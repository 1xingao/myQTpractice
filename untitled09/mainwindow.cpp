#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDialog>
#include <QMessageBox> //系统提供标准对话框
#include <qdebug.h>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionnew, &QAction::triggered, [=]()
            {

        // QDialog dig(this);
        // dig.resize(222,111);
        // dig.exec();
        if(QMessageBox::Save ==QMessageBox::question(this,
            "ques","neir",QMessageBox::Save|QMessageBox::Close) ) 
        {
            qDebug() << "save";
        }     //参数五默认关联回车
        else{
            qDebug() <<"close";
        } });
    //使用show创建非模态的对话框，不会堵塞主程序
    connect(ui->actionyes, &QAction::triggered, [=]() { //匿名函数
        QDialog *yes = new QDialog(this);
        yes->resize(222, 111);
        yes->show();
    });
    connect(ui->actionopen, &QAction::triggered, [=](){
        QString filename =  QFileDialog::getOpenFileName(this,"打开文件","D:\\","(*.txt)");
        qDebug() << filename; });
}

MainWindow::~MainWindow()
{
    delete ui;
}
