#include "mylavel.h"
#include<qdebug.h>
#include<QMouseEvent>
mylavel::mylavel(QWidget *parent) : QLabel(parent)
{
    setMouseTracking(true);
}
void mylavel:: enterEvent(QEvent* event)
{
    qDebug()<<"鼠标进入";
}
void mylavel:: leaveEvent(QEvent *)
{
    qDebug()<<"鼠标离开";
}
void  mylavel:: mouseMoveEvent(QMouseEvent *ev)
{
    qDebug()<< ev->x() <<"-"<< ev->y();
}

