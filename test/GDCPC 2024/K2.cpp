#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Mod=998244353;
const int M=52;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,K;
int mod(int x){return x>=Mod?x-Mod:x;}
/*===========================Node===========================*/
struct Node{
    int a[2][2];
    void Init(){memset(a,0,sizeof(a));}
};
Node Multi(const Node &A,const Node &B){
    Node C;
    C.a[0][0]=(1ll*A.a[0][0]*B.a[0][0]+1ll*A.a[0][1]*B.a[1][0])%Mod;
    C.a[0][1]=(1ll*A.a[0][0]*B.a[0][1]+1ll*A.a[0][1]*B.a[1][1])%Mod;
    C.a[1][0]=(1ll*A.a[1][0]*B.a[0][0]+1ll*A.a[1][1]*B.a[1][0])%Mod;
    C.a[1][1]=(1ll*A.a[1][0]*B.a[0][1]+1ll*A.a[1][1]*B.a[1][1])%Mod;
    return C;
}
Node Add(const Node &A,const Node &B){
    Node C;C.Init();
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)C.a[i][j]=mod(A.a[i][j]+B.a[i][j]);
    return C;
}
Node Pow(Node x,int y){
    Node ans;ans.Init();ans.a[0][0]=ans.a[1][1]=1;
    while(y){if(y&1)ans=Multi(ans,x);x=Multi(x,x);y>>=1;}
    return ans;
}
/*===========================Matrix===========================*/
struct Matrix{
    Node a[M][M];
    void Init(){
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j].Init();
    }
}A;
Matrix Add(const Matrix &A,const Matrix &B){
    Matrix C;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)C.a[i][j]=Add(A.a[i][j],B.a[i][j]);
    return C;
}
Matrix Multi(const Matrix &A,const Matrix &B){
    Matrix C;C.Init();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                C.a[i][j]=Add(C.a[i][j],Multi(A.a[i][k],B.a[k][j]));
            }
        }
    }
    return C;
}
Matrix Pow(Matrix x,int y){
    Matrix ans;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ans.a[i][j]=x.a[i][j];
    y--;
    while(y){if(y&1)ans=Multi(ans,x);x=Multi(x,x);y>>=1;}
    return ans;
}
/*===========================Main===========================*/
int main(){
    Node E;E.Init();
    E.a[0][0]=E.a[0][1]=E.a[1][0]=1;
    n=read();m=read();K=read();
    if(!K){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf("0 ");
            }
            puts("");
        }
        return 0;
    }
    for(int i=1;i<=m;i++){
        int x=read(),y=read(),w=read();
        A.a[x][y]=Add(A.a[x][y],Pow(E,w));
    }
    A=Pow(A,K);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",mod(A.a[i][j].a[1][0]));
        }
        puts("");
    }
    return 0;
}