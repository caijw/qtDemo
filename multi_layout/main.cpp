//#include "mainwindow.h"
#include "one_mainwindow.h"
#include "two_mainwindow.h"
#include "three_mainwindow.h"

#include "padding.h"
#include "placeholder.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // one window begin
//    One_Mainwindow *window = new One_Mainwindow();
//    Placeholder *placeholder = new Placeholder();
//    window->setWidget(placeholder);
//    window->show();
    // one window end

    // two window begin
    Two_Mainwindow *window = new Two_Mainwindow();
    Placeholder *placeholderLeft = new Placeholder();
    Placeholder *placeholderRight = new Placeholder();
    window->setLeftWidget(placeholderLeft);
    window->setRightWidget(placeholderRight);
    window->show();
    // two window end

    // three window begin
//    Three_Mainwindow *window = new Three_Mainwindow();
//    Placeholder *placeholderLeft = new Placeholder();
//    Placeholder *placeholderMiddle = new Placeholder();
//    Placeholder *placeholderRight = new Placeholder();
//    Padding *padding = new Padding();
//    window->setLeftWidget(padding);
//    window->setMiddleWidget(placeholderMiddle);
//    window->setRightWidget(placeholderRight);
//    window->show();
    // three window end
    return a.exec();
}
