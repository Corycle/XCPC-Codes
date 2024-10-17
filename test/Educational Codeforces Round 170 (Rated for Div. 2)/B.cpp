#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
const int N=1e5+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,a[N],b[N],p[N];
// int C[100][100];
int main(){
    p[0]=1;
    for(int i=1;i<N;i++)p[i]=(p[i-1]<<1)%Mod;
    int n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)b[i]=read();
    for(int i=1;i<=n;i++){
        printf("%d\n",a[i]==b[i]?1:p[b[i]]);
    }
    // for (int n = 0; n < 10; n++) { // loop over n from 0 to N-1 (inclusive)
    //     C[n][0] = 1;
    //     C[n][n] = 1;
    //     for (int k = 1; k < n; k++) // loop over k from 1 to n-1 (inclusive)
    //         C[n][k] = C[n][k - 1] + C[n - 1][k - 1];
    //     for(int i=0;i<=n;i++)cout<<C[n][i]<<" ";
    //     cout<<endl;
    // }
    return 0;
}