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
int n,m,Mod,a[N];
int mod(int x){return x>=Mod?x-Mod:x;}
struct Tree{int num,tag1,tag2,sum;};
struct Segment_Tree{
    Tree t[N<<2];
    void update(int p,int x){
        t[p].sum=(t[p].sum+1ll*t[p].num*x)%Mod;
        t[p].tag1=mod(t[p].tag1+x);
    }
    void Mul(int p,int x){
        t[p].sum=1ll*t[p].sum*x%Mod;
        t[p].tag1=1ll*t[p].tag1*x%Mod;
        t[p].tag2=1ll*t[p].tag2*x%Mod;
    }
    void Pushdown(int p){
        if(t[p].tag2!=1){
            Mul(p<<1,t[p].tag2);
            Mul(p<<1|1,t[p].tag2);
            t[p].tag2=1;
        }
        if(t[p].tag1){
            update(p<<1,t[p].tag1);
            update(p<<1|1,t[p].tag1);
            t[p].tag1=0;
        }
    }
    void Build(int p,int l,int r){
        t[p].num=r-l+1;t[p].tag2=1;
        if(l==r){t[p].sum=a[l];return;}
        int mid=(l+r)>>1;
        Build(lson);Build(rson);
        t[p].sum=mod(t[p<<1].sum+t[p<<1|1].sum);
    }
    void Multy(int x,int y,int z,int p,int l,int r){
        if(y<l||x>r)return;
        if(x<=l&&r<=y){Mul(p,z);return;}
        int mid=(l+r)>>1;Pushdown(p);
        Multy(x,y,z,lson);Multy(x,y,z,rson);
        t[p].sum=mod(t[p<<1].sum+t[p<<1|1].sum);
    }
    void Add(int x,int y,int z,int p,int l,int r){
        if(y<l||x>r)return;
        if(x<=l&&r<=y){update(p,z);return;}
        int mid=(l+r)>>1;Pushdown(p);
        Add(x,y,z,lson);Add(x,y,z,rson);
        t[p].sum=mod(t[p<<1].sum+t[p<<1|1].sum);
    }
    int Query(int x,int y,int p,int l,int r){
        if(y<l||x>r)return 0;
        if(x<=l&&r<=y)return t[p].sum;
        int mid=(l+r)>>1;Pushdown(p);
        return mod(Query(x,y,lson)+Query(x,y,rson));
    }
}tree;
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();m=read();Mod=read();
    for(int i=1;i<=n;i++)a[i]=read()%Mod;
    tree.Build(1,1,n);
    for(int i=1;i<=m;i++){
        int op=read(),x=read(),y=read();
        if(op==1)tree.Multy(x,y,read(),1,1,n);
        if(op==2)tree.Add(x,y,read(),1,1,n);
        if(op==3)printf("%d\n",tree.Query(x,y,1,1,n));
    }
	return 0;
}
