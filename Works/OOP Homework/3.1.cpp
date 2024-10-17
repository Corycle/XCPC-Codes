#include<iostream>
using namespace std;
class Student{
private:
    int rScore;
    int fScore;
    static float prop;
public:
    static void setProp(){
        cin>>prop;
    }
    void compScore(){
        float s=rScore*prop+fScore*(1-prop);
        cout<<s;
    }
};
float Student::prop=0;
class Teacher{
private:
    Student *pStu;
public:
    Teacher(int num){
        pStu=new Student[num];
    }
    ~Teacher(){
        delete [] pStu;
    }
    void assign(int x){
        int *p=(int*)(&(pStu[x]));
        cin>>p[0]>>p[1];
        // cin>>pStu[x].rScore>>pStu[x].fScore;
    }
    void show(int x){
        pStu[x].compScore();
    }
};
int main(){
    Student::setProp();
    int n;
    cin>>n;
    Teacher teacher(n);
    for(int i=0;i<n;i++){
        teacher.assign(i);
    }
    for(int i=0;i<n;i++){
        if(i)cout<<' ';
        teacher.show(i);
    }
    cout<<endl;
    return 0;
}