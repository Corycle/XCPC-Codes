/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;
const int inf=0x3f3f3f3f;
const ll INF=4e18;
const int N=5e5+5;
ll read(){
	ll s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m;
ll Speed,a[N];
struct Node{ll t,pos,dis;}P[N];
bool cmp(Node A,Node B){return A.t>B.t;}
bool Check(ll T){
//  cout<<"Check: "<<T<<endl;
    ll sum=0;
    for(int i=1;i<=n;i++)a[i]=0;
    for(int i=1;i<=m;i++){
        if(P[i].t>T)continue;
        __int128 endDis=P[i].dis-(__int128)(T-P[i].t+1-a[P[i].pos])*Speed;
        if(endDis>0)continue;
        ll tNeed=(-endDis)/Speed+1;
        a[P[i].pos]+=tNeed;
        sum+=tNeed;
        if(T-P[i].t+1<sum)return false;
    }
    return true;
}
int main(){
//	freopen("input-18.txt","r",stdin);
	n=read();m=read();Speed=read();
    bool flag=true;
    for(int i=1;i<=m;i++){
        P[i].t=read();P[i].pos=read();P[i].dis=read();
        if(P[i].pos!=P[1].pos)flag=false;
    }
    if(flag){
        puts("-1");
        return 0;
    }
    sort(P+1,P+m+1,cmp);
    ll l=0,r=INF,ans=0;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(Check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    if(ans==INF)ans=-1;
    printf("%lld\n",ans);
	return 0;
}
