#include "sorting.h"
#include "ui_sorting.h"

#include <QPainter>
#include <QDebug>

Sorting::Sorting(node *tmp) :
    QWidget(tmp->parent),
    ui(new Ui::Sorting)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Drawer);
    setWindowModality(Qt::ApplicationModal);

    val = tmp->val;
    elements = *tmp->elements;
    swaping = *tmp->swaping;
    cnt = 0;

    startTimer(50);
}

Sorting::~Sorting()
{
    delete ui;
}

void Sorting::timerEvent(QTimerEvent *event)
{
    if(cnt>=swaping.size()) return;
    std::swap(elements[swaping[cnt].first],elements[swaping[cnt].second]);
    ++cnt;
    update();
}

void Sorting::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.scale(1.0*width()/val,1.0*height()/val);
    painter.translate(-0.5,0.5);
    for(int i=0;i<val;++i)
    {
        painter.drawLine(i+1,val,i+1,val-elements[i]);
    }
}
