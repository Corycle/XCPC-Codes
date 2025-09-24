#include<bits/stdc++.h>
using namespace std;
pair<int,int> bd[1000];
bool vis[1000];
bool a[1005][1005];
int num;
int dis(pair<int,int> a,pair<int,int> b){
	return max(abs(a.first-b.first),abs(a.second-b.second));
}
int x,y;
int main(){
	for(int i=1;i<=125;++i) {
		bd[++num]=make_pair(i,126-i);
		bd[++num]=make_pair(i,127-i);
	}
	cin>>x>>y;
	if(x==0&&y==0) return (0);
	//s_x s_y <= 39
	for(int i=1;i<=num;++i){
		int aim = -1, mindis = 1000000000;
		for(int k=1;k<=num;++k){
			if(vis[k]) continue;
			if(dis(bd[k],make_pair(x,y))<mindis) aim=k,mindis=dis(bd[k],make_pair(x,y));
		}
		vis[aim] = true;
//		cout<<"aim="<<aim<<endl;
		cout<<bd[aim].first<<' '<<bd[aim].second<<endl;
		a[bd[aim].first][bd[aim].second]=1;
		cin>>x>>y;
		if(x==0&&y==0) return (0);
	}
	int l = 1, r = 124, mid;
	while(l<=r){
		mid = (l+r)/2;
		for(int i=1;i<=129;++i){
			if(a[mid][i])break;
			cout<<mid<<' '<<i<<endl;
			cin>>x>>y;
			if(x==0&&y==0) return (0);
		}
		if(x<mid) r = mid - 1;
		else l = mid + 1;
	} 
	while(1);
}

