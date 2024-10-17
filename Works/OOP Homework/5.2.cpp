#include<bits/stdc++.h>
using namespace std;
class A{
private:
    char *name;
public:
    A(){}
    A(const char *s){
        int len=strlen(s);
        name=new char[len+1];
        strcpy(name,s);
        name[len]='\0';
    }
    virtual ~A(){
        if(name!=NULL)delete []name;
        puts("destructor A");
    }
    virtual void show(){
        printf("%s\n",name);
    }
    virtual void print(){}
};
class B:public A{
private:
    int age;
public:
    B(){}
    B(const char *s,int x):A(s),age(x){}
    ~B(){
        puts("destructor B");
    }
    void show(){
        printf("B:");
        A::show();
    }
    void print(){
        printf("%d\n",age);
    }
};
class C:public A{
private:
    char gender;
public:
    C(){}
    C(const char *s,char x):A(s),gender(x){}
    ~C(){
        puts("destructor C");
    }
    void show(){
        printf("C:");
        A::show();
    }
    void print(){
        printf("%c\n",gender);
    }
};
class manage{
public:
    int len;
    A **array;
    manage(int n):len(n){
        array=new A*[len];
        for(int i=0;i<len;i++)array[i]=NULL;
    }
    ~manage(){
        for(int i=0;i<len;i++){
            if(array[i]!=NULL)delete array[i];
        }
        delete [] array;
    }
    void add(int index,const char *s,int age){
        array[index]=new B(s,age);
    }
    void add(int index,const char *s,char gender){
        array[index]=new C(s,gender);
    }
    void display(){
        for (int i=0;i<len;i++) {
            if(array[i]==NULL)continue;
            array[i]->show();
            array[i]->print();
        }
    }
};
#define manager manage
int main(){
    manager m(4);
    m.add(0,"zhang",18);
    m.add(1,"wang",'F');
    m.add(3,"liu",'M');
    m.display();
    return 0;
}