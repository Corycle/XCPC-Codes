/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=5e5+5;
ll read(){
	ll s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,K;
void Solve(ll l,ll r,ll &ans,ll &num){
    if(r-l+1<K)return;
    int m=(l+r)/2;
    if((r-l+1)&1){
        ll tans=0,tnum=0;
        Solve(1,m-l,tans,tnum);
        ans=tans*2+tnum*(l-1+m)+m;
        num=tnum*2+1;
    }
    else{
        ll tans=0,tnum=0;
        Solve(1,m-l+1,tans,tnum);
        ans=tans*2+tnum*(l-1+m);
        num=tnum*2;
    }
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        n=read();K=read();
        ll ans=0,num=0;
        Solve(1,n,ans,num);
        printf("%lld\n",ans);
    }
	return 0;
}
