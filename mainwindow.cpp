#include "mainwindow.h"

#include "graphicsedge.h"
#include "graphicsvertex.h"

#include <QDebug>

#include <QGraphicsView>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
        mScene = new QGraphicsScene(0, 0, 1000, 1000);
        mView = new QGraphicsView(mScene, this);
        mView->setRenderHint(QPainter::Antialiasing);
        mView->setRenderHint(QPainter::TextAntialiasing);

        mEngine.generateInput(6, 4, 0.5);
        mEngine.generateOutput();
        for(int i = 0; i < mEngine.mInputGraph.mVertices.size(); ++i)
        {
                mScene->addItem(new GraphicsVertex(vertexPos(i), QString::number(i)));
        }
        foreach(Edge edge, mEngine.mInputGraph.mEdges)
        {
                mScene->addItem(new GraphicsEdge(QLineF(vertexPos(edge.mTail), vertexPos(edge.mHead)), QString::number(edge.mHead)));
        }

        qDebug().noquote()<<mEngine.mInputGraph;
        qDebug().noquote()<<mEngine.mOutputGraph;

        setCentralWidget(mView);
}

MainWindow::~MainWindow()
{

}

QPointF MainWindow::vertexPos(int id)
{
        QTransform transform;
        transform.translate(500.0, 500.0);
        transform.rotate(-360.0 * id / 6.0);
        return transform.map(QPointF(-495.0, 0.0));
}
