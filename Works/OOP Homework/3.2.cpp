#include<iostream>
using namespace std;
class Node{
public:
    static int x;
    int y;
    char *s;
    Node(){
        y=0;
        s=new char[2];
        s[0]='#';
        s[1]='\0';
    }
    Node(int val,int n){
        y=val;
        s=new char[n];
        for(int i=0;i<n-1;i++)s[i]='a'+i;
        s[n-1]='\0';
    }
    ~Node(){
        if(s!=NULL)delete []s;
    }
    static void Function1(){
        x++;
    }
    void Function2(){
        y++;
    }
};
int Node::x=0;
Node globalObj1(1,2);// 全局对象
Node globalObj2(2,3);
void PrintDataInformation(const Node & p){
    cout<<"    x = "<<p.x<<" , address = "<<&p.x<<" , size = "<<sizeof(p.x)<<endl;
    cout<<"    y = "<<p.y<<" , address = "<<&p.y<<" , size = "<<sizeof(p.y)<<endl;
    cout<<"    s = "<<p.s<<" , address = "<<&p.s<<" , size = "<<sizeof(p.s)<<endl;
}
typedef void (Node::*Function2ptr)();
union {
    Function2ptr f;
    void *addr;
}P2;
void PrintFuncInformation(const Node & p){
    void (*P1)()=&Node::Function1;
    cout<<"    Function1: address = "<<(void*)(P1)<<endl;
    P2.f=&Node::Function2;
    cout<<"    Function2: address = "<<P2.addr<<endl;
}
void func(Node Obj1,Node Obj2){
    Obj1.s=new char[2];
    Obj1.s[0]='#';
    Obj1.s[1]='\0';
    Obj2.s=new char[2];
    Obj2.s[0]='#';
    Obj2.s[1]='\0';
    cout<<"funcObj1:"<<endl;
    PrintDataInformation(Obj1);
    cout<<"funcObj2:"<<endl;
    PrintDataInformation(Obj2);
}
int main(){
    Node localObj1(3,4);// 局部对象
    Node localObj2(4,5);
    Node *dynamicObj1=new Node;// 动态创建对象
    Node *dynamicObj2=new Node;

    cout<<"观察、分析各种对象地址："<<endl;
    cout<<"&globalObj1: "<<&globalObj1<<endl;
    cout<<"&globalObj2: "<<&globalObj2<<endl;
    cout<<"&localObj1:  "<<&localObj1<<endl;
    cout<<"&localObj2:  "<<&localObj2<<endl;
    cout<<"dynamicObj1: "<<dynamicObj1<<endl;
    cout<<"dynamicObj2: "<<dynamicObj2<<endl;
    cout<<endl;

    cout<<"输出对象中各个静态与非静态数据成员的值、地址、对象的存储空间大小等信息："<<endl;
    cout<<"globalObj1:"<<endl;
    PrintDataInformation(globalObj1);
    cout<<"globalObj2:"<<endl;
    PrintDataInformation(globalObj2);
    cout<<"localObj1:"<<endl;
    PrintDataInformation(localObj1);
    cout<<"localObj2:"<<endl;
    PrintDataInformation(localObj2);
    cout<<"dynamicObj1:"<<endl;
    PrintDataInformation(*dynamicObj1);
    cout<<"dynamicObj2:"<<endl;
    PrintDataInformation(*dynamicObj2);
    func(localObj1,localObj2);
    cout<<endl;

    cout<<"输出静态、非静态成员函数地址, 以及main、func等外部函数的地址"<<endl;
    cout<<"globalObj1:"<<endl;
    PrintFuncInformation(globalObj1);
    cout<<"globalObj2:"<<endl;
    PrintFuncInformation(globalObj2);
    cout<<"localObj1:"<<endl;
    PrintFuncInformation(localObj1);
    cout<<"localObj2:"<<endl;
    PrintFuncInformation(localObj2);
    cout<<"dynamicObj1:"<<endl;
    PrintFuncInformation(*dynamicObj1);
    cout<<"dynamicObj2:"<<endl;
    PrintFuncInformation(*dynamicObj2);
    cout<<"main: address = "<<(int*)(&main)<<endl;
    cout<<"func: address = "<<(void*)(&func)<<endl;
    cout<<endl;
    return 0;
}