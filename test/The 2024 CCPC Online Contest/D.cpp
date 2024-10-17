#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=110;
const int mod=998244353;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
string s,t;
int f[N][N][N];
int main(){
	ios::sync_with_stdio(0);
	cin>>s>>t;
	int n=s.size();
	int m=t.size();
	for(int i=0;i<m;++i) f[0][i][i]=(t[i]==s[0]);
	for(int k=1;k<n;++k){
		for(int i=0;i<m;++i){
			f[k][i][i]=((t[i]==s[k])+2ll*f[k-1][i][i])%mod;
			//printf("f[%d][%d][%d]=%d\n",k,i,i,f[k][i][i]);
		}
	}
	for(int k=1;k<n;++k)
	{
		for(int l=0;l<m;++l)
			for(int r=l+1;r<m;++r){
				for(int mid=l;mid<=r;++mid){
					if(t[mid]!=s[k]) continue;
					if(l==mid) f[k][l][r]=(f[k][l][r]+f[k-1][mid+1][r])%mod;
					else if(r==mid) f[k][l][r]=(f[k][l][r]+f[k-1][l][mid-1])%mod;
					else f[k][l][r]=(f[k][l][r]+f[k-1][l][mid-1]*1ll*f[k-1][mid+1][r])%mod;
				}
				for(int mid=l-1;mid<=r;++mid){
					if(l-1==mid) f[k][l][r] = (f[k][l][r]+f[k-1][l][r])%mod;
					else if(r==mid) f[k][l][r] =(f[k][l][r]+ f[k-1][l][r])%mod;
					else f[k][l][r]=(f[k][l][r]+f[k-1][l][mid]*1ll*f[k-1][mid+1][r])%mod;
				}
				//printf("f[%d][%d][%d]=%d\n",k,l,r,f[k][l][r]);
			}
	}
//	int ans = 0;
//	for(int i=1,base=1;i<=n;++i){
//		ans += f[n-i][0][m-1] * base;
//		base <<= 1;
//	}
//	cout<<ans<<endl;
	cout<<f[n-1][0][m-1];
	return 0;
}
