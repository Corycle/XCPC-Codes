#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,ans;
char a[N][N];
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			ans+=(a[i][j]=='c'&&a[i][j+1]=='c'&&a[i+1][j]=='p'&&a[i+1][j+1]=='c');
		}
	}
	printf("%d\n",ans);
	return 0;
}
