#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,popcnt,fma")
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=998244353;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,f[N];
int Pow(int x,int y){
	int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%Mod;
		x=1ll*x*x%Mod;
		y>>=1;
	}
	return ans;
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
	}
	f[0]=0;
	for(int i=1;i<=999;i++){
		cout<<"? "<<1<<" "<<n<<" "<<i<<endl;
		cin>>f[i];
	}
	cout<<"!"<<endl;
	int k;
	cin>>k;
	int ans=0;
	for(int i=0;i<=999;i++){
		int p1=1,p2=1;
		for(int j=0;j<=999;j++){
			if(i==j)continue;
			p1=1ll*p1*(k-j+Mod)%Mod;
			p2=1ll*p2*(i-j+Mod)%Mod;
		}
		ans=(ans+1ll*p1*Pow(p2,Mod-2)%Mod*f[i])%Mod;
	}
	cout<<ans<<endl;
	return 0;
}
