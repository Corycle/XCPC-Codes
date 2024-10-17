#include<bits/stdc++.h>
using namespace std;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
long long n,c[100005],x=1500,ans;
int main(){
    n=read();
    for(int i=1;i<=n;++i) c[i]=read();
    for(int i=1;i<=n;++i){
        x+=c[i];
        ++ans;
        if(x>=4000){
            cout<<ans;
            return 0;
        }
    }
    cout<<-1;
    return 0;
    return 0;
}