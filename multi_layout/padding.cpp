#include "padding.h"
#include "ui_padding.h"

Padding::Padding(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Padding)
{
    ui->setupUi(this);
}

Padding::~Padding()
{
    delete ui;
}

