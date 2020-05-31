#include "mainwindow.h"
#include <QApplication>
#include "thread.h"
#include <memory>


int main(int argc, char *argv[])
{
    auto thred = std::unique_ptr<Thread>(new Thread());
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
