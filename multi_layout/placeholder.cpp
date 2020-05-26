#include "placeholder.h"
#include "ui_placeholder.h"

Placeholder::Placeholder(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Placeholder)
{
    ui->setupUi(this);
}

Placeholder::~Placeholder()
{
    delete ui;
}

