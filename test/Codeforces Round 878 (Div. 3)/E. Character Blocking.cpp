/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,b[N];
char s1[N],s2[N];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        scanf("%s%s",s1+1,s2+1);
        n=strlen(s1+1);
        int t=read(),q=read();
        int num=0,cnt=n;
        for(int i=1;i<=n;i++)num+=(s1[i]==s2[i]);
        for(int i=1;i<=q;i++)b[i]=0;
        for(int i=1;i<=q;i++){
            // printf("%s %s\n",s1+1,s2+1);
            // cout<<"!"<<num<<" "<<cnt<<endl;
            if(b[i]){
                num+=(s1[b[i]]==s2[b[i]]);
                cnt++;
            }
            int op=read();
            if(op==1){
                int x=read();
                if(i+t<=q)b[i+t]=x;
                num-=(s1[x]==s2[x]);
                cnt--;
            }
            else if(op==2){
                int t1=read(),p1=read(),t2=read(),p2=read();
                if(t1>t2){swap(t1,t2);swap(p1,p2);}
                if(t1==t2&&p1==p2)continue;
                if(t1==t2){
                    num-=(s1[p1]==s2[p1])+(s1[p2]==s2[p2]);
                    if(t1==1)swap(s1[p1],s1[p2]);
                    if(t1==2)swap(s2[p1],s2[p2]);
                    num+=(s1[p1]==s2[p1])+(s1[p2]==s2[p2]);
                }
                else{
                    num-=(s1[p1]==s2[p1])+(s1[p2]==s2[p2])*(p1!=p2);
                    if(t1==1)swap(s1[p1],s2[p2]);
                    if(t1==2)swap(s2[p1],s1[p2]);
                    num+=(s1[p1]==s2[p1])+(s1[p2]==s2[p2])*(p1!=p2);
                }
            }
            else{
                puts(cnt==num?"YES":"NO");
            }
        }
    }
	return 0;
}
