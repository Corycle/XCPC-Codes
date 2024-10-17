/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e7+5;
const int M=2e6+5;
const int MM=105;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
bool vis[N];
int cnt,prime[M],vst[MM][MM];
int n,m;
void Prepare(){
    for(int i=2;i<N;i++){
        if(!vis[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&1ll*i*prime[j]<N;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
    for(int i=1;i<MM;i++){
        for(int j=1;j<MM;j++){
            if(__gcd(i,j)!=1)continue;
            // cout<<i<<" "<<j<<endl;
            if(i==1||j==1)vst[i][j]=1;
            else vst[i][j]=vst[i-1][j]|vst[i][j-1];
        }
        // for(int j=1;j<MM;j++)cout<<vst[i][j];
        // cout<<endl;
    }
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
    Prepare();
    int T=read();
    while(T--){
        int n=read(),m=read(),l=read(),f=read();
        if(n==m){
            int pos=upper_bound(prime+1,prime+cnt+1,n)-prime-1;
            int a=prime[pos],b=prime[pos]-1;
            ll ans=max(1ll*a*l+1ll*b*f,1ll*a*f+1ll*b*l);
            a=prime[pos-1];b=min(n,prime[pos-1]*2-1);
            ans=max(ans,max(1ll*a*l+1ll*b*f,1ll*a*f+1ll*b*l));
            a=1;b=n;
            ans=max(ans,max(1ll*a*l+1ll*b*f,1ll*a*f+1ll*b*l));
            //max_{i<=n} {(\sigma(i)-1)*l+i*f,(\sigma(i)-1)*f+i*l}
            for(int i=1;i<=min(MM-1,n);i++){
                for(int j=1;j<=min(MM-1,n);j++){
                    if(!vst[i][j])continue;
                    a=i;b=j;
                    ans=max(ans,max(1ll*a*l+1ll*b*f,1ll*a*f+1ll*b*l));
                }
            }
            printf("%lld\n",ans);
        }
    }
	return 0;
}
