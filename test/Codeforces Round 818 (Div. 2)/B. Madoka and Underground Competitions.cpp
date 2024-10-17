/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=505;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,R,C,a[N][N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int Case=read();
	while(Case--){
		n=read();m=read();R=read();C=read();
		for(int i=1;i<=n;i++)a[R][i]=(abs(i-C)%m==0);
		for(int i=R-1;i>=1;i--){
			for(int j=1;j<=n;j++){
				int y=((j-1)%m+m)%m;if(!y)y=m;
				a[i][j]=a[i+1][y];
			}
		}
		for(int i=R+1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int y=((j+1)%m+m)%m;if(!y)y=m;
				a[i][j]=a[i-1][y];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)printf("%c",a[i][j]?'X':'.');
			puts("");
		}
	}
	return 0;
}
