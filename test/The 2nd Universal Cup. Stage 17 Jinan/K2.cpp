#include<bits/stdc++.h>
#define ll long long
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
using namespace std;
const int N=5e5+5;
ll read(){
    ll s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
ll K;
int n,a[N],b[N];
struct Tree{
    ll sum1,sum2;
};
struct Segment_Tree{
    Tree t[N<<2];
    void Clear(int n){
        memset(t,0,sizeof(Tree)*n*4);
    }
    void Pushup(int p){
        t[p].sum1=t[p<<1].sum1+t[p<<1|1].sum1;
        t[p].sum2=t[p<<1].sum2+t[p<<1|1].sum2;
    }
    void Update(int x,int y,int f,int p,int l,int r){
        if(x<l||x>r)return;
        if(l==r){t[p].sum1+=f;t[p].sum2+=f*y;return;}
        int mid=(l+r)>>1;
        Update(x,y,f,lson);
        Update(x,y,f,rson);
        Pushup(p);
    }
    ll Query1(int x,int y,int p,int l,int r){
        if(y<l||x>r)return 0;
        if(x<=l&&r<=y)return t[p].sum1;
        int mid=(l+r)>>1;
        return Query1(x,y,lson)+Query1(x,y,rson);
    }
    ll Query2(int x,int y,int p,int l,int r){
        if(y<l||x>r)return 0;
        if(x<=l&&r<=y)return t[p].sum2;
        int mid=(l+r)>>1;
        return Query2(x,y,lson)+Query2(x,y,rson);
    }
    int Find(int k,int p,int l,int r){
        if(l==r)return l;
        int mid=(l+r)>>1;
        if(k<=t[p<<1].sum1)return Find(k,lson);
        return Find(k-t[p<<1].sum1,rson);
    }
}tree;
ll Calc(int len){
    int x=tree.Find((len+1)/2,1,1,n);
    ll sum=(b[x]*tree.Query1(1,x,1,1,n)-tree.Query2(1,x,1,1,n))+(tree.Query2(x+1,n,1,1,n)-b[x]*tree.Query1(x+1,n,1,1,n));
    return sum;
}
int main(){
    int T=read();
    while(T--){
        n=read();K=read();
        for(int i=1;i<=n;i++)a[i]=b[i]=read()-i;
        sort(b+1,b+n+1);
        b[0]=unique(b+1,b+n+1)-b-1;
        for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+b[0]+1,a[i])-b;
        tree.Clear(n);
        tree.Update(a[1],b[a[1]],1,1,1,n);
        int ans=1;
        for(int l=1,r=1;l<=n;l++){
            while(r<n){
                ++r;
                tree.Update(a[r],b[a[r]],1,1,1,n);
                if(Calc(r-l+1)<=K)ans=max(ans,r-l+1);
                else{
                    tree.Update(a[r],b[a[r]],-1,1,1,n);
                    r--;
                    break;
                }
            }
            tree.Update(a[l],b[a[l]],-1,1,1,n);
        }
        printf("%d\n",ans);
    }
    return 0;
}