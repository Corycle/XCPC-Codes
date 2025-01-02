/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=998244353;
const int N=5e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,pos1[N],pos2[N];
struct Node{
    int val,id;
    friend bool operator<(Node A,Node B){
        return A.val<B.val;
    }
}P[N],Q[N];
int Pow(int x,int y){
    int ans=1;
    while(y){
        if(y&1)ans=1ll*ans*x%Mod;
        x=1ll*x*x%Mod;
        y>>=1;
    }
    return ans;
}
int Inv(int x){
    return Pow(x,Mod-2);
}
int main(){
	// freopen("D.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        n=read();m=read();
        for(int i=1;i<=n;i++)P[i].val=read();
        for(int i=1;i<=n;i++)Q[i].val=read();
        for(int i=1;i<=n;i++)P[i].id=Q[i].id=i;
        sort(P+1,P+n+1);
        sort(Q+1,Q+n+1);
        for(int i=1;i<=n;i++)pos1[P[i].id]=i;
        for(int i=1;i<=n;i++)pos2[Q[i].id]=i;
        int Ans=1;
        for(int i=1;i<=n;i++){
            Ans=1ll*Ans*min(P[i].val,Q[i].val)%Mod;
        }
        printf("%d ",Ans);
        while(m--){
            int op=read(),x=read();
            if(op==1){
                if(pos1[x]!=n&&P[pos1[x]].val+1>P[pos1[x]+1].val){
                    int pos=lower_bound(P+1,P+n+1,(Node){P[pos1[x]].val+1,0})-P-1;
                    int A=pos1[x],B=pos;
                    Ans=1ll*Ans*Inv(min(P[A].val,Q[A].val))%Mod;
                    Ans=1ll*Ans*Inv(min(P[B].val,Q[B].val))%Mod;
                    P[A].val++;
                    swap(P[A],P[B]);
                    pos1[P[A].id]=A;
                    pos1[P[B].id]=B;
                    Ans=1ll*Ans*min(P[A].val,Q[A].val)%Mod;
                    Ans=1ll*Ans*min(P[B].val,Q[B].val)%Mod;
                }
                else{
                    Ans=1ll*Ans*Inv(min(P[pos1[x]].val,Q[pos1[x]].val))%Mod;
                    P[pos1[x]].val++;
                    Ans=1ll*Ans*min(P[pos1[x]].val,Q[pos1[x]].val)%Mod;
                }
            }
            else{
                if(pos2[x]!=n&&Q[pos2[x]].val+1>Q[pos2[x]+1].val){
                    int pos=lower_bound(Q+1,Q+n+1,(Node){Q[pos2[x]].val+1,0})-Q-1;
                    int A=pos2[x],B=pos;
                    Ans=1ll*Ans*Inv(min(P[A].val,Q[A].val))%Mod;
                    Ans=1ll*Ans*Inv(min(P[B].val,Q[B].val))%Mod;
                    Q[A].val++;
                    swap(Q[A],Q[B]);
                    pos2[Q[A].id]=A;
                    pos2[Q[B].id]=B;
                    Ans=1ll*Ans*min(P[A].val,Q[A].val)%Mod;
                    Ans=1ll*Ans*min(P[B].val,Q[B].val)%Mod;
                }
                else{
                    Ans=1ll*Ans*Inv(min(P[pos2[x]].val,Q[pos2[x]].val))%Mod;
                    Q[pos2[x]].val++;
                    Ans=1ll*Ans*min(P[pos2[x]].val,Q[pos2[x]].val)%Mod;
                }
            }
            printf("%d ",Ans);
        }
        puts("");
    }
	return 0;
}
