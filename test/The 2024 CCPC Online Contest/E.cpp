#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
const int mod=998244353;
int ksm(int x,int p)
{
	if(p==0) return 1;
	if(p==1) return x%mod;
	int mid=ksm(x,p/2);
	if(p%2) return mid*mid%mod*x%mod;
	return mid*mid%mod;
}

int xzc(int n,int m)
{
	int inv26 = ksm(26,mod-2);
	int ans=0;
	for(int i=0;i<=m;++i)
	{
		ans=(ans+ksm(26,i)*(1-ksm((mod+1-ksm(inv26,i))%mod,n))%mod)%mod;
	}
	return (ans+mod)%mod;
}
long long lyk(int n,int m){
	long long ans=1;
	for(int i=1;i<=n;++i){
		if(i<=26) ans+=m;
		else if(i<=26ll*26) ans+=m-1;
		else if(i<=26ll*26*26) ans+=m-2;
		else if(i<=26ll*26*26*26) ans+=m-3;
		else if(i<=26ll*26*26*26*26) ans+=m-4;
		else ans+=m-5;
	}
	return ans;
}


int xzc2(int n,int m)
{
	int ans =0;
	for(int i=0;i<=m;++i)
	{
		int tmp =0;
		if(i<=7) tmp = min(ksm(26,i),n);
		else tmp = n;
		ans=(ans+tmp)%mod;
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	cout<<xzc2(n,m)<<" ";
	cout<<xzc(n,m)<<"\n";
	return 0;
}
