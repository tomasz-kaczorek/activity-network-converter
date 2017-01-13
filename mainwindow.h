#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "engine.h"

#include <QMainWindow>

class QGraphicsView;
class QGraphicsScene;

class MainWindow : public QMainWindow
{
        Q_OBJECT
        public:
                MainWindow(QWidget *parent = 0);
                ~MainWindow();

                QPointF vertexPos(int id);
        private:
                QGraphicsView * mView;
                QGraphicsScene * mScene;
                Engine mEngine;
        };

#endif // MAINWINDOW_H
