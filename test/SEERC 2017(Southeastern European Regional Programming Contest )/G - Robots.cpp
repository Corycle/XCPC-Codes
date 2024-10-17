/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
ll v;
int n,m;
double ans1,ans2;
struct Node{ll a,t;}p[N];
bool cmp(Node A,Node B){return A.a>B.a;}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		p[i].a=read();p[i].t=read();
		ans1+=v*p[i].t+0.5*p[i].a*p[i].t*p[i].t;
		v+=p[i].a*p[i].t;
	}
	sort(p+1,p+n+1,cmp);
	v=0;
	for(int i=1;i<=n;i++){
		ans2+=v*p[i].t+0.5*p[i].a*p[i].t*p[i].t;
		v+=p[i].a*p[i].t;
	}
	printf("%.1lf",ans2-ans1);
	return 0;
}
/*
2
2 1
30 2
*/
