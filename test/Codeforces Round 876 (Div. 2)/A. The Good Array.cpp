/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=105;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,a[N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
	while(T--){
		n=read();m=read();
		for(int i=1;i<=n;i++)a[i]=0;
		for(int i=1;i<=n;i++){
			int t=i/m;
			if(i%m)t++;
            int num1=0,num2=0;
			for(int j=1;j<=i;j++)num1+=a[j];
            if(num1<t){
                for(int j=i;j>=1;j--){
                    if(!a[j]){
                        a[j]=1;
                        num1++;
                        if(num1==t)break;
                    }
                }
            }
            num2=0;
			for(int j=1;j<=i;j++)num2+=a[n-j+1];
            if(num2<t){
                for(int j=n-i+1;j<=n;j++){
                    if(!a[j]){
                        a[j]=1;
                        num2++;
                        if(num2==t)break;
                    }
                }
            }
            // cout<<i<<" "<<t<<endl;
            // for(int j=1;j<=n;j++)cout<<a[j]<<" ";cout<<endl;
		}
        int ans=0;
        for(int i=1;i<=n;i++)ans+=a[i];
        printf("%d\n",ans);
	}
	return 0;
}
