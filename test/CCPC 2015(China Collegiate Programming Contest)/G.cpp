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
char s[15][15];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int fa[N],sum[N];
int id(int x,int y){return (x-1)*9+y;}
int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
void Union(int x,int y){if(x==y)return;fa[x]=y;sum[y]+=sum[x];}
bool Check(){
	for(int i=1;i<=81;i++){fa[i]=i;sum[i]=0;}
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			if(s[i][j]!='o')continue;
			for(int k=0;k<4;k++){
				int x=i+dx[k],y=j+dy[k];
				if(s[x][y]=='.')sum[Find(id(i,j))]++;
				if(s[x][y]=='o')Union(Find(id(i,j)),Find(id(x,y)));
			}
		}
	}
	for(int i=1;i<=9;i++)for(int j=1;j<=9;j++)if(s[i][j]=='o'&&!sum[Find(id(i,j))])return 1;
	return 0;
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
	for(int Case=1;Case<=T;Case++){
		for(int i=1;i<=9;i++)scanf("%s",s[i]+1);
		for(int i=1;i<=9;i++)s[i][0]=s[i][10]=s[0][i]=s[10][i]='x';
		int flag=0;
		for(int i=1;i<=9;i++){
			for(int j=1;j<=9;j++){
				if(s[i][j]!='.')continue;
				s[i][j]='x';
				if(Check()){flag=1;break;}
				s[i][j]='.';
			}
			if(flag)break;
		}
		printf("Case #%d: ",Case);
		puts(flag?"Can kill in one move!!!":"Can not kill in one move!!!");
	}
	return 0;
}
