#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("L.in","w",stdout);
	int T=3;
	srand(time(NULL));
	printf("%d\n",T);
	while(T--){
		int n=rand()%10+3;
		printf("%d\n",n);
		for(int i=1;i<=n;i++)printf("%d",rand()&1);
		puts("");
	}
    return 0;
}
