/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n;
void Solve(int x){
	int flag=0;
	for(int i=15;i>=2;i--){
		if(x&(1<<i)){
			if(!flag)flag=1;
			else printf("+");
			printf("2(");
			Solve(i);
			printf(")");
		}
	}
	if(x&2){
		if(!flag)flag=1;
		else printf("+");
		printf("2");
	}
	if(x&1){
		if(!flag)flag=1;
		else printf("+");
		printf("2(0)");
	}
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();
	Solve(n);
	return 0;
}
