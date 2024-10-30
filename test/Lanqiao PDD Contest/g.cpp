/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,a[N],b[N],sum[N],lst[N],nxt[N],f0[N],f1[N],g0[N],g1[N];
int Solve0(){
	int ans=0;
	for(int i=1,j=0;i<=n;i++){
		if(a[i]){j=i;continue;}
		while(j+1<=n&&a[j+1]==0)j++;
		ans=max(ans,g0[j]-f0[i]+1);
		ans=max(ans,g1[j]-f1[i]+1);
	}
	return ans;
}
int Solve1(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			int l=lst[i]+1,r=nxt[i]-1;
			if(g0[r]>=i&&f0[l]<=i)ans=max(ans,g0[r]-f0[l]+1);
			if(g1[r]>=i&&f1[l]<=i)ans=max(ans,g1[r]-f1[l]+1);
		}
	}
	return ans;
}
int Solve2(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			int j=nxt[i];
			if(j==n+1)continue;
			int l=lst[i]+1,r=nxt[j]-1;
			if(g0[r]>=j&&f1[l]<=i)ans=max(ans,g0[r]-f1[l]+1);
			if(g1[r]>=j&&f0[l]<=i)ans=max(ans,g1[r]-f0[l]+1);
		}
	}
	return ans;
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]^b[i];
	for(int i=1;i<=n;i++)lst[i]=(a[i-1]==1?i-1:lst[i-1]);
	nxt[n+1]=n+1;
	for(int i=n;i>=1;i--)nxt[i]=(a[i+1]==1?i+1:nxt[i+1]);
	g0[0]=g1[0]=-inf;
	for(int i=1;i<=n;i++){
		g0[i]=(sum[i]==0?i:g0[i-1]);
		g1[i]=(sum[i]==1?i:g1[i-1]);
	}
	f0[n+1]=f1[n+1]=inf;
	for(int i=n;i>=1;i--){
		f0[i]=(sum[i-1]==0?i:f0[i+1]);
		f1[i]=(sum[i-1]==1?i:f1[i+1]);
	}
	printf("%d\n",max(max(Solve1(),Solve2()),Solve0()));
	return 0;
}
