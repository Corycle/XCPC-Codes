#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=998244353;
int n;
char s[100005];
int f[2][100][8],g[100005][8];
bool isUpper(char c){
	return c>='A'&&c<='Z';
}
bool isLower(char c){
	return c>='a'&&c<='z';
}
bool isNum(char c){
	return c>='0'&&c<='9';
}
signed main(){
	cin>>n>>(s+1);
	for(int k=1;k<=7;++k) g[0][k]=1;
	int t=1;
	for(int i=1;i<=n;++i){
		t^=1;
		for(int j=0;j<26+26+10;++j) for(int k=1;k<=7;++k) f[t][j][k]=0;
		if(isUpper(s[i])) {
			for(int k=4;k<=7;++k)
				f[t][s[i]-'A'][k]=g[i-1][k]-f[t^1][s[i]-'A'][k];
		}
		else if(isLower(s[i])){
			//2 3 6 7
				f[t][s[i]-'a'+26][2]=g[i-1][2]-f[t^1][s[i]-'a'+26][2];
				f[t][s[i]-'a'+26][3]=g[i-1][3]-f[t^1][s[i]-'a'+26][3];
				f[t][s[i]-'a'+26][6]=g[i-1][6]-f[t^1][s[i]-'a'+26][6];
				f[t][s[i]-'a'+26][7]=g[i-1][7]-f[t^1][s[i]-'a'+26][7];
			//4 5 6 7
			for(int k=4;k<=7;++k)
				f[t][s[i]-'a'][k]=g[i-1][k]-f[t^1][s[i]-'a'][k];
		}
		else if(isNum(s[i])){
			for(int k=1;k<=7;k+=2)
				f[t][s[i]-'0'+26+26][k]=g[i-1][k]-f[t^1][s[i]-'0'+26+26][k];
		}
		else{
			for(int k=1;k<=7;++k){
				if(k&1) for(int j=26+26;j<26+26+10;++j)
					f[t][j][k]=g[i-1][k]-f[t^1][j][k];
				if(k&2) for(int j=26;j<26+26;++j)
					f[t][j][k]=g[i-1][k]-f[t^1][j][k];
				if(k&4) for(int j=0;j<26;++j)
					f[t][j][k]=g[i-1][k]-f[t^1][j][k];
			}
		}
		for(int j=0;j<26+26+10;++j) for(int k=1;k<=7;++k) {
			f[t][j][k]%=p;
			if(f[t][j][k]<0) f[t][j][k]+=p;
		}
		for(int k=1;k<=7;++k) for(int j=0;j<26+26+10;++j) g[i][k]+=f[t][j][k],g[i][k]%=p;
	}
	cout<<((g[n][7]-g[n][6]-g[n][5]-g[n][3]+g[n][4]+g[n][2]+g[n][1])%p+p)%p;
}
