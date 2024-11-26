/*====Corycle====*/
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

int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
	while(T--){
		ll x=read(),m=read(),cnt=0;
		for(int y=1;y<=min(x,m);y++){
			int z=x^y;
			if(z==0||z%x==0||z%y==0){
				cnt++;
				// cout<<"!"<<y<<endl;
			}
		}
		if(m>x){
			/*
				(kx)^x<=m
			*/
			ll k=m/x-2;
            cnt+=max(k-1,0ll);
            for(ll i=max(k+1,2ll);i<=k+3;i++){
                if(((i*x)^x)<=m)cnt++;
            }
		}
		printf("%lld\n",cnt);
	}	
	return 0;
}
