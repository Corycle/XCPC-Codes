#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2e6+5;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,k,a[N];
map<int,int>cnt;
vector<int>pos[N];
int main(){
	n=read();k=read();
	int Min=inf,Ans=0;
	for(int i=1;i<=n;i++)a[i]=read();
	if(k<0){
		k=-k;
		for(int i=1;i<=n;i++)a[i]=-a[i];
	}
	for(int i=1;i<=n;i++)Min=min(Min,a[i]);
	for(int i=1;i<=n;i++){
		a[i]-=Min;
		cnt[a[i]]++;
		Ans=max(Ans,cnt[a[i]]);
		pos[a[i]].push_back(i);
	}
	if(k==0){
		printf("%d\n",Ans);
		return 0;
	}
	for(int i=0;i+k<N;i++){
		if(pos[i].empty()||pos[i+k].empty())continue;
		int n1=pos[i].size(),n2=pos[i+k].size();
		int p1=0,p2=0,num=0,MIN=0;
		while(p1<n1&&p2<n2){
			if(pos[i][p1]<pos[i+k][p2]){
				num++;p1++;
			}
			else{
				num--;p2++;
			}
			MIN=min(MIN,num);
			Ans=max(Ans,n2+num-MIN);
//			cout<<p1<<" "<<p2<<" "<<Ans<<endl;
		}
		while(p1<n1){
			num++;p1++;
			MIN=min(MIN,num);
			Ans=max(Ans,n2+num-MIN);
		}
		while(p2<n2){
			num--;p2++;
			MIN=min(MIN,num);
			Ans=max(Ans,n2+num-MIN);
		}
	}
	printf("%d\n",Ans);
    return 0;
}
/*
7 1
3 2 3 2 2 2 3
*/
