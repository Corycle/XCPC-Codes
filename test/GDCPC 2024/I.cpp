#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=4e5+5;
const int M=26;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m;
char s[N];
struct SAM{
    set<int>R[N];
    vector<int>G[N];
    int tot,lst,root;
    int ch[N][M],fa[N],len[N],sum[N],ID[N],ans[N],Pos[N],p[N][M];
    void init(){tot=lst=root=1;}
    void Insert(int c,int pos){
        int x=lst,fx=++tot;len[fx]=len[x]+1;
        while(x&&!ch[x][c]){ch[x][c]=fx;x=fa[x];}
        if(!x)fa[fx]=root;
        else{
            int y=ch[x][c];
            if(len[y]==len[x]+1)fa[fx]=y;
            else{
                int fy=++tot;len[fy]=len[x]+1;
                fa[fy]=fa[y];fa[y]=fa[fx]=fy;
                memcpy(ch[fy],ch[y],sizeof(ch[fy]));
                while(x&&ch[x][c]==y){ch[x][c]=fy;x=fa[x];}
            }
        }
        lst=fx;
        ID[lst]=lst;
        R[lst].insert(pos);
        Pos[pos]=lst;
        sum[lst]++;
    }
    void Merge(int x,int id1,int id2){
        if(R[id1].size()<R[id2].size())swap(id1,id2);
        ID[x]=id1;
        for(auto pos:R[id2]){
            R[id1].insert(pos);
            set<int>::iterator it=R[id1].find(pos);
            if(it!=R[id1].begin()){
                --it;
                ans[x]=min(ans[x],pos-(*it));
                ++it;
            }
            ++it;
            if(it!=R[id1].end()){
                ans[x]=min(ans[x],(*it)-pos);
            }
        }
        R[id2].clear();
    }
    void DFS(int x){
        ans[x]=inf;
        p[x][0]=fa[x];
        for(int i=1;i<M;i++)p[x][i]=p[p[x][i-1]][i-1];
        for(auto y:G[x]){
            DFS(y);
            ans[x]=min(ans[x],ans[y]);
            Merge(x,ID[x],ID[y]);
            sum[x]+=sum[y];
        }
    }
    void Build(){
        for(int i=2;i<=tot;i++)G[fa[i]].push_back(i);
        DFS(1);
    }
    int Query(int l,int r){
        int Len=r-l+1;
        int x=Pos[r];
        for(int i=M-1;i>=0;i--){
            if(len[p[x][i]]>=Len)x=p[x][i];
        }
        if(sum[x]==1)return -1;
        return ans[x]+Len;
    }
}sam;
int main(){
    sam.init();
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++)sam.Insert(s[i]-'a',i);
    sam.Build();
    m=read();
    for(int i=1;i<=m;i++){
        int l=read(),r=read();
        printf("%d\n",sam.Query(l,r));
    }
    return 0;
}