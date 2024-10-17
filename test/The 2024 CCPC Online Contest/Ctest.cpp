#include<bits/stdc++.h>
using namespace std;
int f[150000],a[150000];
int main(){
	for(int i=1;i<=1500;++i) f[i]=0;
	f[0]=1;
	for(int i=2;i<=600;++i){
		a[i]=i*(i-1)/2;
	}
	for(int i=2;i<=600;++i){
		for(int j=1500;j>=a[i];--j){
			f[j]+=f[j-a[i]];	
		}
	}
	for(int i=1;i<=100;++i) cout<<f[i];
}
