#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
struct node
{
	string team;
	char pid;
	int ti;
	string result;
	bool operator< (const node& rhs) const
	{
		return ti<rhs.ti;
	}
};
node a[maxn];
int mn[maxn][26];
int mx[maxn][26];
int pn[maxn][26];
int px[maxn][26];
pair<int,int> mn1[maxn];
pair<int,int> mx1[maxn];
string pm[maxn];
void mian()
{
	int s;
	cin>>s;
	map<string,int> mp;
	int n= 0;
	for(int i=1;i<=s;++i)
	{
		string t,p,r;
		int tim;
		cin>>t>>p>>tim>>r;
		a[i]=(node){t,p[0]-'A',tim,r};
		if(mp.count(t)==0)
		{
			mp[t]=++n;
			pm[n]=t;
		}
	}
	sort(a+1,a+s+1);
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<26;++j)
		{
			mn[i][j]=mx[i][j]=1000;
			px[i][j]=pn[i][j]=0;
		}
		mn1[i]=mx1[i]=make_pair(0,0);
	}
	map<pair<int,int>,bool> shit;
	for(int i=1;i<=s;++i)
	{
		int tid=mp[a[i].team];
		if(a[i].result[0]=='A')
		{
			mn[tid][a[i].pid]=min(mn[tid][a[i].pid],a[i].ti);
			mx[tid][a[i].pid]=min(mx[tid][a[i].pid],a[i].ti);
		}
		else if(a[i].result[0]=='U')
		{
			if(mn[tid][a[i].pid]==1000) pn[tid][a[i].pid]+=20;
			mx[tid][a[i].pid]=min(mx[tid][a[i].pid],a[i].ti);
		}
		else
		{
			if(mn[tid][a[i].pid]==1000) pn[tid][a[i].pid]+=20;
			if(mx[tid][a[i].pid]==1000) px[tid][a[i].pid]+=20;
		}
	}
	set<pair<pair<int,int>,int> > st;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<26;++j)
		{
			if(mn[i][j]<=300)
			{
				mn1[i].first--;
				mn1[i].second+=mn[i][j]+pn[i][j];
			}
			if(mx[i][j]<=300)
			{
				mx1[i].first--;
				mx1[i].second+=mx[i][j]+px[i][j];
			}
		}
		st.emplace(mn1[i],i);
	}
	
	vector<string> ans;
	
	for(int i=1;i<=n;++i)
	{
		st.erase(make_pair(mn1[i],i));
		st.emplace(mx1[i],i);
		if((st.begin())->first == mx1[i])
		{
			ans.push_back(pm[i]);
		}
		st.erase(make_pair(mx1[i],i));
		st.emplace(mn1[i],i);
	}
	
	sort(ans.begin(),ans.end());
	
	for(auto& i:ans) cout<<i<<" ";
	cout<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		mian();
	}
}

/*
1
4
Alpha A 100 Accepted
Beta B 101 Accepted
Gamma C 240 Unknown
Alpha A 1 U

*/
