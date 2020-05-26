#ifndef TWO_MAINWINDOW_H
#define TWO_MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class TwoMainWindow; }
QT_END_NAMESPACE

class Two_Mainwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit Two_Mainwindow(QWidget *parent = nullptr);
    ~Two_Mainwindow();
    void setLeftWidget(QWidget *widget);
    void setRightWidget(QWidget *widget);
private:
    Ui::TwoMainWindow *ui;

};

#endif // TWO_MAINWINDOW_H
