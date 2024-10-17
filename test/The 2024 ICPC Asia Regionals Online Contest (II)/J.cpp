#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll read(){
    ll s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,id[N];
ll w[N],c[N],v[N];
bool cmp(int x,int y){
    return c[x]*w[y]<c[y]*w[x];
}
int main(){
    n=read();
    for(int i=1;i<=n;i++){
        w[i]=read();v[i]=read();c[i]=read();
        id[i]=i;
    }
    sort(id+1,id+n+1,cmp);
    ll W=0,Ans=0;
    for(int i=1;i<=n;i++){
        Ans+=v[id[i]]-c[id[i]]*W;
        W+=w[id[i]];
    }
    printf("%lld\n",Ans);
    return 0;
}