#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "engine.h"

#include <QMainWindow>

class NewDialog;

class QGraphicsItemGroup;
class QGraphicsView;
class QGraphicsScene;

class MainWindow : public QMainWindow
{
        Q_OBJECT
        public:
                MainWindow(QWidget *parent = 0);
                ~MainWindow();

                QPointF vertexPos(int id, int size);

        public slots:
                void newAction();
                void openAction();
                void saveAction();
                void runAction();
                void showInputAction();
                void showOutputAction();
        private:
                NewDialog * mNewDialog;
                QGraphicsView * mView;
                QGraphicsScene * mScene;
                QGraphicsItemGroup * mInputGroup;
                QGraphicsItemGroup * mOutputGroup;
                Engine mEngine;
        };

#endif // MAINWINDOW_H
