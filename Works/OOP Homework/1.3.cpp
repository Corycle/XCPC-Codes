#include<iostream>
using namespace std;
int main(){
    const char *s1="abc";
    const char *p=s1;
    cout<<p<<endl;

    char *s2=new char[5]{'d','e','f',0,0};
    char * const q=s2;
    cout<<q<<" "<<5<<endl;

    for(int i=0;i<3;i++)q[i]=p[i];
    cin>>q[3];
    cout<<q<<endl;

    delete []s2;
    return 0;
}