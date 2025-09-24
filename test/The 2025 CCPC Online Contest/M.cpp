#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fst first
#define scd second
#define mp make_pair
using namespace std;
const int N=2e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int id(int k,int i,int j){return 1024*k+32*i+j;}
struct Node{
	int a,b,c;
};
vector<Node>F;
void Print(string c){
	printf("%s %u\n",c.c_str(),F.size());
	for(int i=0;i<F.size();i++){
		printf("%d ",F[i].a);
	}
	puts("");
	for(int i=0;i<F.size();i++){
		printf("%d ",F[i].b);
	}
	puts("");
	for(int i=0;i<F.size();i++){
		printf("%d ",F[i].c);
	}
	puts("");
}
int main(){
	printf("%d\n",31+31+5+5+31+32+32);
	for(int j=0;j<=30;j++){
		F.clear();
		for(int i=0;i<=31;i++){
			F.push_back((Node){id(0,i,j),id(0,i,j+1),id(0,i,j+1)});
		}
		Print("add");
	}
	for(int i=0;i<=4;i++){
		F.clear();
		int x=0,y=0;
		if(i&1)x=0,y=2;
		else x=2,y=0;
		for(int j=1<<i;j<=31;j++){
			F.push_back((Node){id(y,j,31),id(y,j-(1<<i),31),id(x,j,31)});
		}
		for(int j=0;j<(1<<i);j++){
			F.push_back((Node){id(y,j,31),id(3,31,31),id(x,j,31)});
		}
		Print("add");
	}
	for(int i=1;i<=31;i++){
		F.clear();
		F.push_back((Node){id(3,31,31),id(2,i,31),id(0,i,31)});
		for(int j=0;j<=30;j++){
			F.push_back((Node){id(0,i,j),id(2,i-1,31),id(0,i,j)});
		}
		Print("add");
	}
	for(int i=0;i<=31;i++){
		F.clear();
		for(int j=0;j<=31;j++){
			F.push_back((Node){id(0,i,j),id(1,i,j),id(1,i,j)});
		}
		Print("mul");
	}
	for(int j=0;j<=30;j++){
		F.clear();
		for(int i=0;i<=31;i++){
			F.push_back((Node){id(1,i,j),id(1,i,j+1),id(1,i,j+1)});
		}
		Print("max");
	}
	for(int i=0;i<=4;i++){
		F.clear();
		int x=0,y=0;
		if(i&1)x=1,y=2;
		else x=2,y=1;
		for(int j=1<<i;j<=31;j++){
			F.push_back((Node){id(y,j,31),id(y,j-(1<<i),31),id(x,j,31)});
		}
		for(int j=0;j<(1<<i);j++){
			F.push_back((Node){id(y,j,31),id(3,31,31),id(x,j,31)});
		}
		Print("max");
	}
	for(int i=0;i<=31;i++){
		F.clear();
		for(int j=0;j<=31;j++){
			F.push_back((Node){id(0,i,j),id(2,i,j),id(0,i,j)});
		}
		Print("sub");
	}
	
	return 0;
}
