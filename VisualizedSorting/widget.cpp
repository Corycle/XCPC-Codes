#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QApplication *app)
    : QWidget(nullptr)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Drawer);

    App=app;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::bubbleslot()
{
    shit tmp{this,1};
    (new Dialog(&tmp))->show();
}

void Widget::quickslot()
{
    shit tmp{this,2};
    (new Dialog(&tmp))->show();
}

void Widget::closeEvent(QCloseEvent *event)
{
    App->quit();
}
