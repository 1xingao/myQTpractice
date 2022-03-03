#include "widget.h"
#include<QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    run();
}

void Widget::run()
{
    QPushButton* btn = new QPushButton;
    btn->setParent(this);
    btn->setText("3,4,5");
    QPushButton* btn2 = new QPushButton("exit",this);
    btn->move(0,20);
    resize(600,400);
    setWindowTitle("1,3,4,56,");
    connect(btn2,&QPushButton::clicked,this,&Widget::close);
    this->teache = new teacher(this);
    this->stu = new student(this);
    //在自定义信号和槽出现重载的时候需要用函数指针指定参数
    //无参
    void(teacher::*teacherfood1)(void)=&teacher::hungrt;
    void(student::*studentfood1)()= &student::treat;
    connect(teache,teacherfood1,stu,studentfood1);
    //有参
    void(teacher::*teacherfood)(QString)=&teacher::hungrt;
    void(student::*studentfood)(QString) = &student::treat;
    connect(teache,teacherfood,stu,studentfood);

    //classover();//触发信号
    QPushButton* btn3 = new QPushButton("下课",this);
    QPushButton* btn4 = new QPushButton("xiake",this);
    resize(600,400);
    btn3->move(0,40);
    btn4->move(0,60);
    //连接信号
    connect(btn3,&QPushButton::clicked,this,&Widget::classover);
    connect(btn4,&QPushButton::clicked,teache,teacherfood1);
    //disconnect()断开信号，参数相同
    //一个信号可以链接多个槽函数，多个槽函数可以链接同一个信号,信号参数可以多于槽，槽可以不接收
    //QT4链接的写法
    //connect(btn3,SIGNAL(clicked()),this,SLOT(close());
}

void Widget::classover()//触发函数
{
    //emit teache->hungrt();
    emit teache->hungrt("123");
}
Widget::~Widget()
{
}

