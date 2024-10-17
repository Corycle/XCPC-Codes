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
ll Ans;
int n,W,H,cnt,b[N];
struct Point{int x,y,v;}P[N];
bool cmp(Point A,Point B){return A.x<B.x;}
struct Tree{ll tag,Max;};
struct Segment_Tree{
	Tree t[N<<2];
	void update(int p,int x){t[p].tag+=x;t[p].Max+=x;}
	void Pushdown(int p){if(t[p].tag){update(p<<1,t[p].tag);update(p<<1|1,t[p].tag);t[p].tag=0;}}
	void Build(int p,int l,int r){
		t[p]=(Tree){0,0};if(l==r)return;
		int mid=(l+r)>>1;Build(lson);Build(rson);
	}
	void Add(int x,int y,int z,int p,int l,int r){
		if(y<l||x>r)return;
		if(x<=l&&r<=y){update(p,z);return;}
		int mid=(l+r)>>1;Pushdown(p);
		Add(x,y,z,lson);Add(x,y,z,rson);
		t[p].Max=max(t[p<<1].Max,t[p<<1|1].Max);
	}
}tree;
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int Case=read();
	while(Case--){
		n=read();W=read();H=read();cnt=Ans=0;
		for(int i=1;i<=n;i++){
			P[i].x=read();P[i].y=read();P[i].v=read();
			b[++cnt]=P[i].y-H+1;b[++cnt]=P[i].y;
		}
		sort(b+1,b+cnt+1);
		sort(P+1,P+n+1,cmp);
		cnt=unique(b+1,b+cnt+1)-b-1;
		tree.Build(1,1,cnt);
		for(int i=1,j=1;i<=n;){
			while(j<=n&&P[j].x<=P[i].x+W-1){
				int l=lower_bound(b+1,b+cnt+1,P[j].y-H+1)-b;
				int r=lower_bound(b+1,b+cnt+1,P[j].y)-b;
				tree.Add(l,r,P[j].v,1,1,cnt);
				j++;
			}
			Ans=max(Ans,tree.t[1].Max);
			if(j==n+1)break;
			int tmp=i;
			while(i<=n&&P[i].x==P[tmp].x){
				int l=lower_bound(b+1,b+cnt+1,P[i].y-H+1)-b;
				int r=lower_bound(b+1,b+cnt+1,P[i].y)-b;
				tree.Add(l,r,-P[i].v,1,1,cnt);
				i++;
			}
		}
		printf("%lld\n",Ans);
	}
	return 0;
}
