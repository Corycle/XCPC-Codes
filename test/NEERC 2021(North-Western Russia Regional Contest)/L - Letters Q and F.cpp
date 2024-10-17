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
int n,m,Q,F;
char s[N][N];
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int j=1;j<=m-2;j++){
		for(int i=1;i<=n-4;i++){
			if(s[i][j]=='#'&&s[i][j+1]=='#'&&s[i][j+2]=='#'&&s[i+1][j]=='#'&&s[i+2][j]=='#'&&s[i+2][j+1]=='#'&&s[i+3][j]=='#'&&s[i+4][j]=='#'){
				s[i][j]=s[i][j+1]=s[i][j+2]=s[i+1][j]=s[i+2][j]=s[i+2][j+1]=s[i+3][j]=s[i+4][j]='.';
				F++;
			}
			if(s[i][j]=='#'&&s[i][j+1]=='#'&&s[i][j+2]=='#'&&s[i+1][j]=='#'&&s[i+1][j+2]=='#'&&s[i+2][j]=='#'&&s[i+2][j+1]=='#'&&s[i+2][j+2]=='#'&&s[i+3][j+2]=='#'&&s[i+2][j+2]=='#'){
				s[i][j]=s[i][j+1]=s[i][j+2]=s[i+1][j]=s[i+1][j+2]=s[i+2][j]=s[i+2][j+1]=s[i+2][j+2]=s[i+3][j+2]=s[i+2][j+2]='.';
				Q++;
			}
		}
	}
	printf("%d %d\n",Q,F);
	return 0;
}
