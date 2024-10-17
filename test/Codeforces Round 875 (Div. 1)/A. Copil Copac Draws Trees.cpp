/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fst first
#define scd second
#define pii pair<int,int>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,Ans;
vector<pii>G[N];
void DFS(int x,int fa,int pre,int Answer){
    for(auto e:G[x]){
        if(fa==e.fst)continue;
        DFS(e.fst,x,e.scd,pre<e.scd?Answer:Answer+1);
    }
    Ans=max(Ans,Answer);
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
	while(T--){
        Ans=0;
		n=read();
        for(int i=1;i<n;i++){
            int x=read(),y=read();
            G[x].push_back(mp(y,i));
            G[y].push_back(mp(x,i));
        }
        DFS(1,0,0,1);
        printf("%d\n",Ans);
        for(int i=1;i<=n;i++)G[i].clear();
	}
	return 0;
}
