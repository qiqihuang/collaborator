#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
    w.show();
    return a.exec();
}
