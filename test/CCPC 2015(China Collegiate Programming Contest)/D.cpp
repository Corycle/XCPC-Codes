/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1005;
const int M=4005;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
ll f[2][M][3];
int n,m,a[N],b[N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
	for(int Case=1;Case<=T;Case++){
		n=read();m=read()*2;
		for(int i=1;i<=n;i++){a[i]=read()*2;b[i]=read();}
		int t=0;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			t^=1;
			for(int j=0;j<=m;j++)for(int k=0;k<=2;k++)f[t][j][k]=f[t^1][j][k];
			for(int j=m;j>=a[i];j--)for(int k=0;k<=2;k++)f[t][j][k]=max(f[t][j][k],f[t^1][j-a[i]][k]+b[i]);
			for(int j=m;j>=a[i]/2;j--)for(int k=1;k<=2;k++)f[t][j][k]=max(f[t][j][k],f[t^1][j-a[i]/2][k-1]+b[i]);
		}
		ll ans=0;
		for(int i=1;i<=n;i++)ans=max(ans,(ll)b[i]);
		for(int i=0;i<2;i++)for(int j=0;j<=m;j++)ans=max(ans,max(f[i][j][0],max(f[i][j][1],f[i][j][2])));
		printf("Case #%d: %lld\n",Case,ans);
	}
	return 0;
}
