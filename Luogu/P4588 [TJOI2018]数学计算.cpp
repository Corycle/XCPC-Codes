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
int n,Mod,cnt,b[N];
struct Node{int op,x;}P[N];
struct Tree{int val,num;};
int Pow(int x,int y){
	int ans=1;
	while(y){if(y&1)ans=1ll*ans*x%Mod;x=1ll*x*x%Mod;y>>=1;}
	return ans;
}
struct Segment_Tree{
	Tree t[N<<2];
	void Build(int p,int l,int r){
		t[p]=(Tree){1,0};if(l==r)return;
		int mid=(l+r)>>1;Build(lson);Build(rson);
	}
	void Change(int x,int y,int p,int l,int r){
		if(x<l||x>r)return;
		if(l==r){t[p].num+=y;t[p].val=Pow(b[l],t[p].num);return;}
		int mid=(l+r)>>1;Change(x,y,lson);Change(x,y,rson);
		t[p].val=1ll*t[p<<1].val*t[p<<1|1].val%Mod;
	}
}tree;
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int Case=read();
	while(Case--){
		n=read();Mod=read();cnt=0;
		for(int i=1;i<=n;i++){P[i].op=read();P[i].x=read();if(P[i].op==1)b[++cnt]=P[i].x;}
		sort(b+1,b+cnt+1);cnt=unique(b+1,b+cnt+1)-b-1;
//		cout<<" ========="<<endl;
//		for(int i=1;i<=cnt;i++)cout<<b[i]<<" ";cout<<endl;
		for(int i=1;i<=n;i++)if(P[i].op==1)P[i].x=lower_bound(b+1,b+cnt+1,P[i].x)-b;
//		for(int i=1;i<=n;i++)cout<<P[i].op<<" "<<P[i].x<<endl;
		tree.Build(1,1,cnt);
		for(int i=1;i<=n;i++){
			if(P[i].op==1)tree.Change(P[i].x,1,1,1,cnt);
			if(P[i].op==2)tree.Change(P[P[i].x].x,-1,1,1,cnt);
			printf("%d\n",tree.t[1].val);
		}
	}
	return 0;
}
