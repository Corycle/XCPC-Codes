#include<iostream>
#include<cstring>
using namespace std;
class Base{
private:
    char *name;
    int age;
public:
    Base(char *Name,int Age):age(Age){
        cout<<"Base constructor"<<endl;
        int len=strlen(Name);
        name=new char[len+1];
        strcpy(name,Name);
        name[len]='\0';
    }
    ~Base(){
        cout<<"Base destructor"<<endl;
        delete [] name;
    }
    void show(int flag=1){
        if(flag)cout<<name<<" "<<age;
    }
};
class Leader:virtual public Base{
private:
    char job[10];
public:
    Leader(char *Name,char *Job,int Age):Base(Name,Age){
        cout<<"Leader constructor"<<endl;
        strcpy(job,Job);
    }
    ~Leader(){
        cout<<"Leader destructor"<<endl;
    }
    void show(int flag=1){
        Base::show(flag);
        cout<<" "<<job;
    }
};
class Engineer:virtual public Base{
private:
    char major[10];
public:
    Engineer(char *Name,char *Major,int Age):Base(Name,Age){
        cout<<"Engineer constructor"<<endl;
        strcpy(major,Major);
    }
    ~Engineer(){
        cout<<"Engineer destructor"<<endl;
    }
    void show(int flag=1){
        Base::show(flag);
        cout<<" "<<major;
    }
};
class Chairman:public Leader,public Engineer{
public:
    Chairman(char *Name,char *Job,char *Major,int Age):Base(Name,Age),Leader(Name,Job,Age),Engineer(Name,Major,Age){
        cout<<"Chairman constructor"<<endl;
    };
    ~Chairman(){
        cout<<"Chairman destructor"<<endl;
    }
    void show(int flag=1){
        Leader::show(flag);
        Engineer::show(0);
        cout<<endl;
    }
};
int main(){
    Chairman a((char*)"Li",(char*)"chair",(char*)"computer",20);
    a.show();
    return 0;
}