/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1005;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,tot,a[N][N];
int Rand(int x){return (1ll*rand()*rand()+rand())%x+1;}
int NewID(){
    int x=Rand(m);
    return x;
}
int main(){
	// freopen("T3_15.in","w",stdout);
    srand(time(NULL));
    n=1000;m=1000000;
    int P=90;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1&&j==1){
                a[i][j]=NewID();
                continue;
            }
            int p=Rand(100);
            if(p<=P){
                if(i==1)a[i][j]=a[i][j-1];
                else if(j==1)a[i][j]=a[i-1][j];
                else if(p<=P/2)a[i][j]=a[i][j-1];
                else a[i][j]=a[i-1][j];
            }
            else a[i][j]=NewID();
        }
    }
    printf("%d\n",n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",a[i][j]);
        }
        puts("");
    }
	return 0;
}
