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
int n,m,pos[N],f[N],P[N][M];
int GetMin(int x,int L){
	int ans=f[L];
	for(int i=M-1;i>=0;i--){
		if(x-(1<<i)>=L){ans=min(ans,P[x][i]);x-=(1<<i);}
	}
	return ans;
}
int sum[N];
bool cmp(int x,int y){return sum[x]<sum[y];}
struct Trie_Tree{
	int root,tot,ch[N][M],pre[N],tag[N];
	void Init(){root=tot=1;}
	void Insert(){
		int x=root,len=strlen(s+1);sum[x]++;
		for(int i=1;i<=len;i++){
			int c=s[i]-'a';
			if(!ch[x][c])ch[x][c]=++tot;
			x=ch[x][c];
			sum[x]++;
		}
		tag[x]=1;
	}
	void DFS(int x){
//		sort(ch[x],ch[x]+26,cmp);
		for(int i=0;i<M;i++)if(ch[x][i])DFS(ch[x][i]);
		for(int i=M-1;i>=0;i--)if(ch[x][i]){pre[ch[x][i]]=x;break;}//pre[right_son]=x;
		if(tag[x])pos[++pos[0]]=x;
	}
	void Solve(int x,int i){
		while(x){
			if(sum[x]<m)f[i]=min(f[i],GetMin(i-1,i-sum[x])+1);
			else{f[i]=min(f[i],GetMin(i-1,i-m)+1);break;}
			x=pre[x];
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
	memset(P,0x3f,sizeof(P));
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+1;
		tree.Solve(pos[i],i);
		P[i][0]=f[i];
		for(int j=1;j<M;j++)if(i>=(1<<j))P[i][j]=min(P[i][j-1],P[i-(1<<(j-1))][j-1]);
	}
	printf("%d",f[n]);
	return 0;
}
