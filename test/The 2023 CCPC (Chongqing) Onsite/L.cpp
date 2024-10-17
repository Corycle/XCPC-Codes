#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,K,a[N];
ll Ans;
struct Node{
    int i,j,op,a,b,d,v;
}P[N];
ll Check(){
    ll res=0;
    for(int i=1;i<=m;i++){
        if(P[i].op==0&&P[i].a*a[P[i].i]+P[i].b*a[P[i].j]<=P[i].d)res+=P[i].v;
        if(P[i].op==1&&P[i].a*a[P[i].i]+P[i].b*a[P[i].j]>=P[i].d)res+=P[i].v;
    }
    return res;
}
void Solve(int x){
    if(x==n+1){
        Ans=max(Ans,Check());
        return;
    }
    for(int i=0;i<=K;i++){
        a[x]=i;
        Solve(x+1);
    }
}
int main(){                     
    n=read();m=read();K=read();
    for(int i=1;i<=m;i++){
        P[i].i=read();
        P[i].j=read();
        P[i].op=read();
        P[i].a=read();
        P[i].b=read();
        P[i].d=read();
        P[i].v=read();
    }
    Solve(1);
    printf("%lld\n",Ans);
    return 0;
}