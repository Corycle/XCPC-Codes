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
int n,a[N],b[N];
struct Node{int pos,a;}P[N];
bool cmp(Node A,Node B){return A.a!=B.a?A.a>B.a:A.pos>B.pos;}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)P[i]=(Node){i,a[i]};
	sort(P+1,P+n+1,cmp);
	for(int i=1;i<=n;i++)b[P[i].pos]=i;
	for(int i=1;i<=n;i++)printf("%d ",b[i]);
	return 0;
}
/*
5
3 2 2 2 1
*/
