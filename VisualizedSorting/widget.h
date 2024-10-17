#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QApplication *app); // ????????????????????????
    ~Widget();

private:
    Ui::Widget *ui;
    QApplication *App;

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void bubbleslot();
    void quickslot();
};
#endif // WIDGET_H
