/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
#define lson t[p].l,l,mid
#define rson t[p].r,mid+1,r
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,cnt,Root[N];
struct Tree{int l,r;ll sum;};
struct Segment_Tree{
    int tot;
    Tree t[N*40];
    void Pushup(int p){t[p].sum=t[t[p].l].sum+t[t[p].r].sum;}
    int Merge(int x,int y){
        if(!x||!y)return x|y;
        t[x].sum+=t[y].sum;
        t[x].l=Merge(t[x].l,t[y].l);
        t[x].r=Merge(t[x].r,t[y].r);
        return x;
    }
    void Update(int x,int y,int &p,int l,int r){
        if(!p)p=++tot;
        if(l==r){t[p].sum+=y;return;}
        int mid=(l+r)>>1;
        if(x<=mid)Update(x,y,lson);
        else Update(x,y,rson);
        Pushup(p);
    }
    void Split(int x,int y,int fp,int &p,int l,int r){
        if(!p)p=++tot;
        if(y<l||x>r)return;
        if(x<=l&&r<=y){t[p]=t[fp];t[fp]={0,0,0};return;}
        int mid=(l+r)>>1;
        Split(x,y,t[fp].l,lson);
        Split(x,y,t[fp].r,rson);
        Pushup(fp);Pushup(p);
    }
    ll Query(int x,int y,int p,int l,int r){
        if(y<l||x>r||!p)return 0;
        if(x<=l&&r<=y)return t[p].sum;
        int mid=(l+r)>>1;
        return Query(x,y,lson)+Query(x,y,rson);
    }
    int Kth(int k,int p,int l,int r){
        if(k>t[p].sum)return -1;
        if(l==r)return l;
        int mid=(l+r)>>1;
        if(k<=t[t[p].l].sum)return Kth(k,lson);
        return Kth(k-t[t[p].l].sum,rson);
    }
}tree;
int main(){
//  freopen("P5494_4.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();m=read();cnt=1;
    for(int i=1;i<=n;i++){
        int x=read();
        if(x)tree.Update(i,x,Root[1],1,n);
    }
    while(m--){
        int op=read(),p=read(),x=read();
        if(op==0)tree.Split(x,read(),Root[p],Root[++cnt],1,n);
        if(op==1)Root[p]=tree.Merge(Root[p],Root[x]);
        if(op==2)tree.Update(read(),x,Root[p],1,n);
        if(op==3)printf("%lld\n",tree.Query(x,read(),Root[p],1,n));
        if(op==4)printf("%d\n",tree.Kth(x,Root[p],1,n));
    }
	return 0;
}
