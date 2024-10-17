/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e6+5;
const int M=26;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n;
ll Ans;
char s[N];
struct SAM{
	vector<int>G[N];
	int tot,lst,root;
	int ch[N][M],fa[N],len[N],sum[N];
	void Init(){tot=lst=root=1;}
	void Insert(int c){
		int x=lst,fx=++tot;len[fx]=len[x]+1;
		while(x&&!ch[x][c]){ch[x][c]=fx;x=fa[x];}
		if(!x)fa[fx]=root;
		else{
			int y=ch[x][c];
			if(len[y]==len[x]+1)fa[fx]=y;
			else{
				int fy=++tot;len[fy]=len[x]+1;
				fa[fy]=fa[y];fa[y]=fa[fx]=fy;
				memcpy(ch[fy],ch[y],sizeof(ch[fy]));
				while(x&&ch[x][c]==y){ch[x][c]=fy;x=fa[x];}
			}
		}
		sum[lst=fx]=1;
	}
	void DFS(int x){
		for(auto y:G[x]){DFS(y);sum[x]+=sum[y];}
		if(sum[x]>1)Ans=max(Ans,1ll*len[x]*sum[x]);
	}
	void Solve(){
		for(int i=2;i<=tot;i++)G[fa[i]].push_back(i);
		DFS(root);
	}
}sam;
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	scanf("%s",s+1);n=strlen(s+1);sam.Init();
	for(int i=1;i<=n;i++)sam.Insert(s[i]-'a');
	sam.Solve();
	printf("%lld\n",Ans);
	return 0;
}
