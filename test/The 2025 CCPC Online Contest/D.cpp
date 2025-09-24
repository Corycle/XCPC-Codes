#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fst first
#define scd second
#define mp make_pair
using namespace std;
const int N=5e5+5;
const int M=16;
const ll Mul=131;
const ll Mod=(1ll<<61)-1;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,cnt,len[N],f[N][M],g[N][M],sum[N];
bool vis[N][M];
ll h1[N],h2[N],h[M],p[N];
char s[N],t[N],tmp[N];
void Prepare(){
	int num=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='*'&&s[i-1]=='*')continue;
		tmp[++num]=s[i];
	}
	for(int i=1;i<=num;i++)s[i]=tmp[i];
	n=num;
	p[0]=1;
	for(int i=1;i<N;i++)p[i]=(__int128)p[i-1]*Mul%Mod;
}
ll GetHash2(int l,int r){
	return (((__int128)h2[r]-(__int128)h2[l-1]*p[r-l+1])%Mod+Mod)%Mod;
}
int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	Prepare();
	if(n==1&&s[1]=='*'){
		printf("%lld\n",1ll*m*(m+1)/2);
		return 0;
	}
	if(s[1]=='*'){
		cnt++;
	}
	for(int i=1;i<=n;i++)h1[i]=((__int128)h1[i-1]*Mul+s[i])%Mod;
	for(int i=1;i<=m;i++)h2[i]=((__int128)h2[i-1]*Mul+t[i])%Mod;
	ll hash=0,Len=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='*'){
			hash=0;
			Len=0;
		}
		else{
			hash=((__int128)hash*Mul+s[i])%Mod;
			Len++;
			if(i==n||s[i+1]=='*'){
				cnt++;
				h[cnt]=hash;
				len[cnt]=Len;
			}
		}
	}
	if(s[n]=='*'){
		cnt++;
	}
//	for(int i=1;i<=cnt;i++)cout<<h[i]<<" ";cout<<endl;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt;j++){
			if(i>=len[j]&&GetHash2(i-len[j]+1,i)==h[j])vis[i][j]=1;
		}
	}
//	for(int j=1;j<=cnt;j++){
//		for(int i=1;i<=m;i++)cout<<vis[i][j];cout<<endl;
//	}
	for(int i=1;i<=m;i++){
		sum[i]=sum[i-1]+vis[i][1];
		for(int j=2;j<=cnt;j++){
			if(vis[i][j]){
				if(j==2)f[i][j]=i-len[j]+1;
				else f[i][j]=g[i-len[j]][j-1];
				g[i][j]=max(g[i-1][j],f[i][j]);
			}
			else{
				f[i][j]=0;
				g[i][j]=g[i-1][j];
			}
		}
//		cout<<i<<": "<<endl;
//		for(int j=1;j<=cnt;j++)cout<<f[i][j]<<" ";cout<<endl;
//		for(int j=1;j<=cnt;j++)cout<<g[i][j]<<" ";cout<<endl;
	}
	ll ans=0;
	if(cnt==1){
		ans=sum[m];
		printf("%lld\n",ans);
		return 0;
	}
	if(cnt==2){
		if(len[1]==0){
			for(int i=1;i<=m;i++){
				if(vis[i][2]){
					ans+=i-len[2]+1;
				}
			}
		}
		else if(len[2]==0){
			for(int i=1;i<=m;i++){
				if(vis[i][1]){
					ans+=m-i+1;
				}
			}
		}
		else {
			for(int i=1;i<=m;i++){
				if(vis[i][2]){
					ans+=sum[i-len[2]];
				}
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=1;i<=m;i++){
		if(vis[i][cnt]){
//			cout<<i<<" :: "<<endl;
			int x=i-len[cnt];
			int p=g[x][cnt-1];
//			cout<<x<<" "<<p<<endl;
			if(len[1]==0){
				ans+=sum[p];
			}
			else{
				ans+=sum[p-1];
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
