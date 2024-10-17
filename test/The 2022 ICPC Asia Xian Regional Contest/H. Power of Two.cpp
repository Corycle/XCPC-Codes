#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,tot,x,y,z,a[N],b[N];
struct Node{
	int op,x;
}P[N];
void And(int i){P[++tot]=(Node){0,i};a[i]--;x--;b[i]&=1;}
void Or (int i){P[++tot]=(Node){1,i};a[i]--;y--;b[i]|=1;}
void Xor(int i){P[++tot]=(Node){2,i};a[i]--;z--;b[i]^=1;}
int main(){
	int T=read();
	while(T--){
		puts("");
		n=read();x=read();y=read();z=read();tot=0;
		for(int i=0;i<=n;i++)a[i]=b[i]=0;
		for(int i=1;i<=n;i++)a[read()]++;
		//AND:
		for(int i=n;i>=0;i--)if((a[i]&1)&&x>=2){And(i);And(i);}
		for(int i=n;i>=0;i--)if(a[i]&&!(a[i]&1)&&x)And(i);
		for(int i=0;i<=n;i++)while(a[i]&&x)And(i);
		//XOR:
		for(int i=n;i>=0;i--)while(a[i]>2&&z>=2){Xor(i);Xor(i);}
		for(int i=n;i>=0;i--)if(a[i]==1&&z)Xor(i);
		for(int i=n;i>=0;i--)if(a[i]==2&&y&&z){Xor(i);Or(i);}
		for(int i=0;i<=n;i++)while(a[i]&&z)Xor(i);
		//OR:
		for(int i=0;i<=n;i++)while(a[i]&&y)Or(i);
		
		for(int i=n-1;i>=0;i--)printf("%d ",b[i]);puts("");
		for(int i=1;i<=n;i++)putchar(P[i].op==0?'&':(P[i].op==1?'|':'^'));puts("");
		for(int i=1;i<=n;i++)printf("%d ",P[i].x);puts("");
	}
	return 0;
}
