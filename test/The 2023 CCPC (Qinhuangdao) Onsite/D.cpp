#include<bits/stdc++.h>
#define ll long long
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define pii pair<ll,ll>
#define mp make_pair
#define fst first
#define scd second
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e5+5;
const ll Inf=1e18;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m;
ll a[N];
pii b[N];
struct Segment_Tree{
    struct Tree{ll Min,pos,tag;}t[N<<2];
    void update(int p,ll z){
        t[p].Min+=z;t[p].tag+=z;
    }
    void Pushup(int p){
        if(t[p<<1].Min<t[p<<1|1].Min){
            t[p].Min=t[p<<1].Min;
            t[p].pos=t[p<<1].pos;
        }
        else{
            t[p].Min=t[p<<1|1].Min;
            t[p].pos=t[p<<1|1].pos;
        }
    }
    void Pushdown(int p){
        if(t[p].tag){
            update(p<<1,t[p].tag);
            update(p<<1|1,t[p].tag);
            t[p].tag=0;
        }
    }
    void Build(int p,int l,int r){
        t[p]=(Tree){0,0,0};
        if(l==r){t[p].Min=a[l];t[p].pos=l;return;}
        int mid=(l+r)>>1;
        Build(lson);Build(rson);Pushup(p);
    }
    void Update(int x,int y,ll z,int p,int l,int r){
        if(y<l||x>r)return;
        if(x<=l&&r<=y){update(p,z);return;}
        int mid=(l+r)>>1;Pushdown(p);
        Update(x,y,z,lson);Update(x,y,z,rson);Pushup(p);
    }
}tree;
int main(){
    int T=read();
    while(T--){
        n=read();m=read();
        for(int i=1;i<=n;i++)a[i]=read();
        tree.Build(1,1,n);
        for(int i=1;i<=m;i++){
            b[i].fst=read();
            b[i].scd=read();
            tree.Update(1,b[i].fst,-b[i].scd,1,1,n);
        }
        sort(b+1,b+m+1);
        int num=m;
        ll Ans=0;
        for(int i=1;i<=n;i++){
            int pos=tree.t[1].pos;
            Ans+=tree.t[1].Min;
            while(num&&b[num].fst>=pos){
                tree.Update(1,b[num].fst,b[num].scd,1,1,n);
                num--;
            }
            tree.Update(pos,pos,Inf,1,1,n);
            printf("%lld ",Ans);
        }
        puts("");
    }
    return 0;
}