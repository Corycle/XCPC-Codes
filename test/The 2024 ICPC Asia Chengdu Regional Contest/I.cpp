#include<bits/stdc++.h>
using namespace std;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
const int N = 200005;
int n,a[N];
#define ls (rt<<1)
#define rs (ls|1)
struct Node{
    int l,r,x;
};
struct Tree{
    Node t[N<<2];
    void build(int rt,int l,int r){
        t[rt].l=l;
        t[rt].r=r;
        if(l==r){
            t[rt].x=0;
            return ;
        }
        build(ls,l,(l+r)/2);
        build(rs,(l+r)/2+1,r);
        t[rt].x=0;
    }
    void pushup(int rt){
        t[rt].x=__gcd(t[ls].x,t[rs].x);
    }
    void update(int pos,int k){
        if(k==0) update(1,pos,0);
        else update(1,pos,pos);
    }
    void update(int rt,int pos,int k){
        // cout<<"DEBUG: "<<rt<<" "<<t[rt].l<<" "<<t[rt].r<<" "<<pos<<" "<<k<<endl;
        if(t[rt].l==t[rt].r) {t[rt].x=k;return;}
        int mid = (t[rt].l+t[rt].r)/2;
        if(pos<=mid) update(rt*2,pos,k);
        else update(rt*2+1,pos,k);
        pushup(rt);
    }
    int query(){
        int x = t[1].x;
        // cout<<"X="<<x<<endl;
        int ans = 0;
        if(x==0) return n;
        for(long long i=1;i*i<=x;++i){
            if(x%i==0){
                if(i*i==x) ans+=1;
                else ans+=2; 
            }
        }
        return ans;
    }
}tree;
void work(){
    n=read();int q=read();
    for(int i=1;i<=n;++i) a[i]=read();
    tree.build(1,1,n);
    for(int i=1;i<n;++i) {
        tree.update(i,a[i]-a[i+1]>0);
    }
    printf("%d\n",tree.query());
    while(q--){
        int p=read(),v=read();
        a[p]=v;
        if(p>1) tree.update(p-1,a[p-1]-a[p]>0);
        if(p<n) tree.update(p,a[p]-a[p+1]>0);
        printf("%d\n",tree.query());
    }
    for(int i=1;i<n;++i) tree.update(i,0);
}
int main(){
    int T=read();
    while(T--) work();
}