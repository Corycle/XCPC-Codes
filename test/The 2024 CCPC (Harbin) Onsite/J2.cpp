#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
const int N=3e5+5;
const ll INF=1e18;
ll read(){
    ll s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
ll b[N];
int n,m,a[N],nxt[N],pos[N];
struct Node{ll x;int t;}P[N];
struct Tree{
    ll sum;
    int tag;
};
struct Segment_Tree{
    Tree t[N<<2];
    void clear(int p){
        t[p].tag=1;
        t[p].sum=0;
    }
    void Pushdown(int p){
        if(t[p].tag){
            clear(p<<1);
            clear(p<<1|1);
            t[p].tag=0;
        }
    }
    void Pushup(int p){
        t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
    }
    void ClearAll(int p,int l,int r){
        t[p].sum=t[p].tag=0;
        if(l==r)return;
        int mid=(l+r)>>1;
        ClearAll(lson);ClearAll(rson);
    }
    void Clear(int x,int y,int p,int l,int r){
        if(y<l||x>r)return;
        if(x<=l&&r<=y){clear(p);return;}
        int mid=(l+r)>>1;Pushdown(p);
        Clear(x,y,lson);Clear(x,y,rson);
        Pushup(p);
    }
    void Add(int x,ll y,int p,int l,int r){
        if(x<l||x>r)return;
        if(l==r){t[p].sum+=y;return;}
        int mid=(l+r)>>1;Pushdown(p);
        Add(x,y,lson);Add(x,y,rson);
        Pushup(p);
    }
    void Update(int x,ll y,int p,int l,int r){
        if(x<l||x>r)return;
        if(l==r){t[p].sum=y;return;}
        int mid=(l+r)>>1;Pushdown(p);
        Update(x,y,lson);Update(x,y,rson);
        Pushup(p);
    }
    ll Query(int x,int y,int p,int l,int r){
        if(y<l||x>r)return 0;
        if(x<=l&&r<=y)return t[p].sum;
        int mid=(l+r)>>1;Pushdown(p);
        return Query(x,y,lson)+Query(x,y,rson);
    }
    int FindPos(ll res,int p,int l,int r){
        if(l==r)return l;
        int mid=(l+r)>>1;Pushdown(p);
        if(t[p<<1].sum>=res)return FindPos(res,lson);
        return FindPos(res-t[p<<1].sum,rson);
    }
}tree;
void Clear(){
    tree.ClearAll(1,1,b[0]);
    b[0]=0;
    for(int i=1;i<=max(n,m);i++){
        a[i]=b[i]=nxt[i]=pos[i]=0;
    }
}
bool cmp(Node A,Node B){return A.x<B.x;}
void Work(){
    n=read();m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=m;i++){
        P[i].x=read();
        P[i].t=read();
        b[++b[0]]=P[i].x;
    }
    for(int i=1;i<=n;i++){
        P[++m]=(Node){INF,i};
    }
    b[++b[0]]=0;
    b[++b[0]]=INF;
    sort(b+1,b+b[0]+1);
    b[0]=unique(b+1,b+b[0]+1)-b-1;
    sort(P+1,P+m+1,cmp);
    for(int i=m;i>=1;i--){
        P[i].x=lower_bound(b+1,b+b[0]+1,P[i].x)-b;
        if(pos[P[i].t])nxt[i]=pos[P[i].t];
        pos[P[i].t]=i;
    }
    // cout<<"!!!!!!!!!!"<<endl;
    // cout<<n<<" "<<m<<endl;
    // for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
    // for(int i=1;i<=b[0];i++)cout<<b[i]<<" ";cout<<endl;
    // for(int i=1;i<=m;i++)cout<<P[i].x<<" "<<P[i].t<<endl;
    // for(int i=1;i<=n;i++)cout<<pos[i]<<" ";cout<<endl;
    // for(int i=1;i<=m;i++)cout<<nxt[i]<<" ";cout<<endl;
    for(int i=1;i<=n;i++){
        tree.Add(P[pos[i]].x,a[i],1,1,b[0]);
        // cout<<"Init: "<<i<<" "<<P[pos[i]].x<<" "<<a[i]<<endl;
    }
    ll ans=0;
    P[0].x=1;
    // cout<<"Solve: "<<endl;
    for(int i=1;i<=m;i++){
        ll res=b[P[i].x]-b[P[i-1].x];
        // cout<<i<<": "<<res<<" "<<tree.t[1].sum<<endl;
        if(tree.t[1].sum<res){
            ans=b[P[i-1].x]+tree.t[1].sum;
            break;
        }
        int pos=tree.FindPos(res,1,1,b[0]);
        ll tmp=tree.Query(1,pos,1,1,b[0]);
        if(pos>1)tree.Clear(1,pos-1,1,1,b[0]);
        tree.Update(pos,tmp-res,1,1,b[0]);
        tree.Update(P[i].x,0,1,1,b[0]);
        tree.Add(P[nxt[i]].x,a[P[i].t],1,1,b[0]);
    }
    printf("%lld\n",ans);
}
int main(){
    int T=read();
    while(T--){
        Work();
        Clear();
    }
    return 0;
}