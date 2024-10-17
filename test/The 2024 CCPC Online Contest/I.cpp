#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
const int maxn=505;
int a[maxn];
int b[maxn];
vector<pair<int,int> > vt[maxn];
set<int> cnt[maxn];
int dp[maxn][maxn];
signed main()
{
	ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;++i)
	{
		cin>>b[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(b[j]>=a[i])
			{
				vt[b[j]-a[i]].push_back(make_pair(i,j));
			}
		}
	}
	int ans=0;
	
	int lst=0;
	
	
	
	for(int k=501;k>=0;--k)
	{
		if(vt[k].empty()) continue;
		for(auto i:vt[k])
		{
			int a=i.first;
			int b=i.second;
			for(int j=b;j<maxn;++j){
				if(cnt[j].count(a)) break;
				cnt[j].insert(a);
			}
		}
		int tmp=0;
		
		memset(dp,0,sizeof dp);
		
		dp[1][0] = cnt[1].size()%mod;
		dp[1][1] = 1;
		
		for(int i=2;i<=m;++i)
		{
			dp[i][0] = dp[i-1][0]*max((int)cnt[i].size()-(i-1),0ll)%mod;
			for(int j=1;j<=i;++j)
			{
				dp[i][j]=(dp[i-1][j-1]+max((int)cnt[i].size()-  (i-1-j)  ,0ll)*dp[i-1][j])%mod;
			}
		}
		
		for(int j=0;j<m;++j)
		{
			tmp = (tmp+dp[m][j])%mod;
		}
		
		ans=(ans+(tmp-lst)*k)%mod;
		
		//cout<<"k "<<k<<" "<<(tmp-lst)<<endl;
		
		lst = tmp;
		
	}
	cout<<(ans+mod)%mod;
	return 0;
}
