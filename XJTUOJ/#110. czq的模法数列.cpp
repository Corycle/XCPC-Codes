/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,q,ans,mod;
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();q=read();mod=read();
	q=(q%mod+mod)%mod;
	int x=1;
	for(int i=1;i<=n;i++){
		ans=(ans+x)%mod;
		x=1ll*x*q%mod;
	}
	printf("%d\n",ans);
	return 0;
}
