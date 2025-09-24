#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6+5;
int a[maxn];
const int mod = 998244353;
int ksm(int x,int p)
{
	if(p==0) return 1;
	int mid=ksm(x,p/2);
	if(p%2) return mid*mid%mod*x%mod;
	return mid*mid%mod;
}
struct mat
{
	int a[2][2];
	mat()
	{
		a[0][0]=a[1][1]=1;
		a[1][0]=a[0][1]=0;
	}
	mat operator* (const mat &rhs) const
	{
		mat shit;
		shit.a[0][0]=shit.a[1][1]=0;
		for(int i=0;i<2;++i)
		{
			for(int j=0;j<2;++j)
			{
				for(int k=0;k<2;++k)
				{
					shit.a[i][j]+=a[i][k]*rhs.a[k][j];
				}
				shit.a[i][j]%=mod;
			}
		}
		return shit;
	}
};
mat ksm(mat x,int p)
{
	if(p==0) return mat();
	auto mid=ksm(x,p/2);
	if(p%2) return mid*mid*x;
	return mid*mid;
}
void mian()
{
	int n,m;
	cin>>n>>m;
	if(n==1)
	{
		cout<<1<<"\n";
		return;
	}
	if(n==2)
	{
		cout<<0<<"\n";
		return;
	}
	int base = (ksm(2,m)+mod-1)%mod;
	int m2 = ksm(2,m);
	mat shit;
	shit.a[0][0]=-base;
	shit.a[0][1]=0;
	shit.a[1][0]=m2*base%mod*base%mod;
	shit.a[1][1]=base*base%mod;
	shit = ksm(shit,(n-1)/2);
	int A ,B;
	if(n%2) A = 1,B=ksm(base,mod-2);
	else A = 0,B=ksm(base,mod-1);
	int ans = A*shit.a[0][0]+B*shit.a[1][0];
	ans = (ans%mod+mod)%mod;
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		mian();
	}
}
