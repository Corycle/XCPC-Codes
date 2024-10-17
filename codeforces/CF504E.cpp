/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=1e9+9;
const int Mul=131;
const int N=3e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
char s[N];
int n,m,cnt,tot;
int h[N],P[N],HL[N],HR[N],fa[N],id[N],pos[N],son[N],sum[N],dep[N],top[N];
struct edge{int to,next;}d[N*2];
void Add(int x,int y){d[++cnt]=(edge){y,h[x]};h[x]=cnt;}
int mod(int x){return x>=Mod?x-Mod:x;}
int LHash(int l,int r){return mod(HL[r]-1ll*P[r-l+1]*HL[l-1]%Mod+Mod);}
int RHash(int l,int r){return mod(HR[l]-1ll*P[r-l+1]*HR[r+1]%Mod+Mod);}
void DFS1(int x,int depth){
    dep[x]=depth;sum[x]=1;
    for(int i=h[x];i;i=d[i].next){
        int y=d[i].to;
        if(y==fa[x])continue;
        fa[y]=x;
        DFS1(y,depth+1);
        sum[x]+=sum[y];
        if(sum[y]>sum[son[x]])son[x]=y;
    }
}
void DFS2(int x,int tp){
    top[x]=tp;
    pos[id[x]=++tot]=x;
    if(son[x])DFS2(son[x],tp);
    for(int i=h[x];i;i=d[i].next){
        int y=d[i].to;
        if(y!=son[x]&&y!=fa[x])DFS2(y,y);
    }
}
int LCA(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        x=fa[top[x]];
    }
    return dep[x]<dep[y]?x:y;
}
int Pre(int x,int p){
    while(top[x]!=top[p]){
        if(fa[top[x]]==p)return top[x];
        x=fa[top[x]];
    }
    return son[p];
}
struct List{
    int num,s[50],t[50];
    int Len(int i){return abs(s[i]-t[i])+1;}
    int Hash(int i,int j,int k){
        int dlt=(s[i]<t[i]?1:-1);
        int l=s[i]+dlt*j,r=s[i]+dlt*(j+k-1);
        return dlt==1?LHash(l,r):RHash(r,l);
    }
    void Insert(int x,int y){num++;s[num]=x;t[num]=y;}
    void Reverse(int l,int r){
        reverse(s+l,s+r+1);
        reverse(t+l,t+r+1);
        for(int i=l;i<=r;i++)swap(s[i],t[i]);
    }
}L1,L2;
void Get(int x,int p,List &L,int flag){
    int fst=L.num;
    while(top[x]!=top[p]){
        L.Insert(id[x],id[top[x]]);
        x=fa[top[x]];
    }
    L.Insert(id[x],id[p]);
    if(flag)L.Reverse(fst+1,L.num);
}
void GetList(int x,int y,List &L){
    int z=LCA(x,y);L.num=0;
    if(x==z)Get(y,z,L,1);
    else if(y==z)Get(x,z,L,0);
    else{
        int p=Pre(x,z);
        Get(x,p,L,0);
        Get(y,z,L,1);
    }
}
int Solve(List &L1,List &L2){
    int p1=1,q1=0,p2=1,q2=0,ans=0;
    while(p1<=L1.num&&p2<=L2.num){
        int len=min(L1.Len(p1)-q1,L2.Len(p2)-q2);
        if(L1.Hash(p1,q1,len)==L2.Hash(p2,q2,len)){
            ans+=len;q1+=len;q2+=len;
            if(q1==L1.Len(p1)){p1++;q1=0;}
            if(q2==L2.Len(p2)){p2++;q2=0;}
        }
        else{
            int l=1,r=len,tmp=0;
            while(l<=r){
                int mid=(l+r)>>1;
                if(L1.Hash(p1,q1,mid)==L2.Hash(p2,q2,mid)){tmp=mid;l=mid+1;}
                else r=mid-1;
            }
            ans+=tmp;
            break;
        }
    }
    return ans;
}
void Prepare(){
    P[0]=1;
    for(int i=1;i<=n;i++)P[i]=1ll*P[i-1]*Mul%Mod;
    DFS1(1,1);DFS2(1,1);
    for(int i=1;i<=n;i++)HL[i]=(1ll*HL[i-1]*Mul+s[pos[i]])%Mod;
    for(int i=n;i>=1;i--)HR[i]=(1ll*HR[i+1]*Mul+s[pos[i]])%Mod;
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();scanf("%s",s+1);
    for(int i=1;i<n;i++){int x=read(),y=read();Add(x,y);Add(y,x);}
    Prepare();
    m=read();
    while(m--){
        int sx=read(),sy=read(),tx=read(),ty=read();//sx->sy tx->ty
        GetList(sx,sy,L1);GetList(tx,ty,L2);
        printf("%d\n",Solve(L1,L2));
    }
	return 0;
}
