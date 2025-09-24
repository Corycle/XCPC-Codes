#include<bits/stdc++.h>
using namespace std;
void work(){
	int n,m;
	cin>>n>>m;
	int x = (n+1)/2;
	int y = m - x;
	int ans = 2 * min(x,y) + 1;
	cout<<ans<<"\n";
}
int main(){
	int T;cin>>T;
	while(T--) work();
}
