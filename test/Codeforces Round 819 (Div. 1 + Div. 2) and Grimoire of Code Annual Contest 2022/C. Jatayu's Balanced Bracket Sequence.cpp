/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
char s[N];
int n,m,fa[N],pos[N];
int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int Case=read();
	while(Case--){
		n=read();m=n*2;
		scanf("%s",s+1);
		for(int i=1;i<=m;i++){fa[i]=i;pos[i]=0;}
		int num=0;
		for(int i=1;i<=m;i++){
			if(s[i]=='('){
				if(s[i-1]==')')fa[Find(i)]=Find(i-1);
				pos[++num]=i;
			}
			else{
				if(pos[num])fa[Find(i)]=Find(pos[num]);
				pos[num--]=0;
			}
		}
		int ans=0;
		for(int i=1;i<=m;i++)ans+=(Find(i)==i);
		printf("%d\n",ans);
	}
	return 0;
}
