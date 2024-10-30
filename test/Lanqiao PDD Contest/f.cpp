/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=1e9+7;
const int Inv6=166666668;
const int N=17;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
char a[N];
int n,m,p[N],f[N][2][2][2][2][2][2][2][2][2][1024],vis[N][2][2][2][2][2][2][2][2][2][1024];
int Solve(int x,int f1,int f2,int f3,int g1,int g2,int g3,int w1,int w2,int w3,int sum){
    if(!x)return (sum==m)&&(g1==0)&&(g2==0)&&(g3==0)&&(w1==1)&&(w2==1)&&(w3==1);
    if(vis[x][f1][f2][f3][g1][g2][g3][w1][w2][w3][sum])return f[x][f1][f2][f3][g1][g2][g3][w1][w2][w3][sum];
    int m1=(f1?a[x]:9),m2=(f2?a[x]:9),m3=(f3?a[x]:9);
    int ans=0;
    for(int i=0;i<=m1;i++){
        if(i==1||i==2||i==4)continue;
        for(int j=0;j<=m2;j++){
            if(j==1||j==2||j==4)continue;
            for(int k=0;k<=m3;k++){
                if(k==1||k==2||k==4)continue;
                // if((sum+p[x]*(i+j+k))%1024==m)
    // cout<<"Solve: "<<x<<" "<<f1<<" "<<f2<<" "<<f3<<" "<<g1<<" "<<g2<<" "<<g3<<" "<<sum<<endl;
    // cout<<i<<" "<<j<<" "<<k<<" "<<(g1&(i==j))<<" "<<(g2&(i==k))<<" "<<(g3&(j==k))<<" "<<(sum+p[x]*(i+j+k))%1024<<endl;
                ans=(ans+Solve(x-1,f1&(i==m1),f2&(j==m2),f3&(k==m3),g1&(i==j),g2&(i==k),g3&(j==k),w1|(i!=0),w2|(j!=0),w3|(k!=0),(sum+p[x]*(i+j+k))%1024))%Mod;
            }
        }
    }
    vis[x][f1][f2][f3][g1][g2][g3][w1][w2][w3][sum]=1;
    return f[x][f1][f2][f3][g1][g2][g3][w1][w2][w3][sum]=ans;
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	scanf("%s",a+1);
    n=strlen(a+1);
    m=read();
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++)a[i]-='0';
    p[1]=1;
    for(int i=2;i<=n;i++)p[i]=p[i-1]*10%1024;
    // for(int i=1;i<=n;i++)cout<<p[i]<<" ";cout<<endl;
    printf("%d\n",1ll*Solve(n,1,1,1,1,1,1,0,0,0,0)*Inv6%Mod);
	return 0;
}
