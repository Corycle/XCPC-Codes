#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,ans,a[3][N],p[3];
bool Check(int x,int y,int z){
	if(x>y)swap(x,y);
	if(x>z)swap(x,z);
	if(y>z)swap(y,z);
	return y==x+1&&z==x+2;
}
int main(){
	n=read();
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			a[i][j]=read();
		}
	}
	m=read();
	for(int i=1;i<=m;i++){
		for(int j=0;j<3;j++){
			p[j]=(p[j]+read())%n;
		}
		int x=a[0][p[0]],y=a[1][p[1]],z=a[2][p[2]];
		if(x==y&&x==z)ans+=200;
		else if(x==y||x==z||y==z)ans+=100;
		else if(y==x+1&&z==x+2)ans+=200;
		else if(Check(x,y,z))ans+=100;
	}
	printf("%d\n",ans);
	return 0;
}
