/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=1e9+7;
const int N=1e5+5;
const int M=27;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
char s[N],t[N];
int n,m,Ans,top;
int a[M],nxt[N][M],vis[N],g[N],st[N];
int mod(int x){return x>=Mod?x-Mod:x;}
struct Node{int pos,ans;};
vector<Node>f[N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=26;i++)a[i]=read();
	scanf("%s%s",s+1,t+1);
	for(int i=1;i<=n;i++)s[i]=s[i]-'A'+1;
	for(int i=1;i<=m;i++)t[i]=t[i]-'A'+1;
	for(int i=1;i<=26;i++)nxt[m+1][i]=m+1;
	for(int i=m;i>=1;i--){
		for(int j=1;j<=26;j++)nxt[i][j]=nxt[i+1][j];
		nxt[i][t[i]]=i;
	}
	f[nxt[1][s[1]]].push_back((Node){1,1});
	for(int i=1;i<=m;i++){
		top=0;
		for(auto tmp:f[i]){
			if(vis[tmp.pos]!=i){vis[tmp.pos]=i;g[tmp.pos]=0;st[++top]=tmp.pos;}
			if(tmp.pos==n)Ans=mod(Ans+tmp.ans);
			g[tmp.pos]=mod(g[tmp.pos]+tmp.ans);
		}
		f[i].clear();
		for(int j=1;j<=top;j++){
			int p=nxt[i+a[s[st[j]]]+1][s[st[j]+1]];
			if(p<=m)f[p].push_back((Node){st[j]+1,g[st[j]]});
			p=nxt[i+1][s[st[j]]];
			if(p<=m)f[p].push_back((Node){st[j],g[st[j]]});
		}
	}
	printf("%d\n",Ans);
	return 0;
}
/*
2 10
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
AB
ABBBBABBBB
*/
