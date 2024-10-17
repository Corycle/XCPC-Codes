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
ll Ans;
int n,cnt[N<<1];
struct Node{int x,y;}P[N];
bool cmp(Node A,Node B){return A.x<B.x;}
int Lmin[N],Lmax[N],Rmin[N],Rmax[N];
void Calc(int l,int r,int mid){
    Lmax[mid+1]=0;Lmin[mid+1]=n+1;
    for(int i=mid;i>=l;i--){
        Lmax[i]=max(Lmax[i+1],P[i].y);
        Lmin[i]=min(Lmin[i+1],P[i].y);
    }
    Rmax[mid]=0;Rmin[mid]=n+1;
    for(int i=mid+1;i<=r;i++){
        Rmax[i]=max(Rmax[i-1],P[i].y);
        Rmin[i]=min(Rmin[i-1],P[i].y);
    }
    int p1=mid,p2=mid+1;
    for(p1=mid;p1>=l;p1--){
        p2=p1+Lmax[p1]-Lmin[p1];
        if(p2>mid&&p2<=r&&Rmax[p2]<Lmax[p1]&&Rmin[p2]>Lmin[p1])Ans++;
    }
    p1=mid+1;p2=mid+1;
    for(int i=mid;i>=l;i--){
        while(p1<=r&&Rmax[p1]<Lmax[i]){cnt[p1+Rmin[p1]]++;p1++;}
        while(p2<=r&&Rmin[p2]>Lmin[i]){cnt[p2+Rmin[p2]]--;p2++;}
        if(p1!=mid+1)Ans+=max(cnt[i+Lmax[i]],0);
    }
    for(int i=mid+1;i<=r;i++)cnt[i+Rmin[i]]=0;
}
void Solve(int l,int r){
    if(l==r){Ans++;return;}
    int mid=(l+r)>>1;
    Solve(l,mid);Solve(mid+1,r);
    Calc(l,r,mid);reverse(P+l,P+r+1);
    if((r-l+1)&1)mid--;
    Calc(l,r,mid);reverse(P+l,P+r+1);
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();
    //Max-Min=R-L
    //Max+L=R+Min
    //L+Max-Min=R
    for(int i=1;i<=n;i++){P[i].x=read();P[i].y=read();}
    sort(P+1,P+n+1,cmp);
    Solve(1,n);
    printf("%lld\n",Ans);
	return 0;
}
