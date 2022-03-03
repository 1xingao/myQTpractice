#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class teacher : public QObject
{
    Q_OBJECT
public:
    explicit teacher(QObject *parent = 0);

signals://自定义信号
    //无返回值，只要声明不需实现
    //可以有参数可以重载
    void hungrt();
    void hungrt(QString foodname);

public slots:

};

#endif // TEACHER_H
