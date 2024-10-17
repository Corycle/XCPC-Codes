/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=305;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
char s[N];
int n,K,p[N][N],num[3];
int Pow(int x,int y){int ans=1;while(y){if(y&1)ans=ans*x%n;x=x*x%n;y>>=1;}return ans;}
int Match(int x,int y){
    if(x==y)return x;
    if((x==0&&y==2)||(x==1&&y==0)||(x==2&&y==1))return x;
    return y;
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();K=read();scanf("%s",s);
    for(int i=0;i<n;i++)s[i]=(s[i]=='R'?0:(s[i]=='P'?1:2));
    for(int i=0;i<n;i++)p[i][0]=s[i];
    for(int j=1;j<=K;j++){
        int dlt=Pow(2,j-1);
        for(int i=0;i<n;i++){
            p[i][j]=Match(p[i][j-1],p[(i+dlt)%n][j-1]);
        }
    }
    putchar("RPS"[p[0][K]]);
	return 0;
}
