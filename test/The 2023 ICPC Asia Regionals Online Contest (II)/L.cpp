#include <bits/stdc++.h>
using namespace std;
#define int long long
const int k=131;
const int mod=(1ll<<31)-1;
const int maxn=1e6+5;
int pre[maxn];
int l[maxn];
void mian()
{
	string s;
	cin>>s;
	int n=s.size();
	s=" "+s;
	for(int i=1;i<=n;++i)
	{
		pre[i]=(s[i]*l[i]+pre[i-1])%mod;
	}
	int ans=0;
	for(int j=1;j<=n;++j)
	{
		int mn=0;
		for(int i=j;i>=1;--i)
		{
			if(j*2+1-i>n)
			{
				break;
			}
			int pre1=pre[j-mn]-pre[i-1];
			int pre2=pre[j*2+1-i]-pre[j+mn];
			if((pre1*l[j+mn+1]-pre2*l[i])%mod==0)
			{
				//cout<<"shit "<<i<<" "<<j<<endl;
				ans++;
				mn=j-i+1;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	l[0]=1;
	for(int i=1;i<maxn;++i)
	{
		l[i]=l[i-1]*k%mod;
	}
	int t;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		mian();
	}
	return 0;
}
