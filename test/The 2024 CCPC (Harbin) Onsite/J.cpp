#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int x=0,f=1;char c=getchar();
    while((c<'0'||c>'9')&&c!='-') c=getchar();
    if(c=='-') f=-1,c=getchar();
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return f*x;
}
int n,m,X,S,curpos;
int a[100005],lst[100005],pos[100005];
struct St{
    int pos,t;
}b[100005];
bool cmppos(St a,St b){
    if(a.pos==b.pos) a.t<b.t;
    return a.pos<b.pos;
}
void work(){
    n=read();m=read();X=0;curpos=0;S=0;
    for(int i=1;i<=n;++i) a[i]=read(),S+=a[i];
    for(int i=1;i<=m;++i){
        b[i].pos=read();
        b[i].t=read();
    }
    sort(b+1,b+m+1,cmppos);
    for(int i=1;i<=n;++i) pos[i]=0;
    for(int i=1;i<=m;++i){
        lst[i]=pos[b[i].t];
        pos[b[i].t]=b[i].pos;
    }
    for(int i=1;i<=m;++i){
        if(S-X+curpos<b[i].pos) break;
        X+=b[i].pos-curpos;
        auto tt = min(a[b[i].t],b[i].pos-lst[i]);
        if(X>=tt) X-=tt;
        else X=0;
        curpos=b[i].pos;
    }
    printf("%lld\n",S-X+curpos);
}
signed main(){
    int T=read();
    while(T--) work();
}