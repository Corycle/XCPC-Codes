#include<iostream>
using namespace std;
void Sort(int &a,int &b,int &c){
    if(a>b)a^=b^=a^=b;
    if(a>c)a^=c^=a^=c;
    if(b>c)b^=c^=b^=c;
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    Sort(a,b,c);
    cout<<a<<" "<<b<<" "<<c<<endl;
    return 0;
}