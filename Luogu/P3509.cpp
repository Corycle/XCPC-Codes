/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e6+5;
ll read(){
	ll s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
ll m,a[N];
int n,K,p[N],tmp[N],Ans[N];
int Check(int x,int d){return a[x]-a[x-d]<a[x+K-d]-a[x];}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();K=read();m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++){
        if(i==1){p[i]=i+K;continue;}
        if(i==n){p[i]=i-K;continue;}
        if(n-K<=i&&a[n]-a[i]<=a[i]-a[n-K]){p[i]=n-K;continue;}
        int l=max(0,i+K-n),r=min(K,i-1),ans=l;
        while(l<=r){
            int mid=(l+r)>>1;
            if(Check(i,mid)){ans=mid;l=mid+1;}
            else r=mid-1;
        }
        if(ans!=i-1&&a[i]-a[i-ans-1]<=a[i+K-ans]-a[i])p[i]=i-ans-1;
        else p[i]=i+K-ans;
    }
    // for(int i=1;i<=n;i++)cout<<p[i]<<" ";cout<<endl;
    for(int i=1;i<=n;i++)Ans[i]=i;
    while(m){
        if(m&1)for(int i=1;i<=n;i++)Ans[i]=p[Ans[i]];
        for(int i=1;i<=n;i++)tmp[i]=p[p[i]];
        for(int i=1;i<=n;i++)p[i]=tmp[i];
        m>>=1;
    }
    for(int i=1;i<=n;i++)printf("%d ",Ans[i]);
	return 0;
}
