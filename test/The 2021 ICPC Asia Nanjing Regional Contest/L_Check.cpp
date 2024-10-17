#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
FILE *F1,*F2;
char a[N];
int main(){
	int num=0;
	while(1){
		cout<<"Case: "<<++num<<endl;
		system("L_random.exe");
		system("L.exe");
		F1=fopen("L.in","r");
		F2=fopen("L.out","r");
		int T;
		fscanf(F1,"%d",&T);
		while(T--){
			int n,m;
			fscanf(F1,"%d",&n);
//			cout<<n<<endl;
			fscanf(F1,"%s",a+1);
//			cout<<(a+1)<<endl;
			fscanf(F2,"%d",&m);
			if(!m)continue;
			for(int i=1;i<=n;i++)a[i]-='0';
			int flag=1;
			for(int i=1;i<=m;i++){
				int x;
				fscanf(F2,"%d",&x);
				if(a[x]==1)flag=0;
				a[x]^=1;
				a[x==n?1:x+1]^=1;
				a[x==1?n:x-1]^=1;
			}
			for(int i=1;i<=n;i++)if(!a[i])flag=0;
			if(!flag||m>2*n){
				cout<<"!!!"<<endl;
				return 0;
			}
		}
		fclose(F1);
		fclose(F2);
	}
    return 0;
}
