#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,a[N],b[N][N],sum[N][N];
struct Heap2Heap{
    priority_queue<int>q1;
    priority_queue<int,vector<int>,greater<int> >q2;
    void Insert(int x){
        if(q2.empty()||x>=q2.top())q2.push(x);
        else q1.push(x);
    }
    void Clear(){
        while(q1.size())q1.pop();
        while(q2.size())q2.pop();
    }
    int Medium(){
        while(q2.size()>q1.size()){q1.push(q2.top());q2.pop();}
        while(q1.size()>q2.size()){q2.push(q1.top());q1.pop();}
        return q2.size()>q1.size()?q2.top():q1.top();
    }
}S;
int Calc(int x){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int val=(i<=j?b[i][j]<=x:0);
            // cout<<val<<" ";
            sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+val;
        }
        // cout<<endl;
    }
    int res=0;
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            int len=r-l+1;
            int num=(len+1)*len/2;
            if(sum[r][r]-sum[l-1][r]-sum[r][l-1]+sum[l-1][l-1]>=(num+1)/2)res++;
        }
    }
    return res;
}
int main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            S.Insert(a[r]);
            b[l][r]=S.Medium();
        }
        S.Clear();
    }
    // for(int i=1;i<=n;i++){
        // for(int j=1;j<=n;j++)cout<<b[i][j]<<" ";cout<<endl;
    // }
    // cout<<Calc(4)<<endl;;
    // return 0;
    int l=1,r=1e9,ans=0;
    int num=(1+n)*n/2;
    while(l<=r){
        int mid=(l+r)>>1;
        if(Calc(mid)>=(num+1)/2){//medium <= mid : > (num+1)/2
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}