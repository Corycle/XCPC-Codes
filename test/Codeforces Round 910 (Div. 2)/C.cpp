/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=105;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,K,ans1[N][N],ans2[N][N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        n=read();m=read();K=read();
        if(K<n+m-2){
            puts("NO");
            continue;
        }
        K-=(n+m-2);
        if(K&1){
            puts("NO");
            continue;
        }
        int t=0;
        for(int i=1;i<m;i++){
            t^=1;
            ans1[1][i]=t;
        }
        for(int i=1;i<n;i++){
            t^=1;
            ans2[i][m]=t;
        }
        if(K%4==0){
            ans1[1][1]=ans1[2][1]=1;
            ans2[1][1]=ans2[1][2]=0;
        }
        else{
            ans1[1][1]=ans1[2][1]=0;
            ans2[1][1]=ans2[1][2]=1;
        }
        puts("YES");
        for(int i=1;i<=n;i++){
            for(int j=1;j<m;j++){
                putchar(ans1[i][j]?'R':'B');
                putchar(' ');
            }
            puts("");
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=m;j++){
                putchar(ans2[i][j]?'R':'B');
                putchar(' ');
            }
            puts("");
        }
    }
	return 0;
}
