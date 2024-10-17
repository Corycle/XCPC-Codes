#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Mod=1e9+7;
const int N=2e6+5;
const int M=27;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,cnt;
string s[N],t[N];
inline int mod(int x){return x>=Mod?x-Mod:x;}
struct SAM{
    vector<int>G[N];
    int tot,lst,root;
    int ch[N][M],fa[N],len[N],sum1[N],sum2[N];
    void Init(){tot=lst=root=1;}
    void Insert(int c){
        int x=lst,fx=++tot;len[fx]=len[x]+1;
        while(x&&!ch[x][c]){ch[x][c]=fx;x=fa[x];}
        if(!x)fa[fx]=root;
        else{
            int y=ch[x][c];
            if(len[y]==len[x]+1)fa[fx]=y;
            else{
                int fy=++tot;len[fy]=len[x]+1;
                fa[fy]=fa[y];fa[y]=fa[fx]=fy;
                memcpy(ch[fy],ch[y],sizeof(ch[y]));
                while(x&&ch[x][c]==y){ch[x][c]=fy;x=fa[x];}
            }
        }
        lst=fx;
    }
    void DFS(int x){
        for(auto y:G[x]){
            sum1[y]=mod(sum1[y]+sum1[x]);
            sum2[y]=mod(sum2[y]+sum2[x]);
            DFS(y);
        }
    }
    void Build(){
        for(int i=2;i<=tot;i++){
            G[fa[i]].push_back(i);
        }
    }
    void Update(string& s){
        int p=root;
        int len=s.length();
        for(int i=len-1;i>=0;i--){
            char c=s[i];
            if(ch[p][c-'a'])p=ch[p][c-'a'];
            else return;
        }
        sum1[p]++;
        sum2[p]=mod(sum2[p]+len);
    }
    int Query(string &s){
        int ans=0;
        int n=s.length(),p=1;
        for(int i=n-1;i>=0;i--){
            p=ch[p][s[i]-'a'];
            int l=i+1;
            ans=(ans+1ll*(n+2-l)*l*sum1[p]%Mod-1ll*l*sum2[p]%Mod+Mod)%Mod;
        }
        return ans;
    }
}sam;
char S[N];
int main(){
    sam.Init();
    n=read();m=read();
    for(int i=1;i<=n;i++){
        scanf("%s",S);
        s[i]=(string)S;
    }
    for(int i=1;i<=m;i++){
        scanf("%s",S);
        t[i]=(string)S;
    }
    for(int i=m;i>=1;i--){
        sam.lst=1;
        int l=t[i].length();
        for(int j=l-1;j>=0;j--){
            sam.Insert(t[i][j]-'a');
        }
        sam.Insert(26);
    }
    sam.Build();
    for(int i=1;i<=n;i++)sam.Update(s[i]);
    sam.DFS(1);
    for(int i=1;i<=m;i++)printf("%d\n",sam.Query(t[i]));
    return 0;
}