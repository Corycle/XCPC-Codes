#include<bits/stdc++.h>
using namespace std;
pair<int,int> bd[1000];
bool vis[1000];
int dis(pair<int,int> a,pair<int,int> b){
	return (abs(a.first-b.first)+abs(a.second-b.second));
}
void printmap(){
}
int x,y;
int main(){
	for(int i=1;i<=50;++i) {
		bd[i]=make_pair(i,50);
		if(i%5==0) vis[i]=true;
	}
	for(int i=1;i<50;++i) {
		bd[50+i]=make_pair(50,i);
		if(i%5==0) vis[50+ i]=true;
	}
	cin>>x>>y;
	if(x==0&&y==0) exit(0);
	for(int i=1;i<=10;++i){
		cout<<5*i<<' '<<50<<endl;
		cin>>x>>y;
		if(x==0&&y==0) exit(0);
	} 
	for(int i=1;i<10;++i){
		cout<<50<<' '<<5*i<<endl;
		cin>>x>>y;
		if(x==0&&y==0) exit(0);
	}
	//s_x s_y <= 39
	for(int i=1;i<=79;++i){
		printmap(); 
		int aim = -1, mindis = 1000000000;
		for(int k=1;k<=99;++k){
			if(vis[k]) continue;
			if(dis(bd[k],make_pair(x,y))<mindis) aim=k,mindis=dis(bd[k],make_pair(x,y));
		}
		vis[aim] = true;
//		cout<<"aim="<<aim<<endl;
		cout<<bd[aim].first<<' '<<bd[aim].second<<endl;
		cin>>x>>y;
		if(x==0&&y==0) exit(0);
	}
	int l = 1, r = 49, mid;
	while(l<=r){
		mid = (l+r)/2;
		for(int i=1;i<=49;++i){
			cout<<mid<<' '<<i<<endl;
			cin>>x>>y;
			if(x==0&&y==0) exit(0);
		}
		if(x<mid) r = mid - 1;
		else l = mid + 1;
	} 
//	while(1);
} 
