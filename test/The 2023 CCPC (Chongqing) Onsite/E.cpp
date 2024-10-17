#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=30,M=50,K=12; 
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,k;
vector<int> e[N+5];
int fruit[N+5];
double f[N+5][N+5][(1<<K)+5];
int main(){
    n=read();m=read();k=read();
    for(int i=1;i<=m;++i){
        int u=read(),v=read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=k;++i){
        int x=read();
        fruit[x]=i;
    }
    for(int j=n-1;j>=0;--j){
        for(int S=0;S<(1<<k);++S){
            for(int i=1;i<=n;++i){
                int size_S = __builtin_popcount(S);
                f[i][j][S]=0;
                for(auto u : e[i]){
                    double res = 0;
                    if(fruit[u]&&(S&(1<<fruit[u]>>1))){
                        res = (n-j-size_S+1)*(f[u][j+1][S^(1<<fruit[u]>>1)]+1);
                        for(int x=1;x<(1<<k);x<<=1) if((S&x)&&x!=(1<<fruit[u]>>1))
                            res += f[u][j+1][S^x^(1<<fruit[u]>>1)]+1;
                        res /= n-j;
                    }
                    else{
                        res = 1.0*(n-j-size_S)*f[u][j+1][S];
                        for(int x=1;x<(1<<k);x<<=1) if(S&x)
                            res += f[u][j+1][S^x];
                        res /= n-j;
                    }
                    f[i][j][S] = max(f[i][j][S],res);
                }
            }
        }
    }
    cout<<f[1][0][(1<<k)-1];
    cout<<f[1][0][3]<<f[3][1][1]<<f[3][1][0];
}