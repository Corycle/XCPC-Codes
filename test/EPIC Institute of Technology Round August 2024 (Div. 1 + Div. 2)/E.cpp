/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=3e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n;
ll t,ans[N];
struct Node{
    int num,val;
    int Lid,Rid,id;
    ll t;
    friend bool operator<(Node A,Node B){
        return A.t!=B.t?A.t<B.t:A.id>B.id;
    }
}P[N];
set<Node>q;
void Clear(){
    t=0;
    q.clear();
    for(int i=0;i<=n+1;i++){
        ans[i]=0;
        P[i].num=P[i].val=P[i].Lid=P[i].Rid=P[i].id=P[i].t=0;
    }
}
void Delete(int x){
    int l=P[x].Lid,r=P[x].Rid;
    P[l].Rid=r;P[r].Lid=l;
    if(P[x].val==P[r].val){
        P[r].t=t+P[r].num;
        q.insert(P[r]);
    }
    if(P[l].val==P[r].val){
        q.erase(q.find(P[r]));
        P[r].num=P[r].t-t;
    }
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
    int T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++){
            P[i].num=read();
            P[i].val=read();
            P[i].Lid=i-1;
            P[i].Rid=i+1;
            P[i].id=i;
            P[i].t=P[i].num;
            q.insert(P[i]);
        }
        t=0;
        P[0].num=P[0].val=inf;P[0].Rid=1;
        P[n+1].num=P[n+1].val=inf+1;P[n+1].Lid=n;
        while(!q.empty()){
            Node x=*q.begin();
            q.erase(q.begin());
            t=x.t;
            ans[x.id]=t;
            Delete(x.id);
        }
        for(int i=1;i<=n;i++){
            ans[i]=max(ans[i],ans[i-1]);
            printf("%lld ",ans[i]);
        }
        puts("");
        Clear();
    }
	return 0;
}
