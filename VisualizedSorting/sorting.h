#ifndef SORTING_H
#define SORTING_H

#include <QWidget>
#include <QLabel>
#include <QTimerEvent>


struct node
{
   QWidget *parent;
   int val;
   QVector<int> *elements;
   QVector<QPair<int,int> > *swaping;
};


namespace Ui {
class Sorting;
}

class Sorting : public QWidget
{
    Q_OBJECT

public:
    explicit Sorting(node *tmp); // modified as well
    ~Sorting();

protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);

private:
    Ui::Sorting *ui;
    QVector<int> elements;
    QVector<QPair<int,int> > swaping;
    int val;
    int cnt;
};

#endif // SORTING_H
