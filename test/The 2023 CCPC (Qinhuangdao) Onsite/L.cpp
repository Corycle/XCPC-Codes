#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e6+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
unordered_map<int,int>Ans[N];
int n,m,a[N],pos[N],MaxL[N],MaxR[N],MinL[N],MinR[N];
void Clear(){
    for(int i=1;i<=n;i++)Ans[i].clear();
}
void Solve(){
    int l=pos[1],r=pos[1];
    MaxR[pos[1]]=MaxL[pos[1]]=1;
    for(int i=pos[1]+1;i<=n;i++)MaxR[i]=max(MaxR[i-1],a[i]);
    for(int i=pos[1]-1;i>=1;i--)MaxL[i]=max(MaxL[i+1],a[i]);
    MinL[0]=MinR[n+1]=inf;
    for(int i=1;i<=n;i++)MinL[i]=min(MinL[i-1],a[i]);
    for(int i=n;i>=1;i--)MinR[i]=min(MinR[i+1],a[i]);
    int LL=pos[1],RR=pos[1];
    for(int i=1;i<=n;i++){
        while(l!=1&&a[l-1]<=i)l--;
        while(r!=n&&a[r+1]<=i)r++;
        int L=min(l,pos[i]);
        int R=max(r,pos[i]);
        LL=min(LL,pos[i]);
        RR=max(RR,pos[i]);
        if(r-l+1==i-1){
            int t=min(MinL[l-1],MinR[r+1]);
            if(l!=1&&t!=inf)Ans[t][a[l-1]]++;
            if(r!=n&&t!=inf)Ans[t][a[r+1]]++;
            if(r+2<=n&&a[r+2]==t)Ans[a[l]][a[r+1]]++;
            if(l-2>=1&&a[l-2]==t)Ans[a[r]][a[l-1]]++;
        }
        else if(RR-LL+1==i+1){
            int Max=max(MaxL[LL],MaxR[RR]);
            if(a[LL]!=i)Ans[a[LL]][Max]++;
            if(a[RR]!=i)Ans[a[RR]][Max]++;
        }
    }
}
void Calc(int &x,int &y,int &answer){
    for(int i=1;i<=n;i++){
        for(auto tmp:Ans[i]){
            if(tmp.second>answer){
                answer=tmp.second;
                x=pos[i];y=pos[tmp.first];
            }
        }
    }
}
int main(){
    int T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++)pos[a[i]=read()]=i;
        
        int x=1,y=1,answer=0;
        Solve();
        Calc(x,y,answer);
        Clear();
        //Solve1()
        printf("%d %d\n",x,y);
    }
    return 0;
}