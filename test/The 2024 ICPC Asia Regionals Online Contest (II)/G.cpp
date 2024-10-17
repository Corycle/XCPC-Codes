#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
const int mod = 998244353;
long long qpow(int a,int b){
    ll res=1,base=a%mod;
    for(int i=1;i<=b;i<<=1){
        if(b&i) res=res*base%mod;
        base=base*base%mod;
    }
    return res%mod;
}
ll inv(int x){return qpow(x,mod-2);}
int p,q;
map<pair<int,int>,int > mem;
long long f(int x,int y){
    // cout<<"computing: "<<x<<" "<<y<<endl;
    if(x==0) return 0;
    if(y==0) return 1;
    if(x==y) return p;
    if(mem.find(make_pair(x,y))!=mem.end()) return mem[make_pair(x,y)];
    if(x<y) return mem[make_pair(x,y)]=qpow(p,y/x)*f(x,y%x)%mod;
    int tmp = qpow(q,x/y);
    return (1-tmp+mod+tmp*f(x%y,y)%mod)%mod;
}
void work(){
    int x,y,a0,a1,b,p0,p1;
    x=read();y=read();
    a0=read();a1=read();b=read();
    p=1ll*a0*inv((a0+a1)%mod)%mod;
    q=1ll*a1*inv((a0+a1)%mod)%mod;
    // p0=1ll*a0*inv(b)%mod;
    // p1=1ll*a1*inv(b)%mod;
    // p=1ll*p0*inv((p0+p1)%mod)%mod;
    // q=1ll*p1*inv((p0+p1)%mod)%mod;
    // cout<<p0<<endl<<p1<<endl;
    // cout<<p<<endl<<q<<endl;
    mem.clear();
    printf("%lld\n",f(x,y));
}
signed main(){
    int T=read();
    while(T--){
        work();
    }
    return 0;
}