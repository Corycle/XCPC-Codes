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
ll Ans[N];
int n,m,num;
int a[N],b[N],c[N],d[N];
struct BIT_Tree{
	int c[N];
	int lowbit(int x){return x&(-x);}
	void Add(int x,int y){for(;x<=n;x+=lowbit(x))c[x]+=y;}
	int Ask(int x){int ans=0;for(;x>=1;x-=lowbit(x))ans+=c[x];return ans;}
}tree;
void Solve(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1;
	Solve(l,mid);Solve(mid+1,r);
	
	int i=l,j=mid+1;
	for(;j<=r;j++){
		while(i<=mid&&c[a[i]]>=c[a[j]])tree.Add(a[i++],1);
		Ans[c[a[j]]]+=i-l-tree.Ask(a[j]);
	}
	for(int k=l;k<i;k++)tree.Add(a[k],-1);
	
	i=l;j=mid+1;
	for(;i<=mid;i++){
		while(j<=r&&c[a[j]]>=c[a[i]])tree.Add(a[j++],1);
		Ans[c[a[i]]]+=tree.Ask(a[i]);
	}
	for(int k=mid+1;k<j;k++)tree.Add(a[k],-1);
	
	int p1=l,p2=mid+1,tmp=l;
	while(p1<=mid&&p2<=r){
		if(c[a[p1]]>=c[a[p2]])d[tmp++]=a[p1++];
		else d[tmp++]=a[p2++];
	}
	while(p1<=mid)d[tmp++]=a[p1++];
	while(p2<=r)d[tmp++]=a[p2++];
	for(int i=l;i<=r;i++)a[i]=d[i];
}
int main(){
//	freopen("P3157_1.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=b[i]=read();
	sort(b+1,b+n+1);num=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+num+1,a[i])-b;
	for(int i=1;i<=m;i++){int x=lower_bound(b+1,b+num+1,read())-b;c[x]=i;}
	int tmp=m;
	for(int i=1;i<=n;i++)if(!c[i])c[i]=++tmp;
	Solve(1,n);
	for(int i=n;i>=1;i--)Ans[i]+=Ans[i+1];
	for(int i=1;i<=m;i++)printf("%lld\n",Ans[i]);
	return 0;
}
