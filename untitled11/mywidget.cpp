#include "mywidget.h"
#include "ui_mywidget.h"
#include<QSpinBox>
#include<qslider.h>
mywidget::mywidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mywidget)
{
    ui->setupUi(this);
    void(QSpinBox::* box)(int)=&QSpinBox::valueChanged;
    connect(ui->spinBox,box,ui->horizontalSlider,&QSlider::setValue);
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}

mywidget::~mywidget()
{
    delete ui;
}
