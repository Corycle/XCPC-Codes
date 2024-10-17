#include<bits/stdc++.h>
#define ll long long
#define fst first
#define scd second
using namespace std;
const int N=4e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
map<int,int>ID[N];
int n,m,T,tot,pre[N];
struct Ques{int op,x,y;}Q[N];
struct Tree{int fa,aux,val,ans,ians,rev,ch[2];};
struct Link_Cut_Tree{
	Tree t[N];
	void Init(int x,int y){t[x].val=t[x].ans=y;}
	void Reverse(int x){t[x].rev^=1;swap(t[x].ch[0],t[x].ch[1]);}
	void Pushup(int x){t[x].ans=t[x].val+t[x].ians+t[t[x].ch[0]].ans+t[t[x].ch[1]].ans;}
	void Pushdown(int x){if(t[x].rev){t[x].rev=0;Reverse(t[x].ch[0]);Reverse(t[x].ch[1]);}}
	void Rotate(int x){
		int y=t[x].fa,z=t[y].fa,l=(x!=t[y].ch[0]),r=l^1;
		if(!t[y].aux){t[x].aux=0;t[y].aux=1;}
		else t[z].ch[y!=t[z].ch[0]]=x;
		t[x].fa=z;t[y].fa=x;t[t[x].ch[r]].fa=y;
		t[y].ch[l]=t[x].ch[r];t[x].ch[r]=y;
		Pushup(y);Pushup(x);
	}
	void Splay(int x){
		Pushdown(x);
		while(t[x].aux){
			int y=t[x].fa,z=t[y].fa;
			if(t[y].aux)Pushdown(z);
			Pushdown(y);Pushdown(x);
			if(t[y].aux){
				if((x==t[y].ch[0])^(y==t[z].ch[0]))Rotate(x);
				else Rotate(y);
			}
			Rotate(x);
		}
	}
	void Access(int x){
		int y=0;
		while(x){
			Splay(x);
			t[t[x].ch[1]].aux=0;
			t[x].ians+=t[t[x].ch[1]].ans;
			t[x].ch[1]=y;
			t[t[x].ch[1]].aux=1;
			t[x].ians-=t[t[x].ch[1]].ans;
			t[y].fa=x;Pushup(x);y=x;x=t[x].fa;
		}
	}
	void Evert(int x){Access(x);Splay(x);Reverse(x);}
	void Split(int x,int y){Evert(x);Access(y);Splay(y);}
	void Link(int x,int y){Split(x,y);t[x].fa=y;t[y].ians+=t[x].ans;Pushup(y);}
	void Cut(int x,int y){Split(x,y);t[x].fa=t[x].aux=t[y].ch[0]=0;Pushup(y);}
	int Query(int x){Evert(x);return t[x].ans;}
}tree;
int main(){
	n=read();m=read();T=read();
	for(int i=1;i<=n;i++){ID[i][1]=++tot;ID[i][m]=++tot;tree.Init(tot,i);}
	for(int i=1;i<=T;i++){
		Q[i].op=read();Q[i].x=read();
		if(Q[i].op==1){
			Q[i].y=read();
			if(!ID[Q[i].x][Q[i].y])ID[Q[i].x][Q[i].y]=++tot;
			if(!ID[Q[i].x+1][Q[i].y])ID[Q[i].x+1][Q[i].y]=++tot;
		}
	}
	for(int i=1;i<=n;i++){
		int lst=0;
		for(auto p:ID[i]){
			if(!lst)lst=p.scd;
			else{
				tree.Link(lst,p.scd);
				pre[p.scd]=lst;
				lst=p.scd;
			}
		}
	}
	for(int i=1;i<=T;i++){
		if(Q[i].op==1){
			int x=Q[i].x,y=Q[i].y;
			if(y==1)swap(ID[x][y],ID[x+1][y]);
			else{
				int p1=pre[ID[x][y]];
				int p2=pre[ID[x+1][y]];
				tree.Cut(p1,ID[x][y]);
				tree.Cut(p2,ID[x+1][y]);
				tree.Link(p1,ID[x+1][y]);
				tree.Link(p2,ID[x][y]);
				swap(pre[ID[x][y]],pre[ID[x+1][y]]);
				swap(ID[x][y],ID[x+1][y]);
			}
		}
		else printf("%d\n",tree.Query(ID[Q[i].x][1]));
	}
	return 0;
}
