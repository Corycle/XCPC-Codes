#include<bits/stdc++.h>
using namespace std;
class A{
private:
    int a;
public:
    A(int x=0):a(x){}
    virtual void operator+(int x){
        a+=x;
    }
    virtual void show(){
        cout<<"a="<<a<<endl;
    }
};
class B:public A{
private:
    int b;
public:
    B(int x=0,int y=0):A(x),b(y){}
    void operator+(int x){
        b+=x;
    }
    void show(){
        A::show();
        cout<<"b="<<b<<endl;
    }
};
void add(A &AorB,int x){
    AorB+x;
}
int main(){
    A myA,*p;
    B myB(2,3);
    add(myA,3); p=&myA;p->show();
    add(myB,3); p=&myB;p->show();
    return 0;
}