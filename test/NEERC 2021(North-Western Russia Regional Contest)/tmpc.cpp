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
int GetMin(int l,int r){
	int k=int(log(r-l+1)/log(2));
//	cout<<"GetMin: "<<l<<" "<<r<<endl;
//	for(int i=0;i<=n;i++)cout<<f[i]<<" ";cout<<endl;
//	cout<<k<<endl;
//	cout<<min(P[r][k],P[l+(1<<k)-1][k])<<endl;
//	cout<<endl;
	return min(P[r][k],P[l+(1<<k)-1][k]);
}
struct Trie_Tree{
	int root,tot;
	int ch[N][M],sum[N],pre[N],tag[N];
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
		for(int i=0;i<M;i++)if(ch[x][i])DFS(ch[x][i]);
		for(int i=M-1;i>=0;i--)if(ch[x][i]){pre[ch[x][i]]=x;break;}//pre[right_son]=x;
		if(tag[x])pos[++pos[0]]=x;
	}
	void Solve(int x,int i){
		while(x){
			if(sum[x]<m)f[i]=min(f[i],GetMin(i-sum[x],i-1)+1);
			else{f[i]=min(f[i],GetMin(i-m,i-1)+1);break;}
			x=pre[x];
		}
	}
	void Print(){
		cout<<"==============="<<endl;
		for(int i=1;i<=tot;i++){
			cout<<i<<"::: "<<pre[i]<<" :: "<<sum[i]<<" : ";
			for(int j=0;j<M;j++)cout<<ch[i][j]<<" ";cout<<endl;
		}
		cout<<"==============="<<endl;
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
//	tree.Print();
//	for(int i=1;i<=n;i++)cout<<pos[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+1;
		tree.Solve(pos[i],i);
		P[i][0]=f[i];
		for(int j=1;j<M;j++)if(i>=(1<<(j-1)))P[i][j]=min(P[i][j-1],P[i-(1<<(j-1))][j-1]);
//		cout<<f[i]<<" ";
	}
//	cout<<endl;
	printf("%d",f[n]);
	return 0;
}
