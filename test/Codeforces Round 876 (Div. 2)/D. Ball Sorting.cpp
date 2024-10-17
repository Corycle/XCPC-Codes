/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=505;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,a[N],f[N][N],ans[N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        n=read();
        a[1]=0;a[n+2]=n+1;
        for(int i=2;i<=n+1;i++)a[i]=read();
        m=n+2;
        for(int i=0;i<=m;i++)for(int j=0;j<=m;j++)f[i][j]=-inf;
        f[1][1]=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<i;j++){
                for(int k=1;k<=i;k++){
                    if(a[j]<a[i]){
                        if(j==i-1)f[i][k]=max(f[i][k],f[j][k]+1);
                        else f[i][k]=max(f[i][k],f[j][k-1]+1);
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)ans[i]=n+2-f[m][i+1];
        int flag=1;
        for(int i=1;i<=m;i++)if(a[i]!=i-1)flag=0;
        if(flag)ans[1]=0;
        for(int i=2;i<=n;i++)ans[i]=min(ans[i],ans[i-1]);
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
    }
	return 0;
}
