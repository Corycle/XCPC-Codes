#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(0);
	int n,t;
	cin>>n>>t;
	int ans=2;
	for(int i=1;i<=n;++i)
	{
		int v;
		cin>>v;
		ans=max(ans,(v+t-1)/t);
	}
	cout<<ans;
    return 0;
}
