#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Mod=1e18;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n;
map<int,int> mmp,mmp2;
const int maxn=1e7+5;
class node
{
public:
	node *l,*r;
	int val;
	node()
	{
		l=r=nullptr;
		val=0;
	}
}pool[maxn];
int cnt=0;
node* newnode()
{
	++cnt;
	#define tmp (pool+(cnt))
	tmp->l=nullptr;
	tmp->r=nullptr;
	tmp->val=0;
	return tmp;
}
void insert(node* r,int x,int val)
{
	for(int i=0;i<=62;++i)
	{
		r->val+=val;
		if(x&(1ll<<i))
		{
			if(r->l==nullptr)
			{
				r->l=newnode();
			}
			r=r->l;
		}
		else
		{
			if(r->r==nullptr)
			{
				r->r=newnode();
			}
			r=r->r;
		}
	}
}
int walk(node* r,int x)
{
	int val=0;
	for(int i=0;i<=62;++i)
	{
		if(x&(1ll<<i))
		{
			if(r->l==nullptr)
			{
				break;
			}
			if(i%2==0)
			{
				val=val+(r->r==nullptr?0:r->r->val);
			}
			r=r->l;
		}
		else
		{
			if(r->r==nullptr)
			{
				break;
			}
			if(i%2==0)
			{
				val=val+(r->l==nullptr?0:r->l->val); 
			}
			r=r->r;
		}
	}
	return val;
}
void work(){
	cnt=0;
	node* root=newnode();
	n=read();mmp2.clear();
	for(int i=1,x;i<=n;++i) x=read(),mmp2[x]++,insert(root,x,1);
	int ans=0;
	for(auto i:mmp2){
		if(i.second>=2)
		{
			ans=ans+i.second*(i.second-1)/2*walk(root,i.first);
		}
		if(i.second>=3)
		{
			ans=ans+i.second*(i.second-1)/2*(i.second-2)/3; 
		}
	}
	printf("%lld\n",n*(n-1)/2*(n-2)/3-ans);
}
signed main(){
	int T=read();
	while(T--) work();
	return 0;
}
