#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<qlineedit.h>
#include<qdebug.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&QMainWindow::close);
    QString ss = ui->lineEdit->text();
    qDebug()<< ss;
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

