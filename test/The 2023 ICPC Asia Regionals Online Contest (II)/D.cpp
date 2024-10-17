#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,a[1000][1000];
void work(){
	n=read();
	int ans1=0,ans2=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			a[i][j]=read();
			if(a[i][j]<0) ans1+=a[i][j],ans2+=a[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		int minn=10000000;
		for(int j=1;j<=n;++j) minn=min(minn,a[i][j]);
		if(minn<0) continue;
		else ans1+=minn;
	}
	for(int i=1;i<=n;++i){
		int minn=10000000;
		for(int j=1;j<=n;++j) minn=min(minn,a[j][i]);
		if(minn<0) continue;
		else ans2+=minn;
	}
	printf("%lld\n",min(ans1,ans2));
}
signed main(){
	int T=read();
	while(T--) work();
	return 0;
}
