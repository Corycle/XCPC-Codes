#include<bits/stdc++.h>
#define ll long long
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
using namespace std;
const int N=5e5+5;
ll read(){
    ll s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
ll K;
int n,m,a[N],b[N];
struct Heap1{
    ll sum;
    priority_queue<int>q1,q2;
    void clear(){
        sum=0;
        while(q1.size())q1.pop();
        while(q2.size())q2.pop();
    }
    int size(){return q1.size()-q2.size();}
    void push(int x){q1.push(x);sum+=x;}
    void pop(int x){q2.push(x);sum-=x;}
    int top(){
        while(q1.size()&&q2.size()&&q1.top()==q2.top()){q1.pop();q2.pop();}
        return q1.top();
    }
};
struct Heap2{
    ll sum;
    priority_queue<int,vector<int>,greater<int> >q1,q2;
    void clear(){
        sum=0;
        while(q1.size())q1.pop();
        while(q2.size())q2.pop();
    }
    int size(){return q1.size()-q2.size();}
    void push(int x){q1.push(x);sum+=x;}
    void pop(int x){q2.push(x);sum-=x;}
    int top(){
        while(q1.size()&&q2.size()&&q1.top()==q2.top()){q1.pop();q2.pop();}
        return q1.top();
    }
};
struct Heap{
    Heap1 q1;
    Heap2 q2;
    void Clear(){q1.clear();q2.clear();}
    void Update(){
        while(q1.size()>q2.size()){q2.push(q1.top());q1.pop(q1.top());}
        while(q2.size()>q1.size()){q1.push(q2.top());q2.pop(q2.top());}
    }
    void Insert(int x){
        if(q1.size()==0)q2.push(x);
        else if(q2.size()==0)q1.push(x);
        else if(x<=q1.top())q1.push(x);
        else q2.push(x);
        Update();
    }
    void Delete(int x){
        if(q1.size()&&x<=q1.top())q1.pop(x);
        else q2.pop(x);
        Update();
    }
    ll Calc(){
        Update();
        if(q1.size()==0&&q2.size()==0)return 0;
        ll x=q1.top();
        return (x*q1.size()-q1.sum)+(q2.sum-x*q2.size());
    }
}S;
int main(){
    int T=read();
    while(T--){
        n=read();K=read();
        for(int i=1;i<=n;i++)a[i]=read()-i;
        S.Clear();
        S.Insert(a[1]);
        int ans=1;
        for(int l=1,r=1;l<=n;l++){
            while(r<n){
                ++r;
                S.Insert(a[r]);
                if(S.Calc()<=K)ans=max(ans,r-l+1);
                else{
                    S.Delete(a[r]);
                    r--;
                    break;
                }
            }
            S.Delete(a[l]);
        }
        printf("%d\n",ans);
    }
    return 0;
}