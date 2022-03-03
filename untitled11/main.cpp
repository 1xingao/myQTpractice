#include "widget.h"
#include "mywidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
//    mywidget x;
//    x.show();
    return a.exec();
}
