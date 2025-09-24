#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5+5;
const int K = 131;
const int mod = (1ll<<61)-1;
vector<int> vt[maxn];
void addedge(int u,int v)
{
	vt[u].push_back(v);
	vt[v].push_back(u);
}
int h[maxn];
int pr[maxn];
void mian()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i) h[i]=0,vt[i].clear();
	for(int i=1;i<=m;++i)
	{
		int a,b;
		cin>>a>>b;
		addedge(a,b);
		h[a] = (h[a] + pr[b])%mod;
		h[b] = (h[b] + pr[a])%mod;
	}
	map<int,vector<int> > mp;
	int toth=0;
	vector<int> rem;
	for(int i=1;i<=n;++i)
	{
		if(!vt[i].empty()) mp[h[i]].push_back(i), toth=(toth+pr[i])%mod;
		else rem.push_back(i);
	}
	int ned = 0;
	for(auto& i:mp)
	{
		if(i.second.size()>1) ned=1;
		int tmp = 0;
		for(auto j:i.second)
		{
			tmp = (tmp+pr[j])%mod;
		}
		if((tmp+i.first)%mod!=toth)
		{
			cout<<"NO\n";
			return;
		}
	}
	if(mp.size()<=2)
	{
		if(!ned)
		{
			int B = mp.begin()->second[0];
			int E = mp.rbegin()->second[0];
			int lst = B;
			cout<<"YES\n";
			for(int i=1;i<=n;++i)
			{
				if(i!=B&&i!=E) cout<<lst<<" "<<i<<"\n", lst = i;
			}
			cout<<lst<<" "<<E<<"\n";
		}
		else
		{
			if(rem.size()<=1){
				cout<<"NO\n";
				return;
			}
			int BB = rem.back();
			rem.pop_back();
			int EE = rem.back();
			rem.pop_back();
			int lst = BB;
			cout<<"YES\n";
			for(auto i:rem)
			{
				if(i!=BB&&i!=EE) cout<<lst<<" "<<i<<"\n",lst = i;
			}
			cout<<lst<<" "<<EE<<"\n";
			for(auto i:mp.begin()->second) cout<<i<<" "<<BB<<"\n";
			for(auto i:mp.rbegin()->second) cout<<i<<" "<<EE<<"\n";
		}
		return;
	}
	
	if(!ned&&rem.size()==1)
	{
		cout<<"YES\n";
		
		int rt = rem[0];
		
		for(auto& i:mp)
		{
			cout<<i.second[0]<<" "<<rt<<"\n";
		}
		return;
	}
	
	if(rem.size() <= mp.size())
	{
		cout<<"NO\n";
		return;
	}
	
	cout<<"YES\n";
	
	int rt = rem.back();
	rem.pop_back();
	
	for(auto i: rem)
	{
		cout<<rt<<" "<<i<<"\n";
	}
	
	vector<int> shit;
	
	for(int i=1;i<=mp.size();++i)
	{
		shit.push_back(rem.back());
		rem.pop_back();
	}
	
	int ii = 0;
	
	for(auto& i:mp)
	{
		for(auto&j:i.second)
		{
			cout<<j<<" "<<shit[ii]<<"\n";
		}
		++ii;
	}
	
}

signed main()
{
	//for(int i=2;i*i<=mod;++i) if(mod%i==0) cout<<i<<"\n";
	pr[0]=1;
	for(int i=1;i<maxn;++i)
	{
		pr[i]=pr[i-1]*(__int128)K%mod;
	}
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		mian();
	}
}
