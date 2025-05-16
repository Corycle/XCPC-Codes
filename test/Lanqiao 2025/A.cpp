#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int cnt,vis[N],prime[N];
int main(){
	for(int i=2;i<N;i++){
		if(!vis[i])prime[++cnt]=i;
		for(int j=1;j<=cnt&&1ll*i*prime[j]<N;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
	cout<<prime[2025]<<endl;
	return 0;
}
