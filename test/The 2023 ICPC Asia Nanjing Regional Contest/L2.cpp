#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;
ll read(){
    ll s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,pos[3],lst[N];
ll m,Ans,Cost,Size,FreeSize;
struct Node{ll c,f,w;}a[N];
bool cmp(Node A,Node B){return A.f<B.f;}
void Put(int &p){
    Cost=max(Cost,a[p].f);
    if(a[p].c*a[p].w<=Size){
        Size-=a[p].c*a[p].w;
        a[p].c=0;
    }
    else if(Size==m){
        ll num=a[p].c/(Size/a[p].w);
        FreeSize+=num*(Size%a[p].w);
        a[p].c%=(Size/a[p].w);
        Ans+=num*a[p].f;
        Cost=0;
    }
    else{
        ll num=Size/a[p].w;
        a[p].c-=num;
        FreeSize+=(Size%a[p].w);
        Size=0;
    }
    if(!a[p].c)p=lst[p];
}
int main(){
    int T=read();
    while(T--){
        n=read();m=read();
        for(int i=1;i<=n;i++){a[i].c=read();a[i].w=read();a[i].f=read();}
        sort(a+1,a+n+1,cmp);
        pos[1]=pos[2]=0;
        for(int i=1;i<=n;i++){lst[i]=pos[a[i].w];pos[a[i].w]=i;}
        int p1=pos[1],p2=pos[2];Size=m;Cost=0;FreeSize=0;Ans=0;
        while(p1&&p2){
            if(FreeSize){
                int dlt=min(FreeSize,a[p1].c);
                a[p1].c-=dlt;
                FreeSize-=dlt;
                if(!a[p1].c)p1=lst[p1];
            }
            else if(a[p2].f>=a[p1].f&&Size>=2)Put(p2);
            else Put(p1);
            if(!Size){Ans+=Cost;Size=m;Cost=0;}
        }
        while(p1){Put(p1);if(Size<1){Ans+=Cost;Size=m;Cost=0;}}
        while(p2){Put(p2);if(Size<2){Ans+=Cost;Size=m;Cost=0;}}
        Ans+=Cost;
        printf("%lld\n",Ans);
    }
    return 0;
}