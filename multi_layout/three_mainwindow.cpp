#include "three_mainwindow.h"
#include "ui_three_mainwindow.h"

Three_Mainwindow::Three_Mainwindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::ThreeMainWindow)
{
    ui->setupUi(this);
}

Three_Mainwindow::~Three_Mainwindow()
{
    delete ui;
}

void Three_Mainwindow::setLeftWidget(QWidget *widget)
{
    ui->leftLayout->insertWidget(0, widget);
}
void Three_Mainwindow::setMiddleWidget(QWidget *widget)
{
    ui->middleLayout->insertWidget(0, widget);
}
void Three_Mainwindow::setRightWidget(QWidget *widget)
{
    ui->rightLayout->insertWidget(0, widget);
}
