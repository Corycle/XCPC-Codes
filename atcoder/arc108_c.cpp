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
int n,m,cnt;
int h[N],val[N];
struct edge{int to,next,val;}d[N*2];
void Add(int x,int y,int z){d[++cnt]=(edge){y,h[x],z};h[x]=cnt;}
void DFS(int x,int fa,int pre){
    if(!val[x]){
        if(fa&&val[fa]!=pre)val[x]=pre;
        else{
            for(int i=h[x];i;i=d[i].next){
                int y=d[i].to;
                if(val[y]||d[i].val==pre)continue;
                val[x]=d[i].val;break;
            }
            if(!val[x])val[x]=(pre==1?2:1);
        }
    }
    for(int i=h[x];i;i=d[i].next){
        int y=d[i].to;
        if(val[y])continue;
        DFS(y,x,d[i].val);
    }
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();m=read();
    for(int i=1;i<=m;i++){
        int x=read(),y=read(),z=read();
        Add(x,y,z);Add(y,x,z);
    }
    DFS(1,0,0);
    for(int i=1;i<=n;i++)printf("%d\n",val[i]);
	return 0;
}
