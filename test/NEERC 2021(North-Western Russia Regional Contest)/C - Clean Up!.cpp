#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=3e5+5;
const int M=26;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
char s[N];
int n,m,Ans,pos[N],sum[N];
bool cmp(int x,int y){return sum[x]>sum[y];}
struct Trie_Tree{
	int root,tot,ch[N][M],tag[N];
	void Init(){root=tot=1;}
	void Insert(){
		int x=root,len=strlen(s+1);
		for(int i=1;i<=len;i++){
			int c=s[i]-'a';
			if(!ch[x][c])ch[x][c]=++tot;
			x=ch[x][c];
		}
		tag[x]=1;
	}
	void DFS(int x){
		sum[x]=tag[x];
		for(int i=0;i<M;i++){
			if(!ch[x][i])continue;
			DFS(ch[x][i]);
			sum[x]+=sum[ch[x][i]];
		}
		if(sum[x]>m){
			sort(ch[x],ch[x]+26,cmp);
			for(int i=0;i<M;i++){
				sum[x]-=sum[ch[x][i]];
				Ans++;
				if(sum[x]<=m)break;
			}
		}
	}
}tree;
int main(){
	n=read();m=read();
	tree.Init();
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		tree.Insert();
	}
	tree.DFS(1);
	if(sum[1])Ans++;
	printf("%d\n",Ans);
	return 0;
}
