#include<bits/stdc++.h>
#define ll long long
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
using namespace std;
const int N=1e6+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m;
ll a[N];
struct Tree{ll Sum,Max,tag,pos1,pos2;};
struct Segment_Tree{
    Tree t[N<<2];
    void update(int p,int l,int r,ll x){
        // cout<<"update: "<<p<<" "<<l<<" "<<r<<" "<<x<<endl;
        t[p].pos1=l;t[p].pos2=r;
        t[p].Sum=1ll*(r-l+1)*x;
        t[p].Max=x;
        t[p].tag=x;
    }
    void Pushup(int p){
        t[p].Sum=t[p<<1].Sum+t[p<<1|1].Sum;
        t[p].Max=max(t[p<<1].Max,t[p<<1|1].Max);
        t[p].pos1=((t[p].Max==t[p<<1].Max)?t[p<<1].pos1:t[p<<1|1].pos1);
        t[p].pos2=((t[p].Max==t[p<<1|1].Max)?t[p<<1|1].pos2:t[p<<1].pos2);
    }
    void Pushdown(int p,int l,int r,int mid){
        if(t[p].tag){
            update(lson,t[p].tag);
            update(rson,t[p].tag);
            t[p].tag=0;
        }
    }
    void Build(int p,int l,int r){
        memset(&t[p],0,sizeof(t[p]));
        if(l==r){update(p,l,r,a[l]);return;}
        int mid=(l+r)>>1;
        Build(lson);Build(rson);
        Pushup(p);
    }
    void Update(int x,int y,ll z,int p,int l,int r){
        if(y<l||x>r)return;
        if(x<=l&&r<=y){update(p,l,r,z);return;}
        int mid=(l+r)>>1;Pushdown(p,l,r,mid);
        Update(x,y,z,lson);Update(x,y,z,rson);
        Pushup(p);
    }
    ll QueryMax(int x,int y,int p,int l,int r){
        if(y<l||x>r)return 0;
        if(x<=l&&r<=y)return t[p].Max;
        int mid=(l+r)>>1;Pushdown(p,l,r,mid);
        return max(QueryMax(x,y,lson),QueryMax(x,y,rson));
    }
    ll QuerySum(int x,int y,int p,int l,int r){
        if(y<l||x>r)return 0;
        if(x<=l&&r<=y)return t[p].Sum;
        int mid=(l+r)>>1;Pushdown(p,l,r,mid);
        return QuerySum(x,y,lson)+QuerySum(x,y,rson);
    }
    int GetMaxPos1(int x,int y,ll Max,int p,int l,int r){
        if(y<l||x>r)return n+1;
        if(x<=l&&r<=y)return t[p].Max==Max?t[p].pos1:n+1;
        int mid=(l+r)>>1;Pushdown(p,l,r,mid);
        return min(GetMaxPos1(x,y,Max,lson),GetMaxPos1(x,y,Max,rson));
    }
    int GetMaxPos2(int x,int y,ll Max,int p,int l,int r){
        if(y<l||x>r)return 0;
        if(x<=l&&r<=y)return t[p].Max==Max?t[p].pos2:0;
        int mid=(l+r)>>1;Pushdown(p,l,r,mid);
        return max(GetMaxPos2(x,y,Max,lson),GetMaxPos2(x,y,Max,rson));
    }
    int LowerBound1(int x,ll z,int p,int l,int r){
        if(x>=r||t[p].Max<z)return 0;
        if(l==r)return t[p].Max>=z?l:0;
        int mid=(l+r)>>1;Pushdown(p,l,r,mid);
        int pos=0;
        if(mid>x)pos=LowerBound1(x,z,lson);
        if(pos)return pos;
        return LowerBound1(x,z,rson);
    }
    int LowerBound2(int x,ll z,int p,int l,int r){
        if(x<=l||t[p].Max<z)return 0;
        if(l==r)return t[p].Max>=z?l:0;
        int mid=(l+r)>>1;Pushdown(p,l,r,mid);
        int pos=0;
        if(mid+1<x)pos=LowerBound2(x,z,rson);
        if(pos)return pos;
        return LowerBound2(x,z,lson);
    }
}t1,t2;
ll GetAnswer(){
    return t1.QuerySum(1,n,1,1,n)-t2.QuerySum(1,n,1,1,n);
}
int main(){
    int T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++)a[i]=read();
        t1.Build(1,1,n);
        t2.Build(1,1,n);
        for(int i=1;i<=n;i++){
            ll lmax=t2.QueryMax(1,i,1,1,n);
            ll rmax=t2.QueryMax(i,n,1,1,n);
            t1.Update(i,i,min(lmax,rmax),1,1,n);
        }
        m=read();
        while(m--){
            int x=read();
            a[x]+=read();
            t2.Update(x,x,a[x],1,1,n);
            ll lmax=t2.QueryMax(1,x-1,1,1,n);
            ll rmax=t2.QueryMax(x+1,n,1,1,n);
            ll Hight=t1.QueryMax(x,x,1,1,n);
            if(Hight>a[x]){
                printf("%lld\n",GetAnswer());
                continue;
            }
            t1.Update(x,x,a[x],1,1,n);
            if(a[x]>=lmax&&x!=1){
                int pos=t2.GetMaxPos2(1,x-1,lmax,1,1,n);
                t1.Update(pos,x-1,lmax,1,1,n);
            }
            else if(x!=1){
                int pos=t2.LowerBound2(x,a[x],1,1,n);
                t1.Update(pos+1,x,a[x],1,1,n);
            }
            if(a[x]>=rmax&&x!=n){
                int pos=t2.GetMaxPos1(x+1,n,rmax,1,1,n);
                t1.Update(x+1,pos,rmax,1,1,n);
            }
            else if(x!=n){
                int pos=t2.LowerBound1(x,a[x],1,1,n);
                t1.Update(x,pos-1,a[x],1,1,n);
            }
            printf("%lld\n",GetAnswer());
        }
    }
    return 0;
}