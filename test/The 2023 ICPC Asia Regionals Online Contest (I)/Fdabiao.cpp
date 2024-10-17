#include<bits/stdc++.h>
using namespace std;
int F[10005][10005];
bool f(int x,int y){
	if(x&&y){
		return true;
	}
	if(F[x][y]==1){
		return true;
	}
	if(F[x][y]==2){
		return false;
	}
	if(x==0&&y==0) {F[x][y]=2;return false;}
	if(x==1&&y==0) {F[x][y]=2;return false;}
	if(x==0&&y==1) {F[x][y]=2;return false;}
	for(int k=1;x-2*k>=0;++k){
		if(!f(x-2*k,y+k)) {F[x][y]=1;return true;}
	}
	for(int k=1;y-2*k>=0;++k){
		if(!f(x+k,y-2*k)) {F[x][y]=1;return true;}
	}
	for(int k=1;x-k>=0&&y-k>=0;++k){
		if(!f(x-k,y-k)) {F[x][y]=1;return true;}
	}
	for(int k=1;x-y-2*k>=0;++k){
		if(!f(x-y-2*k,k)) {F[x][y]=1;return true;}
	}
	for(int k=1;y-x-2*k>=0;++k){
		if(!f(k,y-x-2*k)) {F[x][y]=1;return true;}
	}
	F[x][y]=2;
	return false;
}
int main(){
	for(int i=0;i<=1000;++i){
//		if(f(0,i)) cout<<(i&(-i))<<' ';
		if(!f(0,i)) cout<<(i&(-i))<<' ';	
	}
}
