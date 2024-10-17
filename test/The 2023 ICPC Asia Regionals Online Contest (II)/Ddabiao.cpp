#include<bits/stdc++.h>
using namespace std;
int a[100][100],p[100],q[100];
int main(){
	int n=10,ans=0;
	srand(time(0));
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) a[i][j]=rand()%100;
	for(int i=1;i<=n;++i) p[i]=i,q[i]=i;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int k=1;k<=n;++k){
				if(a[j][p[j]]+a[k][p[k]]>a[j][p[k]]+a[k][p[j]]){
					swap(p[j],p[k]);
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			cout<<a[i][j]<<' ';
		cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=n;++i) cout<<p[i]<<' ',ans+=a[i][p[i]];
	cout<<endl<<ans<<endl;
	for(int i=1;i<=3628800;++i){
		int res=0;
		for(int i=1;i<=n;++i) res+=a[i][q[i]];
		if(res<ans) ans=res;
		next_permutation(q+1,q+n+1);
	}
	cout<<endl<<ans<<endl;
}
