#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
ll a,b,c;
int main(){
	int T=read();
	while(T--){
		a=read();b=read();c=read();
		ll ans=b*c;
		for(ll i=1;(1ll<<(i-1))<=c;i++){
			ll t=0;
			if(c%(1ll<<i))t=a*i+(c/(1ll<<i)+1)*b;
			else t=a*i+c/(1ll<<i)*b;
			ans=min(ans,t);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
