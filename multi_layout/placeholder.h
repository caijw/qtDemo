#ifndef PLACEHOLDER_H
#define PLACEHOLDER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Placeholder; }
QT_END_NAMESPACE

class Placeholder : public QWidget
{
    Q_OBJECT
public:
    Placeholder(QWidget *parent = nullptr);
    ~Placeholder();
private:
    Ui::Placeholder *ui;
};

#endif // PLACEHOLDER_H
