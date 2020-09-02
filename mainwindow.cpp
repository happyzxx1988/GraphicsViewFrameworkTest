#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include "constants.h"
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    view = ui->graphicsView;
    scene  = new QGraphicsScene(this);
    this->image = new QImage();
//    view->setScene(scene);

//    this->initScene();
//    this->initSceneBackground();
//    QTimer::singleShot(0, this, SLOT(adjustViewSize()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initScene()
{
    scene->setSceneRect(-100, -100, 200, 200);
}

void MainWindow::initSceneBackground()
{
    QPixmap bg(TILE_SIZE, TILE_SIZE);
    QPainter p(&bg);
    p.setBrush(QBrush(Qt::gray));
    p.drawRect(0, 0, TILE_SIZE, TILE_SIZE);
    view->setBackgroundBrush(QBrush(bg));


    scene->addPixmap(QPixmap::fromImage(*image));
    view->setScene(scene);
    view->resize(image->width() + 10, image->height() + 10);
    view->show();


}

void MainWindow::adjustViewSize()
{
    qDebug() << "adjustViewSize";
}
//打开文件图片
void MainWindow::on_action_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(
                this, "open image file",
                ".",
                "Image files (*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)");
    if(fileName != "")
    {
        if(image->load(fileName))
        {
//            QGraphicsScene *scene = new QGraphicsScene;
            scene->addPixmap(QPixmap::fromImage(*image));
            view->setScene(scene);
            view->resize(image->width() + 10, image->height() + 10);
            view->show();
        }
    }
}
