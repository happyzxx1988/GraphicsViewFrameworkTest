﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void adjustViewSize();

private:
    Ui::MainWindow *ui;

    QGraphicsView * view;

    QGraphicsScene *scene;
    void initScene();
    void initSceneBackground();

};

#endif // MAINWINDOW_H
