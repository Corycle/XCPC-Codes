/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const double eps=1e-7;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m;
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
	while(T--){
		n=read();m=read();
		double ans=((m%(n-1)?m/(n-1)+1:m/(n-1))-1.0*m/(n-1))*(n-2);
		if(ans<eps)puts("CSFNB!");
		else printf("%.6lf\n",ans);
	}
	return 0;
}
