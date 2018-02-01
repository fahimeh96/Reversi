#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow w;
    w.setFixedSize(700,400);
    w.setWindowIcon(QIcon(":/icons/icon.png"));
    w.show();
    return app.exec();
}
