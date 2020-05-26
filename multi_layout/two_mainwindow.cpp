#include "two_mainwindow.h"
#include "ui_two_mainwindow.h"

Two_Mainwindow::Two_Mainwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TwoMainWindow)
{
    ui->setupUi(this);
}

Two_Mainwindow::~Two_Mainwindow()
{
    delete ui;
}

void Two_Mainwindow::setLeftWidget(QWidget *widget)
{
    ui->leftLayout->insertWidget(0, widget);
}
void Two_Mainwindow::setRightWidget(QWidget *widget)
{
    ui->rightLayout->insertWidget(0, widget);
}
