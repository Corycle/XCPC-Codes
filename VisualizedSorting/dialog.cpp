#include "dialog.h"
#include "ui_dialog.h"

#include <algorithm>
#include <random>

Dialog::Dialog(shit *tmp) :
    QWidget(tmp->parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Drawer);
    setWindowModality(Qt::ApplicationModal);

    Parent = tmp->parent;
    flag = tmp->flag;
}

Dialog::~Dialog()
{
    delete ui;
}

void Qsort(QVector<int>& arr, int low, int high, QVector<QPair<int,int> >& res)
{
    if (high <= low) return;
    int i = low;
    int j = high;
    int key = arr[low];
    while (true)
    {
        while (arr[i] <= key)
        {
            i++;
            if (i == high){
                break;
            }
        }
        while (arr[j] >= key)
        {
            j--;
            if (j == low){
                break;
            }
        }
        if (i >= j) break;
        std::swap(arr[i],arr[j]);
        res.push_back({i,j});
    }
    arr[low] = arr[j];
    arr[j] = key;
    res.push_back({j,low});
    Qsort(arr, low, j - 1, res);
    Qsort(arr, j + 1, high, res);
}

void Dialog::generate()
{
    int val=ui->spinBox->value();
    QVector<int> elements;
    QVector<QPair<int,int> > swaping;
    for(int i=1;i<=val;++i) elements.push_back(i);
    std::shuffle(elements.begin(),elements.end(),std::default_random_engine(std::random_device()()));
    auto tmp = elements;
    if(flag==1)
    {
        for (int i=0;i<val;i++)
        {
            for (int j=0;j<val-i-1;j++)
            {
                if (tmp[j]>tmp[j+1])
                {
                    std::swap(tmp[j],tmp[j+1]);
                    swaping.push_back({j,j+1});
                }
            }
        }
    }
    else if(flag==2)
    {
        Qsort(tmp,0,val-1,swaping);
    }
    node Node{Parent,val,&elements,&swaping};
    (new Sorting(&Node))->show();
    close();
}
