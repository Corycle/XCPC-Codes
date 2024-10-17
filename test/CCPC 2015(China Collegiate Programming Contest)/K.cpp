/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=4005;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m;
ll a[2][N],f[2][N],sum1[2][N],sum2[2][N];
ll Sum1(int k,int l,int r){return sum1[k][r]-sum1[k][l-1];}
ll Sum2(int k,int l,int r){return sum2[k][r]-sum2[k][l-1];}
ll L(int k,int l,int r){return Sum2(k,l,r)-(l-1)*Sum1(k,l,r);}
ll R(int k,int l,int r){return (r+1)*Sum1(k,l,r)-Sum2(k,l,r);}
ll Calc(int k,int l,int r){
	if(l==1&&r==n)return 1e18;
	if(r==n)return L(k,l,r);
	if(l==1)return R(k,l,r);
	int mid=(l+r)>>1;
	return L(k,l,mid)+R(k,mid+1,r);
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
	for(int Case=1;Case<=T;Case++){
		n=read();
		for(int i=1;i<=n;i++){a[0][i]=read(),a[1][i]=read();}
		for(int i=1;i<=n;i++){
			for(int k=0;k<2;k++){
				sum1[k][i]=sum1[k][i-1]+a[k][i];
				sum2[k][i]=sum2[k][i-1]+a[k][i]*i;
			}
		}
		memset(f,0x7f,sizeof(f));
		f[0][0]=f[1][0]=0;
		for(int i=1;i<=n;i++){
			for(int k=0;k<2;k++){
				for(int j=1;j<=i;j++){
					f[k][i]=min(f[k][i],f[k^1][j-1]+Calc(k^1,j,i));
				}
			}
		}
		printf("Case #%d: %lld\n",Case,min(f[0][n],f[1][n]));
	}
	return 0;
}
