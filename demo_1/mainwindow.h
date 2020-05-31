#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWebEngineView>
#include <QMainWindow>
#include <QWebEnginePage>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QUrl url, QWidget *parent = nullptr);
    ~MainWindow();
    void setUrl(QUrl url);

public slots:
    void hideWebEngineView();
    void showWebEngineView();


private:
    Ui::MainWindow *ui;
    QWebEngineView *webEngineView;
};
#endif // MAINWINDOW_H
