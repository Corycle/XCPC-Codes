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
int n,m,a[N][N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        n=read();m=read();
        if(!(m&1)){
            int cnt=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++)a[i][j]=++cnt;
            }
        }
        else if(!(n&1)){
            int cnt=0;
            for(int j=1;j<=m;j++){
                for(int i=1;i<=n;i++)a[i][j]=++cnt;
            }
        }
        else{
            int t=1;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++)a[i][j]=(t-1)*m+j;
                t+=2;
                if(t>n)t=2;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)printf("%d ",a[i][j]);
            puts("");
        }
        puts("");
    }
	return 0;
}
