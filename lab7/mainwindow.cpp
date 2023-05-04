#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);
    QPen pen;
    pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine);

    QBrush brush;
    brush.setColor(Qt:: green);
    brush.setStyle(Qt::SolidPattern);


    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(this->xysqr.x(), this->xysqr.y(),this->size, this->size );
    painter.end();
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint point_click = event->pos();
    qDebug() << point_click;

   if (
           ((point_click.x() >= xysqr.x()) && (point_click.x() <= xysqr.x() + this->size))
          &&
           ((point_click.y() >= xysqr.y()) && (point_click.y() <= xysqr.y() + this->size))
       )
   {

       this->popal = true;
 mclick = point_click - xysqr;
   }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(this->popal == true)
    {

        xysqr = event->pos() - mclick;
        repaint();

    }

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
     this->popal =false;
}


