#ifndef ONE_MAINWINDOW_H
#define ONE_MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class OneMainWindow; }
QT_END_NAMESPACE



class One_Mainwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit One_Mainwindow(QWidget *parent = nullptr);
    ~One_Mainwindow();
    void setWidget(QWidget *widget);

private:
    Ui::OneMainWindow *ui;
};

#endif // ONE_MAINWINDOW_H
