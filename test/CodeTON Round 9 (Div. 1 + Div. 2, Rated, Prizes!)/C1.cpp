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
		for(int y=1;y<=min(x*2,m);y++){
			int z=x^y;
			if(x==y)continue;
			if(x%z==0||y%z==0){
				cnt++;
				// cout<<"!"<<y<<endl;
			}
		}
		printf("%lld\n",cnt);
	}	
	return 0;
}
