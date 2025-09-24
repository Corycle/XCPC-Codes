#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m;
struct Line{
	int l,r;
}a[N];
struct Node{
	int l,r;
	friend bool operator<(Node A,Node B){
		return A.r>B.r;
	}
};
bool cmp(Line A,Line B){
	return A.l!=B.l?A.l<B.l:A.r<B.r;
}
int GetAns(){
	int u=-1,ans=n,num=1;
	sort(a+1,a+m+1,cmp);
	priority_queue<Node>q;
	for(int i=1;i<=m;i++){
		while(q.empty()||(num<=m&&a[num].l<=u+1)){
			q.push((Node){a[num].l,a[num].r});
			num++;
		}
		int l=q.top().l,r=q.top().r;q.pop();
//		cout<<"? "<<l<<" "<<r<<" u="<<u<<endl;
		if(r<=u+1)continue;
		if(l==r)continue;
		if(l<=u+1){
			u=u+1;
//			cout<<"use "<<u<<" to print "<<u+1<<endl;
			ans--;
		}
		else{
			u=l;
//			cout<<"use "<<u<<" to print "<<u+1<<endl;
			ans--;
		}
	}
	return ans;
}
int main(){
	int T=read();
	while(T--){
		m=read();n=read();
		for(int i=1;i<=m;i++){
			a[i].l=read();
			a[i].r=read();
		}
		int ans=GetAns();
		printf("%d\n",ans);
	}
	return 0;
}
/*
1
8 10
3 4
7 8
1 10
1 10
1 10
1 10
1 10
1 10

*/
