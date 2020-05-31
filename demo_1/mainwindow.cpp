#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QUrl url, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    webEngineView = new QWebEngineView();
    ui->leftLayout->insertWidget(0, webEngineView);
    setUrl(url);
    connect(ui->hideWebviewBtn, SIGNAL(clicked()), this, SLOT(hideWebEngineView()));
    connect(ui->showWebviewBtn, SIGNAL(clicked()), this, SLOT(showWebEngineView()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUrl(QUrl url) {
    webEngineView->setUrl(url);
    webEngineView->show();
}

void MainWindow::hideWebEngineView() {
    std::cout << "hideWebEngineView" << std::endl;
    webEngineView->hide();
    QWebEnginePage* page = webEngineView->page();

    std::cout << page << std::endl;
}

void MainWindow::showWebEngineView() {
    std::cout << "showWebEngineView" << std::endl;
    webEngineView->show();
}
