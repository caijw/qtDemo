#ifndef PADDING_H
#define PADDING_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Padding; }
QT_END_NAMESPACE

class Padding : public QWidget
{
    Q_OBJECT
public:
    Padding(QWidget *parent = nullptr);
    ~Padding();
private:
    Ui::Padding *ui;
};

#endif // PADDING_H
