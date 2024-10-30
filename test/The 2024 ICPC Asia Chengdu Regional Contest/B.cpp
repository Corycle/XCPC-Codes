#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int Mod=1e9+7;
const int N=305;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
char s[N];
int n,m,q,f[3][N][N][N],cnt[3],g[N][N][N],sum[N][N][N];
int main(){
    n=read();m=read();
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        cnt[0]+=(s[i]=='a');
        cnt[1]+=(s[i]=='b');
        cnt[2]+=(s[i]=='c');
    }
    if(s[1]=='a'||s[1]=='?')f[0][1][0][0]=1;
    if(s[1]=='b'||s[1]=='?')f[1][0][1][0]=1;
    if(s[1]=='c'||s[1]=='?')f[2][0][0][1]=1;
    for(int i=2;i<=n;i++){
        for(int x=0;x<=i;x++){
            for(int y=0;x+y<=i;y++){
                int z=i-(x+y);
                if(x&&(s[i]=='a'||s[i]=='?')){
                    f[0][x][y][z]=(f[0][x][y][z]+f[1][x-1][y][z])%Mod;
                    f[0][x][y][z]=(f[0][x][y][z]+f[2][x-1][y][z])%Mod;
                }
                if(y&&(s[i]=='b'||s[i]=='?')){
                    f[1][x][y][z]=(f[1][x][y][z]+f[0][x][y-1][z])%Mod;
                    f[1][x][y][z]=(f[1][x][y][z]+f[2][x][y-1][z])%Mod;
                }
                if(z&&(s[i]=='c'||s[i]=='?')){
                    f[2][x][y][z]=(f[2][x][y][z]+f[0][x][y][z-1])%Mod;
                    f[2][x][y][z]=(f[2][x][y][z]+f[1][x][y][z-1])%Mod;
                }
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;i+j<=n;j++){
            int k=n-i-j;
            g[i][j][k]=(1ll*f[0][i][j][k]+f[1][i][j][k]+f[2][i][j][k])%Mod;
        }
    }
    for(int i=1;i<=n;i++){
        sum[i][0][0]=(sum[i-1][0][0]+g[i][0][0])%Mod;
        sum[0][i][0]=(sum[0][i-1][0]+g[0][i][0])%Mod;
        sum[0][0][i]=(sum[0][0][i-1]+g[0][0][i])%Mod;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum[i][j][0]=(1ll*sum[i-1][j][0]+sum[i][j-1][0]-sum[i-1][j-1][0]+g[i][j][0]+Mod)%Mod;
            sum[i][0][j]=(1ll*sum[i-1][0][j]+sum[i][0][j-1]-sum[i-1][0][j-1]+g[i][0][j]+Mod)%Mod;
            sum[0][i][j]=(1ll*sum[0][i-1][j]+sum[0][i][j-1]-sum[0][i-1][j-1]+g[0][i][j]+Mod)%Mod;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                sum[i][j][k]=(1ll*sum[i-1][j][k]+sum[i][j-1][k]+sum[i][j][k-1]-sum[i-1][j-1][k]-sum[i-1][j][k-1]-sum[i][j-1][k-1]+sum[i-1][j-1][k-1]+g[i][j][k])%Mod;
                sum[i][j][k]=(sum[i][j][k]+Mod)%Mod;
            }
        }
    }
    while(m--){
        // int x=read(),y=read(),z=read();
        // cout<<f[0][x][y][z]+f[1][x][y][z]+f[2][x][y][z]<<endl;
        int x=read()+cnt[0],y=read()+cnt[1],z=read()+cnt[2];
        x=min(x,n);y=min(y,n);z=min(z,n);
        printf("%d\n",sum[x][y][z]);
    }
    return 0;
}