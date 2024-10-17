/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e4+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,cnt,top,a[N],b[N],st[N];
struct Heap{
	priority_queue<int,vector<int>,greater<int> >q1,q2;
	void Insert(int x){q1.push(x);}
	void Delete(int x){q2.push(x);}
	int Top(){
		while(!q1.empty()&&!q2.empty()&&q1.top()==q2.top()){q1.pop();q2.pop();}
		return q1.top();
	}
}q;
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=b[i]=read();
	sort(b+1,b+n+1);cnt=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+cnt+1,a[i])-b;
	for(int i=1,j=1,pos=1;i<=n;i++){
		while(j<=n&&top+j-pos+1<=m)q.Insert(a[j++]);
		if(!top||st[top]>q.Top()){
			int x=q.Top();
			while(pos<=n){
				q.Delete(a[pos]);
				st[++top]=a[pos++];
				if(a[pos-1]==x)break;
			}
		}
		printf("%d ",b[st[top--]]);
	}
	return 0;
}
