#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
const int M=31;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,a[N],b[N];
struct Line_Set{
	int a[M];
	void Clear(){memset(a,0,sizeof(a));}
	void Insert(int x){
		for(int i=M-1;i>=0;i--){
			if(!a[i]&&((x>>i)&1)){
				a[i]=x;
//				cout<<"Insert: "<<x<<endl;
				break;
			}
			else if((x>>i)&1)x^=a[i];
		}
	}
	int Query(int SA,int SB){
//		cout<<"Query: "<<SA<<" "<<SB<<endl;
		for(int i=M-1;i>=0;i--){
			if(!a[i])continue;
			if(((SA>>i)&1)&&((SB>>i)&1)){
				SA^=a[i];
				SB^=a[i];
			}
			else if(((SA>>i)&1)||((SB>>i)&1)){
				int tmp1=SA,tmp2=SB;
				if(!((tmp1>>i)&1))tmp1^=a[i];
				if(!((tmp2>>i)&1))tmp2^=a[i];
				for(int j=i-1;j>=0;j--){
					tmp1=min(tmp1,tmp1^a[j]);
					tmp2=min(tmp2,tmp2^a[j]);
				}
				return min(tmp1,tmp2);
			}
		}
		return max(SA,SB);
	}
}S;
int main(){
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		int SA=0,SB=0;
		S.Clear();
		for(int i=1;i<=n;i++){
			SA^=a[i];
			SB^=b[i];
			S.Insert(a[i]^b[i]);
		}
		printf("%d\n",S.Query(SA,SB));
	}
	return 0;
}
