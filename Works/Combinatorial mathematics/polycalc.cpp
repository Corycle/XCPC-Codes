#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;
ll read(){
	ll s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
ll Fac(int n){
    ll ans=1;
    for(int i=1;i<=n;i++)ans*=i;
    return ans;
}
class Number{
public:
    ll x,y;
    Number(ll a=0,ll b=1):x(a),y(b){}
    void Fix(){
        if(!x){y=1;return;}
        if(x<0&&y<0){x=-x;y=-y;}
        ll gcd=__gcd(abs(x),abs(y));
        x/=gcd;y/=gcd;
    }
    friend Number operator*(Number A,Number B){
        Number C(A.x*B.x,A.y*B.y);
        C.Fix();
        return C;
    }
    friend Number operator+(Number A,Number B){
        Number C(A.x*B.y+A.y*B.x,A.y*B.y);
        C.Fix();
        return C;
    }
    void Print(){
        if(y==1)printf("%lld",x);
        else printf("%lld/%lld",x,y);
    }
};
class Poly{
public:
    int n;
    vector<Number>a;
    Poly(int m=0):n(m){
        a.resize(n+1);
        for(int i=0;i<=n;i++)a[i]=Number(0);
    }
    friend Poly operator*(Poly A,Poly B){
        Poly C(A.n+B.n);
        for(int i=0;i<=A.n;i++){
            for(int j=0;j<=B.n;j++){
                C.a[i+j]=C.a[i+j]+A.a[i]*B.a[j];
            }
        }
        while(C.n&&C.a[C.n].x==0)C.n--;
        C.a.resize(C.n+1);
        return C;
    }
    void Print(){
        bool flag=false;
        for(int i=0;i<=n;i++){
            if(a[i].x==0)continue;
            if(flag)printf(a[i].x>0?" +":" ");
            flag=true;
            a[i].Print();
            if(i){
                if(i==1)printf("*x");
                else printf("*x^%d",i);
            }
        }
        puts(flag?"":"0");
    }
};
Poly p[N];
int main(){
    int n=read();
    for(int i=1;i<=n;i++){
        p[i]=Poly(read());
        for(int j=0;j<=p[i].n;j++){
            ll x=read(),y=read();
            p[i].a[j]=Number(x,y);
            p[i].a[j].Fix();
        }
    }
    for(int i=1;i<=n;i++){
        cout<<"Poly "<<i<<" :"<<endl;
        p[i].Print();
    }
    Poly ans=p[1];
    for(int i=2;i<=n;i++)ans=ans*p[i];
    cout<<"Answer : "<<endl;
    ans.Print();

    // Number sum(0);
    // for(int i=0;i<=ans.n;i++)sum=sum+ans.a[i]*Fac(i);
    // cout<<"Sum = ";
    // sum.Print();
    // puts("");
    return 0;
}
/*
3
3 0/1 1/1 1/1 1/1
3 1/1 1/1 1/1 1/1
6 0/1 0/1 1/1 1/1 1/1 1/1 1/1
*/