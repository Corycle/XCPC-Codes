#include<bits/stdc++.h>
using namespace std;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
string name[10];
int w[10];
int main(){
    for(int i=1;i<=8;++i){
        cin>>name[i];
        cin>>w[i];
    }
    int a = 1;
    for(int i=1;i<=4;++i){
        if(w[i]>w[a]) a=i;
    }
    int b=5;
    for(int i=5;i<=8;++i){
        if(w[i]>w[b]) b=i;
    }
    if(w[a]<w[b]) swap(a,b);
    cout<<name[a]<<" beats "<<name[b]<<endl;
}