/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=998244353;
const int N=4;
const int M=6;
ll read(){
	ll s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
struct Matrix{
    int a[M][M];
    void Init(){memset(a,0,sizeof(a));}
    void Init1(){
        // f[i][min(j+1,5)]+=f[i-1][j] 0<=j<=5
        Init();
        for(int i=0;i<M;i++)a[i][min(i+1,5)]++;
    }
    void Init2(){
        // f[i][j-1]+=f[i-1][j] 1<=j<=5
        // f[i][1]+=f[i-1][0]
        Init();
        a[0][1]++;
        for(int i=1;i<M;i++)a[i][i-1]++;
    }
    void Init3(){
        // f[i][min(j+1,5)]+=f[i-1][j] 0<=j<=5
        // f[i][j-1]+=f[i-1][j] 1<=j<=5
        Init();
        for(int i=0;i<M;i++)a[i][min(i+1,5)]++;
        for(int i=1;i<M;i++)a[i][i-1]++;
    }
    friend Matrix operator*(Matrix A,Matrix B){
        Matrix C;C.Init();
        for(int i=0;i<M;i++){
            for(int j=0;j<M;j++){
                for(int k=0;k<M;k++){
                    C.a[i][j]=(C.a[i][j]+1ll*A.a[i][k]*B.a[k][j])%Mod;
                }
            }
        }
        return C;
    }
    void Print(){
        for(int i=0;i<M;i++){
            cout<<"  ";
            for(int j=0;j<M;j++){
                cout<<a[i][j]<<(j==M-1?"\\\\":" & ");
            }
            cout<<endl;
        }
    }
};
ll n;
int K,Ans,t[N];
Matrix A[N];
Matrix Pow(Matrix x,ll y){
    Matrix ans;ans.Init();
    for(int i=0;i<M;i++)ans.a[i][i]=1;
    while(y){if(y&1)ans=ans*x;x=x*x;y>>=1;}
    return ans;
}
int main(){
    n=read();K=read();
    for(int i=0;i<N;i++){
        t[i]=read();
        if(t[i]==1)A[i].Init1();
        if(t[i]==2)A[i].Init2();
        if(t[i]==3)A[i].Init3();
        A[i].Print();
        cout<<endl;
    }
	Matrix res=Pow(A[0]*A[1]*A[2]*A[3],n/4);
    for(int i=0;i<n%4;i++)res=res*A[i];
    for(int i=0;i<M;i++)Ans=(Ans+res.a[K][i])%Mod;
    printf("%d\n",Ans);
	return 0;
}
