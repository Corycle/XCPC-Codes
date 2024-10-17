#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
ll read(){
	ll s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
int main(){
	int T=read();
	while(T--){
		ll n=read();
		for(ll i=n/2;i>=1;i--){
			if(gcd(n,i)==1){printf("%lld\n",i);break;}
		}
	}
	return 0;
}
