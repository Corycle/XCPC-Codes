/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e6+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
ll Ans;
vector<int>F[N];
int n,m,p,a[N],b[N],sum[N],num[N],pos[N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();m=read();p=read();
	for(int i=1;i<=m;i++)F[i].push_back(0);
	for(int i=1;i<=n;i++){
		a[i]=read()+1;b[i]=read();
		sum[i]=sum[i-1]+(b[i]<=p);
		while(pos[a[i]]+1<=num[a[i]]&&sum[F[a[i]][pos[a[i]]+1]-1]<sum[i])pos[a[i]]++;
		Ans+=pos[a[i]];
		F[a[i]].push_back(i);
		num[a[i]]++;
	}
	printf("%lld\n",Ans);
	return 0;
}
