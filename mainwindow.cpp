#include "mainwindow.h"

#include "graphicsedge.h"
#include "graphicsvertex.h"
#include "newdialog.h"

#include <QDebug>
#include <QElapsedTimer>
#include <QGraphicsItemGroup>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMenu>
#include <QMenuBar>
#include <QResizeEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      mInputGroup(0),
      mOutputGroup(0)
{
        mNewDialog = new NewDialog(this);
        mScene = new QGraphicsScene(0, 0, 1000, 1000);
        mView = new QGraphicsView(mScene, this);
        mView->setRenderHint(QPainter::Antialiasing);
        mView->setRenderHint(QPainter::TextAntialiasing);

        QAction * newAction = new QAction("New...");
        QAction * openAction = new QAction("Open...");
        QAction * saveAction = new QAction("Save...");
        QMenu * fileMenu = menuBar()->addMenu(tr("File"));
        fileMenu->addAction(newAction);
        //fileMenu->addAction(openAction);
        //fileMenu->addAction(saveAction);

        QAction * runAction = new QAction("Run");
        QAction * showInputAction = new QAction("Show input");
        QAction * showOutputAction = new QAction("Show output");
        QMenu * buildMenu = menuBar()->addMenu(tr("Build"));
        buildMenu->addAction(runAction);
        buildMenu->addAction(showInputAction);
        buildMenu->addAction(showOutputAction);

        setCentralWidget(mView);

        connect(newAction, SIGNAL(triggered(bool)), this, SLOT(newAction()));
        connect(runAction, SIGNAL(triggered(bool)), this, SLOT(runAction()));
        connect(showInputAction, SIGNAL(triggered(bool)), this, SLOT(showInputAction()));
        connect(showOutputAction, SIGNAL(triggered(bool)), this, SLOT(showOutputAction()));
}

MainWindow::~MainWindow()
{

}

QPointF MainWindow::vertexPos(int id, int size)
{
        QTransform transform;
        transform.translate(mScene->width() / 2.0, mScene->height() / 2.0);
        transform.rotate(-360.0 * id / size);
        return transform.map(QPointF(qMin(mScene->width() / 2.0, mScene->height() / 2.0) - 20.0, 0.0));
}

void MainWindow::resizeEvent(QResizeEvent *)
{
        mView->fitInView(mScene->sceneRect(), Qt::KeepAspectRatio);
}

void MainWindow::newAction()
{
        if(mNewDialog->exec() == QDialog::Accepted)
        {
                mEngine.generateInput(mNewDialog->vertices(), mNewDialog->jump(), mNewDialog->chance());
        }
        mScene->clear();
        mInputGroup = 0;
        mOutputGroup = 0;
        qDebug().noquote()<<mEngine.mInputGraph;
}

void MainWindow::openAction()
{

}

void MainWindow::saveAction()
{

}

void MainWindow::runAction()
{
        QElapsedTimer timer;
        timer.start();

        mEngine.generateOutput();

        int time = timer.elapsed();

        qDebug().noquote()<<mEngine.mOutputGraph;
        qDebug().noquote()<<"Generated in"<<time<<"ms\n";
}

void MainWindow::showInputAction()
{
        if(mOutputGroup)
        {
                mOutputGroup->setVisible(false);
        }
        if(mInputGroup)
        {
                mInputGroup->setVisible(true);
        }
        else
        {
                mInputGroup = new QGraphicsItemGroup();
                int size = mEngine.mInputGraph.mVertices.size();
                for(int i = 0; i < size; ++i)
                {
                        mInputGroup->addToGroup(new GraphicsVertex(vertexPos(i, size), QString::number(i)));
                }
                foreach(Edge edge, mEngine.mInputGraph.mEdges)
                {
                        mInputGroup->addToGroup(new GraphicsEdge(QLineF(vertexPos(edge.mTail, size), vertexPos(edge.mHead, size))));
                }
                mScene->addItem(mInputGroup);
        }
}

void MainWindow::showOutputAction()
{
        if(mInputGroup)
        {
                mInputGroup->setVisible(false);
        }
        if(mOutputGroup)
        {
                mOutputGroup->setVisible(true);
        }
        else
        {
                mOutputGroup = new QGraphicsItemGroup();
                int size = mEngine.mOutputGraph.mVertices.size();
                for(int i = 0; i < size; ++i)
                {
                        mOutputGroup->addToGroup(new GraphicsVertex(vertexPos(i, size)));
                }
                foreach(Edge edge, mEngine.mOutputGraph.mEdges)
                {
                        if(edge.mFake)
                        {
                                mOutputGroup->addToGroup(new GraphicsEdge(QLineF(vertexPos(edge.mTail, size), vertexPos(edge.mHead, size)), true));
                        }
                        else
                        {
                                mOutputGroup->addToGroup(new GraphicsEdge(QLineF(vertexPos(edge.mTail, size), vertexPos(edge.mHead, size)), QString::number(edge.mHead)));
                        }
                }
                mScene->addItem(mOutputGroup);
        }

}
