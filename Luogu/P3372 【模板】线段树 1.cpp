/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,a[N];
struct Tree{ll tag,sum;};
struct Segment_Tree{
	Tree t[N<<2];
	void update(ll k,int p,int l,int r){t[p].tag+=k;t[p].sum+=k*(r-l+1);}
	void Pushdown(int p,int l,int r){
		int mid=(l+r)>>1;
		if(t[p].tag){update(t[p].tag,lson);update(t[p].tag,rson);t[p].tag=0;}
	}
	void Build(int p,int l,int r){
		if(l==r){t[p].sum=a[l];return;}
		int mid=(l+r)>>1;
		Build(lson);Build(rson);
		t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
	}
	void Add(int x,int y,int z,int p,int l,int r){
		if(y<l||x>r)return;
		if(x<=l&&r<=y){update(z,p,l,r);return;}
		int mid=(l+r)>>1;Pushdown(p,l,r);
		Add(x,y,z,lson);Add(x,y,z,rson);
		t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
	}
	ll Ask(int x,int y,int p,int l,int r){
		if(y<l||x>r)return 0;
		if(x<=l&&r<=y)return t[p].sum;
		int mid=(l+r)>>1;Pushdown(p,l,r);
		return Ask(x,y,lson)+Ask(x,y,rson);
	}
}tree;
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	tree.Build(1,1,n);
	while(m--){
		int op=read(),x=read(),y=read();
		if(op==1)tree.Add(x,y,read(),1,1,n);
		else printf("%lld\n",tree.Ask(x,y,1,1,n));
	}
	return 0;
}
