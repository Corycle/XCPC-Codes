#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+5;
const int mod = 998244353;
using ll = long long;
int jc[maxn];
int njc[maxn];
int ksm(int x,int p)
{
	if(p==0) return 1;
	int mid=ksm(x,p/2);
	if(p%2) return mid*1ll*mid%mod*x%mod;
	return mid*1ll*mid%mod;
}
inline int C(int n,int m)
{
	return jc[n]*1ll*njc[m]%mod*njc[n-m]%mod;
}
int prev1[3*maxn+1];

int x[100],y[100];
int main(){
	jc[0]=1;
	for(int i=1;i<maxn;++i)
	{
		jc[i]=jc[i-1]*1ll*i%mod;
	}
	njc[maxn-1]=ksm(jc[maxn-1],mod-2);
	for(int i=maxn-2;i>=0;--i)
	{
		njc[i]=njc[i+1]*1ll*(i+1)%mod;
	}
	
	
	//cout<<"test "<<njc[0]<<endl;

	int* prev=prev1+maxn+101;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	
	for(int i=-m;i<=m;++i)
	{
		int dis = abs(i);
		if((m+i)%2==0) prev[i]=C(m,(m+i)/2);
		prev[i]=(prev[i]+prev[i-1])%mod;
	}
	
	
	for(int i=1;i<=n;++i)
	{
		cin>>x[i]>>y[i];
	}
	
	
	int ans1 = 0;
	{
	int* p = x;
	for(int i=1;i<=n;++i)
	{
		for(int j=p[i]-m;j<=p[i]+m;j+=2)
		{
			int dis = abs(p[i]-j);
			int tmpans = C(m,(m+dis)/2);
			for(int l=1;l<=n;++l)
			{
				int orz = 0;
				if(l<i)
				{
					int L = j-p[l];
					int R = j+k-p[l];
					L=min(max(L,-m),m);
					R=min(max(R,-m),m);
					orz+=prev[R]-prev[L-1];
				}
				else if(l>i)
				{
					int L = j-p[l]+1;
					int R = j+k-p[l];
					L=min(max(L,-m),m);
					R=min(max(R,-m),m);
					orz+=prev[R]-prev[L-1];
				}
				else
				{
					continue;
				}
				tmpans = (tmpans * 1ll* orz) % mod;
			}
			ans1 = (ans1+tmpans)%mod;
			//if(ans1) cout<<ans1<<endl;
		}
	}
	}
	
	
	int ans2 = 0;
	{
	int* p = y;
	for(int i=1;i<=n;++i)
	{
		for(int j=p[i]-m;j<=p[i]+m;j+=2)
		{
			int dis = abs(p[i]-j);
			int tmpans = C(m,(m+dis)/2);
			for(int l=1;l<=n;++l)
			{
				int orz = 0;
				if(l<i)
				{
					int L = j-p[l];
					int R = j+k-p[l];
					L=min(max(L,-m),m);
					R=min(max(R,-m),m);
					orz+=prev[R]-prev[L-1];
				}
				else if(l>i)
				{
					int L = j-p[l]+1;
					int R = j+k-p[l];
					L=min(max(L,-m),m);
					R=min(max(R,-m),m);
					orz+=prev[R]-prev[L-1];
				}
				else
				{
					continue;
				}
				tmpans = (tmpans * 1ll* orz) % mod;
			}
			ans2 = (ans2+tmpans)%mod;
			//if(ans1) cout<<ans1<<endl;
		}
	}
	}
	
	cout<<((ans1*1ll*ans2)%mod+mod)%mod<<endl;
	
}

/*
3 2 2
2 2
2 1
1 1
*/

