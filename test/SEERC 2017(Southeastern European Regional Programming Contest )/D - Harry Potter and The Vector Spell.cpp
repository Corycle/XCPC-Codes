/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
#define set_it set<int>::iterator
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
set<int>a[N];
int n,m,ans,p[N],pos[N],vis[N];
bool cmp(int x,int y){return *a[x].begin()!=*a[y].begin()?*a[x].begin()<*a[y].begin():a[x].size()<a[y].size();}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		p[i]=i;
		int num=read();
		if(!num){n--;i--;continue;}
		for(int j=1;j<=num;j++)a[i].insert(read());
	}
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++){
		int t=*a[p[i]].begin();
		if(!pos[t]){pos[t]=p[i];vis[p[i]]=1;ans++;}
	}
	for(int i=1;i<=n;i++){
		if(vis[p[i]])continue;
		while(!a[p[i]].empty()){
			int t=*a[p[i]].begin();
			if(!pos[t]){pos[t]=p[i];break;}
			for(auto tmp:a[pos[t]]){
				set_it P=a[p[i]].lower_bound(tmp);
				if(P==a[p[i]].end()||*P!=tmp)a[p[i]].insert(tmp);
				else a[p[i]].erase(tmp);
			}
		}
		if(!a[p[i]].empty())ans++;
	}
	printf("%d",ans);
	return 0;
}
