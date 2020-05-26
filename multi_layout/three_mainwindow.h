#ifndef THREE_MAINWINDOW_H
#define THREE_MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class ThreeMainWindow; }
QT_END_NAMESPACE

class Three_Mainwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit Three_Mainwindow(QWidget *parent = nullptr);
    ~Three_Mainwindow();
    void setLeftWidget(QWidget *widget);
    void setMiddleWidget(QWidget *widget);
    void setRightWidget(QWidget *widget);
private:
    Ui::ThreeMainWindow *ui;

};

#endif // THREE_MAINWINDOW_H
