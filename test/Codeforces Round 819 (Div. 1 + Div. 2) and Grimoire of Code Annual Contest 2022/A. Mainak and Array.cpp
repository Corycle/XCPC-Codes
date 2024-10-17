/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e4+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,a[N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int Case=read();
	while(Case--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		int Ans=a[n]-a[1];
		for(int i=2;i<=n;i++)Ans=max(Ans,a[i]-a[1]);
		for(int i=1;i<n;i++)Ans=max(Ans,a[n]-a[i]);
		for(int i=2;i<=n;i++)Ans=max(Ans,a[i-1]-a[i]);
		printf("%d\n",Ans);
	}
	return 0;
}
