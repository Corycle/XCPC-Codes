#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
priority_queue<int,vector<int>,greater<int> >q[N];
int n,ID[N],L[N],R[N];
struct Node{int l,r;}P[N];
void Clear(){
    for(int i=1;i<=n;i++)while(!q[i].empty())q[i].pop();
}
int Merge(int id1,int id2){
    if(q[id1].size()<q[id2].size())swap(id1,id2);
    while(!q[id2].empty()){q[id1].push(q[id2].top());q[id2].pop();}
    return id1;
}
int main(){
    int T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++)ID[i]=i;
        for(int i=1;i<=n;i++){
            P[i].l=read();
            P[i].r=read();
            q[ID[P[i].l]].push(P[i].r);
        }
        int ans=1;
        for(int i=1;i<=n;i++){
            if(q[ID[i]].empty()){ans=0;break;}
            int x=q[ID[i]].top();
            q[ID[i]].pop();
            if(!q[ID[i]].empty()&&x==q[ID[i]].top()){ans=0;break;}
            int newL=x+1;
            ID[newL]=Merge(ID[i],ID[newL]);
        }
        printf("%d\n",ans);
        Clear();
    }
    return 0;
}