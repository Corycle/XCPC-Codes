#include<bits/stdc++.h>
using namespace std;
int a[10][10]={
	{1,0,-1,0,-1,-1},
	{-1,-1,-1,0,-1,-1},
	{-1,-1,-1,-1,0,0},
	{-1,-1,-1,-1,-1,-1},
	{-1,-1,1,-1,-1,1},
	{-1,0,-1,-1,1,-1}
};
void Print(){
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			cout<<a[i][j];
		}
	}
	cout<<endl;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool Check(){
	for(int i=0;i<6;i++){
		int sum=0;
		for(int j=0;j<6;j++)sum+=a[i][j];
		if(sum!=3)return false;
		sum=0;
		for(int j=0;j<6;j++)sum+=a[j][i];
		if(sum!=3)return false;
	}
	for(int i=0;i<6;i++){
		for(int j=0;j+2<6;j++){
			if(a[i][j]==a[i][j+1]&&a[i][j]==a[i][j+2])return false;
			if(a[j][i]==a[j+1][i]&&a[j][i]==a[j+2][i])return false;
		}
	}
	for(int i=0;i<6;i++){
		for(int j=0;j<i;j++){
			int s1=0,s2=0;
			for(int k=0;k<6;k++){
				s1=(s1<<1)|a[i][k];
				s2=(s2<<1)|a[j][k];
			}
			if(s1==s2)return false;
			s1=0;s2=0;
			for(int k=0;k<6;k++){
				s1=(s1<<1)|a[k][i];
				s2=(s2<<1)|a[k][j];
			}
			if(s1==s2)return false;
		}
	}
	return true;
}
void DFS(int x,int y){
	if(y==6){DFS(x+1,0);return;}
	if(x==6){
		if(Check())Print();
		return;
	}
	if(a[x][y]!=-1)DFS(x,y+1);
	else{
		a[x][y]=0;
		DFS(x,y+1);
		a[x][y]=1;
		DFS(x,y+1);
		a[x][y]=-1;
	}
}
int main(){
	DFS(0,0);
	return 0;
}
/*
1 0 x 0 x x
x x x 0 x x
x x x x 0 0
x x x x x x
x x 1 x x 1
x 0 x x 1 x
*/
