#include "widget.h"
#include "./ui_widget.h"
#include<QPushButton>
#include<QStackedWidget>
#include "mywidget.h"
#include<qcheckbox.h>
#include<qdebug.h>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("test");
    //ui->label->setPixmap(QPixmap("D:/abcin/kangna.jpg"));
    ui->label_2->setPixmap(QPixmap("://asc/1.jpg"));
    ui->label_3->setPixmap(QPixmap("://asc/meimei.jpg"));
    ui->label_4->setPixmap(QPixmap("://asc/xiaogong.jpg"));
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(2);
    });
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(3);
    });
    connect(ui->pushButton_5,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(4);
    });
    
    // bool cha = true;
    // connect(ui->checkBox_6,&QCheckBox::stateChanged,[=](){
    //     ui->checkBox->setDown(cha);
    // });
}

Widget::~Widget()
{
    delete ui;
}

