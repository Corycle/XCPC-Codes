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
int Rand(int n){return (1ll*rand()*rand()+rand())%n+1;}
int n,m;
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	srand(time(NULL));
    n=Rand(1e5);m=Rand(6)-1;
    cout<<n<<" "<<m<<endl;
    cout<<Rand(3)<<" "<<Rand(3)<<" "<<Rand(3)<<" "<<Rand(3)<<endl;
	return 0;
}
