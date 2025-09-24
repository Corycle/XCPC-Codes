#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
vector<pair<int,int> > vt[maxn];
pair<int,int> tel[maxn];
long long dis[maxn];
long long dis2[maxn];
int n,m;
void dij1()
{
	priority_queue<pair<long long,int > > q;
	q.emplace(0ll,1);
	dis[1]=0;
	while(!q.empty())
	{
		auto u = q.top();
		q.pop(); 
		for(auto v:vt[u.second])
		{
			if(dis[v.first]>-u.first+v.second)
			{
				dis[v.first]=-u.first+v.second;
				q.emplace(-dis[v.first],v.first);
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		dis2[i]=dis[i];
	}
}
void dij()
{
	priority_queue<pair<long long,int > > q;
	for(int i=1;i<=m;++i)
	{
		int u = tel[i].first;
		int v = tel[i].second;
		dis2[u]=min(dis2[u],dis[v]);
		dis2[v]=min(dis2[v],dis[u]);
	}
	for(int i=1;i<=n;++i)
	{
		q.emplace(-dis2[i],i);
	}
	while(!q.empty())
	{
		auto u = q.top();
		q.pop();
		for(auto v:vt[u.second])
		{
			if(dis2[v.first]>-u.first+v.second)
			{
				dis2[v.first]=-u.first+v.second;
				q.emplace(-dis2[v.first],v.first);
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		dis[i]=dis2[i];
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=0;i<maxn;++i)
	{
		dis[i]=LLONG_MAX/3;
	}
	n=read();
	m=read();
	for(int i=1;i<n;++i)
	{
		int u,v,w;
		u=read();
		v=read();
		w=read();
		vt[u].emplace_back(v,w);
		vt[v].emplace_back(u,w);
	}
	for(int i=1;i<=m;++i)
	{
		tel[i].first = read();
		tel[i].second= read();
	}
	dij1();
	long long ans = 0;
	for(int i=1;i<=n;++i)
	{
		ans = ans + dis[i];
	}
	cout<<ans<<"\n";
	for(int k=1;k<=n;++k)
	{
		dij();
		ans =0;
		for(int i=1;i<=n;++i)
	{
		ans = ans + dis[i];
	}
	cout<<ans<<"\n";
	}
}

