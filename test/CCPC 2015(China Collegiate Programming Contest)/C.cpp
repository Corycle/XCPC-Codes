/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=1e9+7;
const int N=1005;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,a[N],b[N],f[N];
int mod(int x){return x>=Mod?x-Mod:x;}
struct Tree{
	int c[N],n;
	int lowbit(int x){return x&(-x);}
	void Add(int x,int y){x++;for(;x<=n;x+=lowbit(x))c[x]=mod(c[x]+y);}
	int Ask(int x){x++;int ans=0;for(;x>=1;x-=lowbit(x))ans=mod(ans+c[x]);return ans;}
	void Clear(int t){n=t+1;for(int i=1;i<=n;i++)c[i]=0;}
}t[N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
	for(int Case=1;Case<=T;Case++){
		n=read();m=read();
		for(int i=1;i<=n;i++)a[i]=b[i]=read();
		sort(b+1,b+n+1);b[0]=unique(b+1,b+n+1)-b-1;
		for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+b[0]+1,a[i])-b;
		if(b[0]<m){printf("Case #%d: 0\n",Case);continue;}
		for(int i=0;i<=b[0];i++)t[i].Clear(b[0]);
		t[0].Add(0,1);
		for(int i=1;i<=n;i++){
			for(int k=1;k<=a[i];k++)f[k]=t[k-1].Ask(a[i]-1);
			for(int k=1;k<=a[i];k++)t[k].Add(a[i],f[k]);
		}
		printf("Case #%d: %d\n",Case,t[m].Ask(b[0]));
	}
	return 0;
}
