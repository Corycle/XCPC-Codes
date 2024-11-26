#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m;
struct Tree{
    int c[N];
    void clear(){
        for(int i=1;i<=n;i++)c[i]=0;
    }
    int lowbit(int x){
        return x&(-x);
    }
    void Add(int x,int y){
        for(;x<=n;x+=lowbit(x))c[x]+=y;
    }
    int Ask(int x){
        int ans=0;
        for(;x>=1;x-=lowbit(x))ans+=c[x];
        return ans;
    }
}tree;
struct Node{
    int a,b;
}P[N];
bool cmp(Node A,Node B){
    return A.b<B.b;
}
char ans[N];
int main(){
    int T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++)P[i].a=read();
        for(int i=1;i<=n;i++)P[i].b=read();
        sort(P+1,P+n+1,cmp);
        int num=0;
        tree.clear();
        for(int i=1;i<=n+1;i++)ans[i]=0;
        for(int i=1;i<=n;i++){
            num=num^((tree.Ask(n)-tree.Ask(P[i].a))&1);
            tree.Add(P[i].a,1);
        }
        ans[1]=(num?'A':'B');
        for(int i=2;i<=n;i++){
            int l=read(),r=read(),x=read();
            num=num^(((r-l)*x)&1);
            ans[i]=(num?'A':'B');
        }
        printf("%s\n",ans+1);
    }
    return 0;
}