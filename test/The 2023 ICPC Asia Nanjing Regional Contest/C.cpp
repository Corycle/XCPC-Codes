#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int calc(int l,int r,int p){
    if(r<l) return 0;
    --l,--r;
    if(l==-1) l=0;
    return (r+2*p)/p-(l+p*2-1)/p;
}
int p,m;
void work(){
    p=read();m=read()+1;
    int ans=0;
    for(int i=1;i<=60;++i){
        if((m&(1ll<<i>>1))==0) continue;
        int l=(((m-(1ll<<i>>1))^(p-1))>>(i-1)<<(i-1));
        int r=l+(1ll<<i>>1)-1;
        ans+=calc(l,r,p);
        // cout<<i<<' '<<l<<' '<<r<<' '<<p<<' '<<calc(l,r,p)<<endl;
    }
    printf("%lld\n",ans);
    return ;
}
signed main(){
    int T=read();
    while(T--) work();
}