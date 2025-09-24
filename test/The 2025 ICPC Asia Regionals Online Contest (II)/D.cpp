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
	return mid*mid%mod;'
}
void mian()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		ans = (ans + (ksm(3,n-i)+1)*ksm(2,mod-2)%mod*a[i]%mod*ksm(2,i-1))%mod;
	}
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
