#include<bits/stdc++.h>
#define ll long long
#define fst first
#define scd second
#define mp make_pair
#define pii pair<int,int>
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
int n,m,pos[N],f[N];
struct Heap{
	int num;
	priority_queue<pii>q1,q2;
	void Insert(pii x){q1.push(x);num++;}
	void Delete(pii x){q2.push(x);num--;}
	int Size(){return num;}
	pii Top(){
		while(!q1.empty()&&!q2.empty()&&q1.top()==q2.top()){q1.pop();q2.pop();}
		return q1.top();
	}
}Q;
struct Trie{
	int root,tot;
	int ch[N][M],fa[N],sum[N],pre[N],tag[N];
	void Init(){root=tot=1;}
	void Insert(){
		int x=root,len=strlen(s+1);sum[x]++;
		for(int i=1;i<=len;i++){
			int c=s[i]-'a';
			if(!ch[x][c])fa[ch[x][c]=++tot]=x;
			x=ch[x][c];
			sum[x]++;
		}
		tag[x]=1;
	}
	void Prepare(){
		for(int i=1;i<=tot;i++){
			if(sum[i]<=m&&(sum[fa[i]]>m||i==1))Q.Insert(mp(sum[i],i));
		}
	}
	void Clear(int x){
//		cout<<"C: "<<x<<endl;
		sum[x]=0;
		for(int i=0;i<M;i++)if(sum[ch[x][i]])Clear(ch[x][i]);
	}
	void Delete(int x){
		cout<<"============"<<endl;
		cout<<x<<endl;
		int tmp=sum[x];
		Clear(x);
		for(int p=fa[x];p;p=fa[p])sum[p]-=tmp;
		for(int p=fa[x];p;p=fa[p]){
			if(sum[p]<=m&&(sum[fa[p]]>m||p==1))Q.Insert(mp(sum[p],p));
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
	tree.Prepare();
	int ans=0;
	while(Q.Size()){
		pii x=Q.Top();Q.Delete(x);
		if(tree.sum[x.scd]!=x.fst)continue;
		tree.Delete(x.scd);
		ans++;
//		system("pause");
	}
	printf("%d\n",ans);
	return 0;
}
