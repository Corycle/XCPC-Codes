/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=1e9+7;
const int N=1e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
string s="lzr010506";
int n,m;
struct Node{
    string name;
    int num,time;
}a[N],b[N];
unordered_map<string,int>cnt;
char S[15];
bool cmp(const Node &A,const Node &B){
    return A.num!=B.num?A.num>B.num:(A.time!=B.time?A.time<B.time:A.name<B.name);
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        scanf("%s",S);
        a[i].name=(string)(S);
        a[i].num=read();
        a[i].time=read();
        cnt[a[i].name]++;
    }
    sort(a+1,a+n+1,cmp);
    
    m=read();
    for(int i=1;i<=m;i++){
        scanf("%s",S);
        b[i].name=(string)(S);
        b[i].num=read();
        b[i].time=read();
        cnt[b[i].name]++;
    }
    sort(b+1,b+m+1,cmp);

    int p1=0,p2=0;
    for(int i=1;i<=n;i++){
        if(a[i].name==s){
            p1=i;
            while(p1!=1&&a[p1].num==a[p1-1].num&&a[p1].time==a[p1-1].time)p1--;
        }
    }
    for(int i=1;i<=m;i++){
        if(b[i].name==s){
            p2=i;
            while(p2!=1&&b[p2].num==b[p2-1].num&&b[p2].time==b[p2-1].time)p2--;
        }
    }
    int ans1=p1,ans2=p2;
    for(int i=1;i<p1;i++){
        if(cnt[a[i].name]==2)ans1--;
    }
    for(int i=1;i<p2;i++){
        if(cnt[b[i].name]==2)ans2--;
    }
    printf("%d\n",min(ans1,ans2));
	return 0;
}
