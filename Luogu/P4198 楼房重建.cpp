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
int n,m;
struct Tree{double Max;int ans;};
struct Segment_Tree{
	Tree t[N<<2];
	int Ask(double x,int p,int l,int r){
		if(l==r)return t[p].Max>x;
		int mid=(l+r)>>1;
		if(x>=t[p<<1].Max)return Ask(x,rson);
		return t[p].ans-t[p<<1].ans+Ask(x,lson);
	}
	void Change(int x,double y,int p,int l,int r){
		if(x<l||x>r)return;
		if(l==r){t[p]=(Tree){y,1};return;}
		int mid=(l+r)>>1;Change(x,y,lson);Change(x,y,rson);
		/*====Pushup====*/
		t[p].Max=max(t[p<<1].Max,t[p<<1|1].Max);
		t[p].ans=t[p<<1].ans+Ask(t[p<<1].Max,rson);
	}
}tree;
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;i++){
		int x=read();
		tree.Change(x,(double)read()/x,1,1,n);
		printf("%d\n",tree.t[1].ans);
	}
	return 0;
}
