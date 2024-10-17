#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,Answer;
int a[N],b[N],fa1[N],fa2[N];
vector<int>G1[N],G2[N];
unordered_map<int,int>S1[N],S2[N];
void DFS1(int x){
	for(auto y:G1[x]){
		if(y==fa1[x])continue;
		fa1[y]=x;
		DFS1(y);
		S1[x][a[y]]=y;
	}
}
void DFS2(int x){
	for(auto y:G2[x]){
		if(y==fa2[x])continue;
		fa2[y]=x;
		DFS2(y);
		S2[x][b[y]]=y;
	}
}
void DFS3(int p1,int p2,int depth){
	Answer=max(Answer,depth);
	for(auto x:G1[p1]){
		if(x==fa1[p1])continue;
		if(!S2[p2][a[x]])continue;
		DFS3(S1[p1][a[x]],S2[p2][a[x]],depth+1);
	}
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)b[i]=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		G1[x].push_back(y);
		G1[y].push_back(x);
	}
	for(int i=1;i<m;i++){
		int x=read(),y=read();
		G2[x].push_back(y);
		G2[y].push_back(x);
	}
	if(a[1]!=b[1]){puts("0");return 0;}
	DFS1(1);DFS2(1);DFS3(1,1,1);
	printf("%d\n",Answer);
	return 0;
}
