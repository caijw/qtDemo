#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto url = QUrl(QStringLiteral("https://www.youtube.com/"));
    MainWindow w(url);
    w.show();
    return a.exec();
}
