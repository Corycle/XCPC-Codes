/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,a[N];
vector<int>p[N];
struct Segment_Tree{
    #define lson p<<1,l,mid
    #define rson p<<1|1,mid+1,r
    struct Tree{
        int tag,max;
    }t[N<<2];
    void add(int p,int x){
        t[p].tag+=x;
        t[p].max+=x;
    }
    void Pushdown(int p){
        if(t[p].tag){
            add(p<<1,t[p].tag);
            add(p<<1|1,t[p].tag);
            t[p].tag=0;
        }
    }
    void Pushup(int p){
        t[p].max=max(t[p<<1].max,t[p<<1|1].max);
    }
    void Build(int p,int l,int r){
        t[p].tag=0;t[p].max=-inf;
        if(l==r)return;
        int mid=(l+r)>>1;
        Build(lson);Build(rson);
    }
    void Add(int x,int y,int z,int p,int l,int r){
        if(y<l||x>r)return;
        if(x<=l&&r<=y){add(p,z);return;}
        int mid=(l+r)>>1;Pushdown(p);
        Add(x,y,z,lson);
        Add(x,y,z,rson);
        Pushup(p);
    }
    void Update(int x,int y,int p,int l,int r){
        if(x<l||x>r)return;
        if(l==r){t[p].max=max(t[p].max,y);return;}
        int mid=(l+r)>>1;Pushdown(p);
        Update(x,y,lson);
        Update(x,y,rson);
        Pushup(p);
    }
    int Max(int x,int y,int p,int l,int r){
        if(y<l||x>r)return -inf;
        if(x<=l&&r<=y)return t[p].max;
        int mid=(l+r)>>1;Pushdown(p);
        return max(Max(x,y,lson),Max(x,y,rson));
    }
}tree;
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        n=read();
        tree.Build(1,1,n);
        for(int i=0;i<=n+1;i++){
            p[i].clear();
        }
        for(int i=1;i<=n;i++){
            a[i]=min(read(),n+1);
            p[a[i]].push_back(i);
        }
        if(p[0].size()==0){
            printf("%d\n",n);
            continue;
        }
        int ans=0,num=n;
        for(int i=0;i<=n+1;i++){
            num-=p[i].size();
            ans=max(ans,max(tree.t[1].max,0)+num);
            if(p[i].size()==0)break;
            if(i==0){
                tree.Update(p[0][0],1,1,1,n);
            }
            else{
                int m=p[i].size();
                int val=tree.Max(p[i][0]+1,n,1,1,n)+1;
                for(int j=0;j<m;j++){
                    tree.Add(1,p[i][j]-1,1,1,1,n);
                    // cout<<"Add: "<<1<<" "<<p[i][j]-1<<" "<<1<<endl;
                }
                tree.Update(p[i][0],val,1,1,n);
            }
        }
        ans=max(ans,tree.t[1].max);
        printf("%d\n",ans);
    }
	return 0;
}
