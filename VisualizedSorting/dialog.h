#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include <QDebug>

#include "sorting.h"

struct shit
{
    QWidget *parent;
    int flag;
};

namespace Ui {
class Dialog;
}

class Dialog : public QWidget
{
    Q_OBJECT

public:
    explicit Dialog(shit *tmp);
    ~Dialog();

private:
    Ui::Dialog *ui;

    QWidget *Parent;

    int flag;

private slots:
    void generate();
};

#endif // DIALOG_H
