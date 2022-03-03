#include "mainwindow.h"
#include<Qmenubar.h>
#include<Qtoolbar.h>
#include<qpushbutton.h>
#include<qstatusbar.h>
#include<qlabel.h>
#include<qdockwidget.h>
#include<qtextedit.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(1000,800);
    //创建菜单
    QMenuBar* bur = menuBar();//本身就在对象树上不需要指定父亲
    setMenuBar(bur);
    //创建菜单
    QMenu* filemenu =  bur->addMenu("文件");
    QMenu* editer =  bur->addMenu("编辑");
    QMenu* exit_menu = bur->addMenu("选项");
    //创建菜单项
    //菜单栏最多只能有一个
    QAction* addact =  filemenu->addAction("打开");
    QAction* eddact =  filemenu->addSeparator();//分割线
    filemenu->addAction("新建");
    QAction* exit_retu =  exit_menu->addAction("exit");
    //connect(exit_retu,&QAction::isCheckable,this,QMainWindow::close);
    //工具栏可以有多个
    QToolBar* tool_bar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,tool_bar);
    //使用第三个重载函数指定区域，addtoolbar()第一个参数可以在帮助文档中找到
    //允许停靠
    tool_bar->setAllowedAreas(Qt::LeftToolBarArea| Qt::TopToolBarArea);
    //设置浮动
    tool_bar->setFloatable(true);
    //tool_bar->setMovable(false);//强制锁定
    //工具栏设置内容
    tool_bar->addAction(addact);
    QPushButton* btn = new QPushButton("exit",this);
    tool_bar->addWidget(btn);
    connect(btn,QPushButton::clicked,this,QMainWindow::close);

    //状态栏，只允许一个
    QStatusBar* status_bar =  statusBar();
    setStatusBar(status_bar);
    //放置标签控件
    QLabel* lab = new QLabel("提示信息",this);
    status_bar->addWidget(lab);
    QLabel* lab2 = new QLabel("提示信息2",this);
    status_bar->addPermanentWidget(lab2);//右侧
    //铆接部件，可以有多个
    QDockWidget* dock = new QDockWidget("浮动",this);
    addDockWidget(Qt::RightDockWidgetArea,dock);
    //dock->setAllowedAreas(Qt::TopToolBarArea);
    //设置中心部件,only one
    QTextEdit* text_my = new QTextEdit(this);
    setCentralWidget(text_my);
    //只有一个的添加的时候是set，有多个的时候用的是add
}

MainWindow::~MainWindow()
{
}

