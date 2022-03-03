#include "student.h"
#include<QDebug>
student::student(QObject *parent) :
    QObject(parent)
{
}
void student::treat()
{
    qDebug()<<"qigke";
}
void student::treat(QString foodname)
{
    qDebug()<<"eat"<<foodname.toUtf8().data();
}
