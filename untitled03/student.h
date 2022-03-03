#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class student : public QObject
{
    Q_OBJECT
public:
    explicit student(QObject *parent = 0);

signals:

public slots://返回值void，需要声明也要实现，有参重载
    void treat();
    void treat(QString foodname);

};

#endif // STUDENT_H
