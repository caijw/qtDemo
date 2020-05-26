#include "one_mainwindow.h"
#include "ui_one_mainwindow.h"

One_Mainwindow::One_Mainwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OneMainWindow)
{
    ui->setupUi(this);
}

One_Mainwindow::~One_Mainwindow()
{
    delete ui;
}

void One_Mainwindow::setWidget(QWidget *widget)
{
    ui->layout->insertWidget(0, widget);
}


