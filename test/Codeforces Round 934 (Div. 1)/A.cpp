/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,a[N],b[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	int T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++)a[i]=read();
        sort(a+1,a+n+1);
        for(int i=0;i<=n;i++)b[i]=0;
        for(int i=1;i<=n;i++)b[a[i]]++;
        int ans=0;
        while(q.size())q.pop();
        for(int i=0;i<=n;i++){
            if(!b[i]){ans=i;break;}
            q.push(mp(b[i],i));
        }
        int t=0;
        while(q.size()){
            if(t==0){//Alice
                q.pop();
            }
            else{//Bob
                pii tmp=q.top();
                q.pop();
                tmp.first--;
                if(tmp.first)q.push(tmp);
                else ans=min(ans,tmp.second);
            }
            t^=1;
        }
        printf("%d\n",ans);
    }
	return 0;
}
