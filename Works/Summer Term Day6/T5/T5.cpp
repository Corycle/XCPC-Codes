/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
char s[N];
int n,m,a[N];
struct Operation{int c[2][2];}P[N];
struct Tree{
	int a[2];
	friend Tree operator+(Tree A,Tree B){
		Tree C;
		C.a[0]=B.a[A.a[0]];
		C.a[1]=B.a[A.a[1]];
		return C;
	}
};
struct Segment_Tree{
	Tree t[N<<2];
	void Init(int p,int l){
		t[p].a[0]=P[l].c[0][a[l]];
		t[p].a[1]=P[l].c[1][a[l]];
	}
	void Build(int p,int l,int r){
		if(l==r){Init(p,l);return;}
		int mid=(l+r)>>1;
		Build(lson);Build(rson);
		t[p]=t[p<<1]+t[p<<1|1];
	}
	void Change(int x,int p,int l,int r){
		if(x<l||x>r)return;
		if(l==r){Init(p,l);return;}
		int mid=(l+r)>>1;
		Change(x,lson);Change(x,rson);
		t[p]=t[p<<1]+t[p<<1|1];
	}
	Tree Query(int x,int y,int p,int l,int r){
		if(x<=l&&r<=y)return t[p];
		int mid=(l+r)>>1;
		if(y<=mid)return Query(x,y,lson);
		if(x>mid)return Query(x,y,rson);
		return Query(x,y,lson)+Query(x,y,rson);
	}
}tree;
int main(){
	// freopen("T5_10.in","r",stdin);
	// freopen("T5_10.out","w",stdout);
	n=read();m=read();
    scanf("%s",s+1);
	for(int i=1;i<=n;i++)a[i]=s[i]-'0';
	for(int i=2;i<=n;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)P[i].c[j][k]=read();
	tree.Build(1,2,n);
	while(m--){
		int op=read();
		if(op==1){
			int l=read(),r=read();
			if(l==r){printf("%d\n",a[l]);continue;}
			printf("%d\n",tree.Query(l+1,r,1,2,n).a[a[l]]);
		}
		else if(op==2){
			int x=read()+1;
			for(int i=0;i<2;i++)for(int j=0;j<2;j++)P[x].c[i][j]=read();
			tree.Change(x,1,2,n);
		}
		else if(op==3){
			int x=read();
			a[x]=read();
			tree.Change(x,1,2,n);
		}
	}
	return 0;
}
