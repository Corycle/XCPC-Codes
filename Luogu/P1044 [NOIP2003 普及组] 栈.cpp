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
int n;
ll f[20];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();
	f[0]=f[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<i;j++)f[i]+=f[j]*f[i-j-1];
	}
	printf("%lld\n",f[n]);
	return 0;
}
