/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
char s[6][6];
int a[6][6][6];
int b[6][6]={
{},
{0,1,1,2,2},
{0,1,1,2,2},
{0,3,3,4,4},
{0,3,3,4,4}
};
bool DFS(int x,int y){
	if(x==4&&y==5){
		for(int i=1;i<=4;i++)printf("%s\n",s[i]+1);
		return 1;
	}
	if(y==5)return DFS(x+1,1);
	if(s[x][y]!='*')return DFS(x,y+1);
	for(int c=1;c<=4;c++){
		if(a[x][y][c])continue;
		for(int k=1;k<=4;k++){a[x][k][c]++;a[k][y][c]++;}
		for(int i=1;i<=4;i++)for(int j=1;j<=4;j++)if(b[x][y]==b[i][j])a[i][j][c]++;
		s[x][y]='0'+c;
		if(DFS(x,y+1))return 1;
		s[x][y]='*';
		for(int i=1;i<=4;i++)for(int j=1;j<=4;j++)if(b[x][y]==b[i][j])a[i][j][c]--;
		for(int k=1;k<=4;k++){a[x][k][c]--;a[k][y][c]--;}
	}
	return 0;
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
	for(int Case=1;Case<=T;Case++){
		for(int i=1;i<=4;i++)scanf("%s",s[i]+1);
		memset(a,0,sizeof(a));
		for(int i=1;i<=4;i++){
			for(int j=1;j<=4;j++){
				if(s[i][j]=='*')continue;
				int c=s[i][j]-'0';
				for(int k=1;k<=4;k++){a[i][k][c]++;a[k][j][c]++;}
				for(int x=1;x<=4;x++)for(int y=1;y<=4;y++)if(b[i][j]==b[x][y])a[x][y][c]++;
			}
		}
//		for(int i=1;i<=4;i++){
//			for(int j=1;j<=4;j++){
//				if(s[i][j]=='*'){
//					cout<<i<<" "<<j<<":::"<<endl;
//					for(int k=1;k<=4;k++)cout<<a[i][j][k]<<" ";cout<<endl;
//				}
//			}
//		}
		printf("Case #%d:\n",Case);
		DFS(1,1);
	}
	return 0;
}
