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

int Rand(int Maxn){return (rand()*rand()+rand())%Maxn+1;}
int main(){
	srand(time(NULL));
	for(int i=1;i<=20;i++){
		string s="";
		s.push_back(i/10+'0');
		s.push_back(i%10+'0');
		FILE *InputFile=fopen(("drama"+s+".in").c_str(),"w");
		FILE *OutputFile=fopen(("drama"+s+".out").c_str(),"w");
		int x=Rand(1e4),y=Rand(1e4);
		int z=Rand(min(x,y));
		fprintf(InputFile,"%d %d %d\n",x,y,z);
		fprintf(OutputFile,"%.6lf\n",1.0*z/(1.0*x*y));
		fclose(InputFile);
		fclose(OutputFile);
	}
	return 0;
}
