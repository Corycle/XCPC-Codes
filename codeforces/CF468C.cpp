/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e18;
ll read(){
	ll s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}

int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	ll n=read();
    ll l=n-inf*9%n*9%n;
    printf("%lld %lld\n",l,l+inf-1);
	return 0;
}