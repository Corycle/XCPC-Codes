#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Mod=998244353;
const int G=3;
const int N=5e5+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int m,K,len,L,R[N],B[N];
int mod(int x){return x>=Mod?x-Mod:x;}
int Pow(int x,int y){
    int ans=1;
    while(y){
        if(y&1)ans=1ll*ans*x%Mod;
        x=1ll*x*x%Mod;
        y>>=1;
    }
    return ans;
}
void Prepare(int n){
    len=1;L=0;while(len<=n+n){len<<=1;L++;}
    for(int i=0;i<len;i++)R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
}
void NTT(int a[],int n,int f){
    for(int i=0;i<n;i++)if(i<R[i])swap(a[i],a[R[i]]);
    for(int i=1;i<n;i<<=1){
        int Wn=Pow(G,Mod-1+f*(Mod-1)/(i<<1));
        for(int j=0;j<n;j+=(i<<1)){
            int W=1;
            for(int k=0;k<i;k++){
                int x=a[j+k],y=1ll*W*a[j+k+i]%Mod;
                a[j+k]=mod(x+y);
                a[j+k+i]=mod(x-y+Mod);
                W=1ll*W*Wn%Mod;
            }
        }
    }
    if(f==-1){
        int inv=Pow(n,Mod-2);
        for(int i=0;i<n;i++)a[i]=1ll*a[i]*inv%Mod;
    }
}
int b[N],c[N];
void Solve(vector<int>& a,int l,int r){
    if(l==r){
        a.resize(2);
        a[0]=1;
        a[1]=B[l];
        // cout<<"Solve: "<<l<<" "<<r<<endl;
        // for(auto x:a)cout<<x<<" ";cout<<endl;
        return;
    }
    int mid=(l+r)>>1;
    vector<int> a1,a2;
    Solve(a1,l,mid);
    Solve(a2,mid+1,r);
    Prepare(r-l+2);
    int num1=a1.size(),num2=a2.size();
    for(int i=0;i<num1;i++)b[i]=a1[i];
    for(int i=num1;i<len;i++)b[i]=0;
    for(int i=0;i<num2;i++)c[i]=a2[i];
    for(int i=num2;i<len;i++)c[i]=0;
    NTT(b,len,1);NTT(c,len,1);
    for(int i=0;i<len;i++)b[i]=1ll*b[i]*c[i]%Mod;
    NTT(b,len,-1);
    a.resize(r-l+2);
    for(int i=0;i<=r-l+1;i++)a[i]=b[i];
    // cout<<"Solve: "<<l<<" "<<r<<endl;
    // for(auto x:a)cout<<x<<" ";cout<<endl;
}
int fac[N],inv[N];
int C(int n,int m){return 1ll*fac[n]*inv[m]%Mod*inv[n-m]%Mod;}
int main(){
    m=read();K=read();
    for(int i=1;i<=m;i++)B[i]=read();
    vector<int>ans;
    Solve(ans,1,m); 
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<=m;i++)fac[i]=1ll*fac[i-1]*i%Mod;
    for(int i=2;i<=m;i++)inv[i]=1ll*inv[Mod%i]*(Mod-Mod/i)%Mod;
    for(int i=2;i<=m;i++)inv[i]=1ll*inv[i-1]*inv[i]%Mod;
    // cout<<"ans: "<<endl;
    // for(auto x:ans)cout<<x<<" ";cout<<endl;
    int Ans=1ll*Pow(Pow(K,K/2),Mod-2)*Pow(C(m,K),Mod-2)%Mod*ans[K]%Mod;
    printf("%d\n",Ans);
    return 0;
}