#include<iostream>
#include<cstring>
using namespace std;
class Student{
private:
    char *name;
    float g1;
    float g2;
public:
    Student(char *,float,float);
    Student(const Student &);
    ~Student();
    float GetG1(){return g1;}
    float GetG2(){return g2;}
    Student* GetAddr(){return this;}
};
Student::Student(char *s,float a1,float a2):g1(a1),g2(a2){
    name=new char[strlen(s)+1];
    strcpy(name,s);
    cout<<"construct "<<name<<endl;
}
Student::Student(const Student &s){
    name=new char[strlen(s.name)+2];
    strcpy(name,s.name);
    name[strlen(s.name)]='u';
    name[strlen(s.name)+1]='\0';
    g1=s.g1-10.0;
    g2=s.g2-10.0;
    cout<<"copy "<<name<<endl;
}
Student::~Student(){
    cout<<"destruct "<<name<<endl;
    if(name!=NULL)delete []name;
}
int main(){
    Student a((char*)"li",90.0,80.0);
    Student *st=new Student[2]{Student((char*)"zhang",80.0,70.0),Student((char*)"wang",90.0,80.0)};
    for(int i=0;i<2;i++){
        if(i)cout<<' ';
        cout<<(st[i].GetG1()+st[i].GetG2())/2;
    }
    cout<<endl;
    delete [] st;
    Student b=a;
    Student *p1=&b;
    Student *p2=b.GetAddr();
    cout<<(p1-p2)<<endl;
    return 0;
}