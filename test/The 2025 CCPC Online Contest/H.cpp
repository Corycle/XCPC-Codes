#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,popcnt,fma")

using ll = long long;

int v[55][100000];

int h[55],t_[55];

ll l[55][55],to[55][55];


ll f[55][16][(1<<14)];

ll g[2][55][(1<<14)];


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,k,T;
	cin>>n>>m>>k>>T;
	
	//cout<<"n "<<n<<endl;
	
	m++;
	
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=k;++j)
		{
			cin>>v[i][j];
		}
	}
	
	h[1]=n;
	t_[1]=0;
	
	for(int j=1;j<=n;++j)
	{
		l[1][j]=j-1,to[1][j]=v[j][0];
		//cout<<"shit "<<j<<" "<<to[1][j]<<endl;
	}
	
	for(int i=2;i<=m;++i)
	{
		cin>>h[i]>>t_[i];
		for(int j=1;j<=h[i];++j)
		{
			cin>>l[i][j];
			l[i][j]--;
			int too;
			cin>>too;
			to[i][j] = v[l[i][j]+1][too];
		}
	}
	
	for(int i=0;i<=1;++i)
	for(int t=0;t<=T;++t)
	for(int j=0;j<=n;++j)
	for(int msk=0;msk<(1<<n);++msk)
	f[t][j][msk]=LLONG_MIN/3;
	
	
	for(int i=0;i<=m;++i)
	for(int t=0;t<=T;++t)
	for(int msk=0;msk<(1<<n);++msk)
	g[0][t][msk]=LLONG_MIN/3;
	
	// f[i][t][j][msk]
	// g[i][t][msk]
	
	g[0][0][0]=0;
	
	for(int i=1;i<=m;++i)
	{
		//cout<<"shit "<<i<<endl;

	for(int t=0;t<=T;++t)
	for(int j=0;j<=n;++j)
	for(int msk=0;msk<(1<<n);++msk)
	f[t][j][msk]=LLONG_MIN/3;
		//cout<<"s "<<i<<endl;
		for(int t=t_[i];t<=T;++t)
		{
			for(int msk=0;msk<(1<<n);++msk)
				f[t][0][msk] = g[0][t-t_[i]][msk];
			
			for(int j=1;j<=h[i];++j)
			{
				for(int msk=0;msk<(1<<n);++msk)
				{
					f[t][j][msk]=max(f[t][j-1][msk], f[t][j][msk]);
					if(msk&(1<<l[i][j])) f[t][j][msk]=max(f[t][j][msk],f[t][j-1][msk^(1<<l[i][j])]+to[i][j]);
				}
			}
			
			for(int msk=0;msk<(1<<n);++msk)
			{
				g[0][t][msk] = max(g[0][t][msk],f[t][h[i]][msk]);
				//cout<<"msk "<<i<<" "<<t<<" "<<msk<<" "<<g[i][t][msk]<<endl;
			}
		}
	}
	
	ll totans = 0;
	
	for(int t=0;t<=T;++t)
	{
		for(int i=1;i<=m;++i)
		{
			for(int msk=0;msk<(1<<n);++msk)
			{
				totans=max(totans,g[0][t][msk]);
			}
		}
		
		if(t>0) cout<<totans<<"\n";
	}
	
	
	
	

}
