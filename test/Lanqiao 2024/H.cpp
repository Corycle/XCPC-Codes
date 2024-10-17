#include<bits/stdc++.h>
#define ll long long
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
using namespace std;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,a[N],b[N],ans[N],vis[N];
struct Tree{
	int id,val;
	friend bool operator<(Tree A,Tree B){
		return A.val!=B.val?A.val<B.val:A.id>B.id;
	}
};
struct Segment_Tree{
	Tree t[N<<2];
	void Build(int p,int l,int r){
		if(l==r){t[p].id=l;t[p].val=a[l];return;}
		int mid=(l+r)>>1;
		Build(lson);Build(rson);
		t[p]=max(t[p<<1],t[p<<1|1]);
	}
	void Update(int x,int p,int l,int r){
		if(x<l||x>r)return;
		if(l==r){t[p].id=l;t[p].val=a[l];return;}
		int mid=(l+r)>>1;
		Update(x,lson);Update(x,rson);
		t[p]=max(t[p<<1],t[p<<1|1]);
	}
	Tree Query(int x,int y,int p,int l,int r){
		if(y<l||x>r)return (Tree){0,-1};
		if(x<=l&&r<=y)return t[p];
		int mid=(l+r)>>1;
		return max(Query(x,y,lson),Query(x,y,rson));
	}
}tree;
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	tree.Build(1,1,n);
	for(int i=1;i<=n;i++){
		Tree res=tree.Query(i,m+i,1,1,n);
		ans[i]=res.val;
		if(res.val!=-1){
			m-=res.id-i;
			a[res.id]=-1;
			tree.Update(res.id,1,1,n);
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}
