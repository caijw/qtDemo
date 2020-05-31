#include "mainwindow.h"
#include <QApplication>
#include "uv_thread.h"
#include <memory>


int main(int argc, char *argv[])
{
    auto thred = std::unique_ptr<UVThread>(new UVThread());
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
