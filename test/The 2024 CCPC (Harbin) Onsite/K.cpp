#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll read(){
    ll s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n;
ll m,ans,a[N],b[N],sum1[N],sum2[N];
struct Node{ll w;int l,r;}P[N];
bool cmp(Node A,Node B){return A.w<B.w;}
int main(){
    n=read();m=read();
    for(int i=1;i<=n;i++){
        P[i].w=read();P[i].l=read();P[i].r=read();
    }
    sort(P+1,P+n+1,cmp);
    ll sum=m;
    for(int i=1;i<=n;i++){
        sum-=P[i].l;
        a[i]=P[i].l;
    }
    int pos=0;
    for(int i=n;i>=1;i--){
        if(P[i].l+sum>P[i].r){
            sum-=P[i].r-P[i].l;
            a[i]=P[i].r;
        }
        else{
            a[i]+=sum;
            sum=0;
            pos=i;
            break;
        }
    }
    for(int i=1;i<=n;i++)ans+=1ll*a[i]*P[i].w;
    // l l l l l x r r r r r
    // printf("%lld\n",ans);
    // for(int i=1;i<=n;i++)cout<<P[i].w<<" "<<P[i].l<<" "<<P[i].r<<endl;
    // for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
    // cout<<pos<<endl;
    ll Answer=ans;
    for(int i=n;i>=1;i--){
        b[i]=P[i].r-a[i];
        sum1[i]=sum1[i+1]+b[i];
        sum2[i]=sum2[i+1]+b[i]*P[i].w;
    }
    for(int i=1;i<pos;i++){
        int l=i+1,r=n,res=n+1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(sum1[mid]<=P[i].l){
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        ll tmp=ans-P[i].l*P[i].w+sum2[res]+P[res-1].w*(P[i].l-sum1[res]);
        Answer=max(Answer,tmp);
        // cout<<i<<"? "<<res<<" "<<tmp<<endl;
        // cout<<P[i].l<<" "<<P[i].w<<" "<<sum2[res]<<" "<<P[res-1].w<<endl;
    }
    for(int i=1;i<=n;i++)sum1[i]=sum2[i]=b[i]=0;
    for(int i=1;i<=n;i++){
        b[i]=a[i]-P[i].l;
        sum1[i]=sum1[i-1]+b[i];
        sum2[i]=sum2[i-1]+b[i]*P[i].w;
    }
    for(int i=pos+1;i<=n;i++){
        if(sum1[i-1]<=m-a[i]){
            ll tmp=ans-sum2[i-1]+sum1[i-1]*P[i].w;
            Answer=max(Answer,tmp);
            // cout<<i<<": "<<tmp<<endl;
            continue;
        }
        int l=1,r=i-2,res=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(sum1[mid]<=m-P[i].r){
                res=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        ll tmp=ans-(sum2[res]+(m-P[i].r-sum2[res])*P[res+1].w)+(m-P[i].r)*P[i].w;
        Answer=max(Answer,tmp);
        // cout<<i<<"! "<<tmp<<endl;
    }
    printf("%lld\n",Answer);
    return 0;
}