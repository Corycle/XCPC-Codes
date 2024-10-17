#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define fst first
#define scd second
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e5+5;
const int M=5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
map<pii,int>Ans;
int P[N];
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int Rand(int maxn){return (1ll*rand()*rand()+rand())%maxn+1;}
int Pow(int x,int y,int Mod){int ans=1;while(y){if(y&1)ans=1ll*ans*x%Mod;x=1ll*x*x%Mod;y>>=1;}return ans;}
bool Miller_Rabin(int n){
	if(n==2)return true;
	if(n<2||!(n&1))return false;
	int m=n-1,k=0;while(!(m&1)){k++;m>>=1;}
	for(int i=1;i<=M;i++){
		int a=Rand(n-1),x=Pow(a,m,n),y=0;
		for(int j=1;j<=k;j++){
			y=x;x=1ll*x*x%n;
			if(x==1&&y!=1&&y!=n-1)return false;
		}
		if(x!=1)return false;
	}
	return true;
}
int Pollard_rho(int n,int c){
	int x=Rand(n-1),y=x,z=1,i=1,k=2;
	while(1){
		i++;
		x=(1ll*x*x+c)*n;
		z=1ll*z*abs(y-x)%n;
		if(i%127==0||i==k){
			int d=gcd(z,n);
			if(d>1)return d;
			if(i==k){y=x;k<<=1;}
		}
	}
}
void Solve(int n,int c){
	if(n==1)return;
	if(Miller_Rabin(n)){P[++P[0]]=n;return;}
	int p=n;while(p==n)p=Pollard_rho(n,c--);
	Solve(p,c);Solve(n/p,c);
}
int DFS(int a,int b){
	if(a>b)swap(a,b);
	if(a==1)return 0;
	if(b-a==1)return a-1;
	if(Ans[mp(a,b)])return Ans[mp(a,b)];
	int ans=a-1;
	for(int i=1;i<=P[0];i++){
		int x=P[i];
		if((b-a)%x)continue;
		if(a%x==0){
			ans=min(ans,DFS(a/x,b/x)+1);
		}
		else{
			int t=a%x;
			if(a!=t&&t<=x-t)ans=min(ans,DFS((a-t)/x,(b-t)/x)+t+1);
			if(x-t<=t)ans=min(ans,DFS((a+x-t)/x,(b+x-t)/x)+x-t+1);
		}
	}
	return Ans[mp(a,b)]=ans;
}
int main(){
	int T=read();
	while(T--){
		int a=read(),b=read();
		P[0]=0;
		Solve(abs(b-a),10000007);
		sort(P+1,P+P[0]+1);
		P[0]=unique(P+1,P+P[0]+1)-P-1;
		printf("%d\n",DFS(a,b));
	}
    return 0;
}
