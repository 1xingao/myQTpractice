#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        pos+=10;
        update();
    });
}
void Widget::paintEvent(QPaintEvent *event)
{
//    QPainter painter(this);
//    QPen pen(QColor(0,0,255));
//    pen.setWidth(3);
//    painter.setPen(pen);

//    painter.drawLine(QPoint(0,0),QPoint(100,100));
//    painter.drawEllipse(QPoint(100,100),50,50);
//    QBrush brush(Qt::blue);
//    brush.setStyle(Qt::Dense2Pattern);
//    painter.setBrush(brush);
//    painter.drawRect(QRect(QPoint(100,100),QPoint(200,200)));
//    painter.drawText(QRect(10,200,150,50),QString("yha"));

//    QPainter painter(this);
//    painter.drawEllipse(QPoint(100,100),50,50);
//    painter.setRenderHint(QPainter::Antialiasing);//抗锯齿
//    painter.drawEllipse(QPoint(200,100),50,50);
//    painter.drawRect(QRect(20,20,50,50));
//    painter.translate(100,0);//转移画家位置
//    painter.save();//保存画家位置，设置标点
//    painter.drawRect(QRect(20,20,50,50));
//    painter.translate(100,0);
//    painter.restore();//还原位置到标点
//    painter.drawRect(QRect(20,20,50,50));
    //直接绘制资源图片
    QPainter painter(this);

    if(pos > this->width())pos = 0;

    painter.drawPixmap(pos,100,QPixmap("://asc/meimei.jpg"));

}
Widget::~Widget()
{
    delete ui;
}

