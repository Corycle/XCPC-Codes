/*========Corycle========*/
#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int N=55;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m;
double ans,E[N][N],a[N][N];
double Gauss(){
	double ans=1;
	for(int i=1;i<n;i++){
		int t=i;
		for(int j=i;j<n;j++)if(abs(a[j][i])>abs(a[t][i]))t=j;
		for(int j=i;j<n;j++)swap(a[i][j],a[t][j]);
		for(int j=i+1;j<n;j++){
			double dlt=a[j][i]/a[i][i];
			for(int k=i;k<n;k++)a[j][k]-=a[i][k]*dlt;
		}
		ans*=a[i][i];
	}
	return ans;
}
int main(){
	n=read();
	ans=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%lf",&E[i][j]);
			if(i==j)continue;
			if(abs(E[i][j])<eps)E[i][j]=eps/2;
			if(abs(E[i][j]-1)<eps)E[i][j]=1-eps/2;
			if(i<j)ans*=1-E[i][j];
			a[i][j]-=E[i][j]/(1-E[i][j]);
			a[i][i]+=E[i][j]/(1-E[i][j]);
		}
	}
	printf("%.10lf",abs(ans*Gauss()));
	return 0;
}
