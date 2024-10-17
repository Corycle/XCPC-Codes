#include<iostream>
using namespace std;
class Base{
private:
    int x;
public:
    Base(int a):x(a){}
    void show(){
        cout<<"x="<<x<<endl;
    }
};
class derived:public Base{
private:
    int y;
public:
    derived(int a,int b):Base(a),y(b){}
    void show(){
        Base::show();
        cout<<"y="<<y<<endl;
    }
};
void func1(Base A){
    A.show();
}
void func2(derived A){
    A.show();
}
int main(){
    derived a(10,20);
    a.show();
    Base *pBase=&a;
    derived *pDerived=&a;
    pBase->show();
    pDerived->show();
    func1(a);
    func2(a);
    return 0;
}