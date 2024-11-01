#include<bits/stdc++.h>
#define Point Vector2f
using namespace std;
const int N=105;
const double eps=1e-6;
double alpha,beta;
double Sqr(double x){return x*x;}
struct Vector2f{
    double x,y;
    Vector2f(double a=0,double b=0):x(a),y(b){}
    double norm(){
        return sqrt(x*x+y*y);
    }
    friend Vector2f operator+(Vector2f A,Vector2f B){
        return Vector2f(A.x+B.x,A.y+B.y);
    }
    friend Vector2f operator-(Vector2f A,Vector2f B){
        return Vector2f(A.x-B.x,A.y-B.y);
    }
    friend Vector2f operator*(Vector2f A,double B){
        return Vector2f(A.x*B,A.y*B);
    }
}x,dfx;
double f(Point A){
    return exp(A.x+3*A.y-0.1)+exp(A.x-3*A.y-0.1)+exp(-A.x-0.1);
}
Vector2f df(Point A){
    Vector2f res;
    res.x=exp(A.x+3*A.y-0.1)+exp(A.x-3*A.y-0.1)-exp(-A.x-0.1);
    res.y=3*exp(A.x+3*A.y-0.1)-3*exp(A.x-3*A.y-0.1);
    return res;
}
double Calc(){
    double res=1;
    while(f(x-dfx*res)>f(x)-alpha*res*Sqr(dfx.norm()))res*=beta;
    return res;
}
bool Check(Point A){
    dfx=df(A);
    return dfx.norm()<eps;
}
double a[N],b[N];
int main(){
    int n1=0,n2=0;
    cin>>n1>>n2;
    for(int i=1;i<=n1;i++)cin>>a[i];
    for(int i=1;i<=n2;i++)cin>>b[i];
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            alpha=a[i];beta=b[j];
            int n=0;
            x=Point(0.5,0.5);
            while(!Check(x)){
                n++;
                x=x-dfx*Calc();
            }
            cout<<"alpha="<<alpha<<" , beta="<<beta<<" , n="<<n<<" , x*=("<<x.x<<","<<x.y<<") , f(x*)="<<f(x)<<endl;
        }
    }
    return 0;
}
/*
Input:
5 5
0.01 0.1 0.25 0.4 0.5
0.1 0.3 0.5 0.7 0.9
Output:
alpha=0.01 , beta=0.1 , n=50 , x*=(-0.346573,-4.86471e-19) , f(x*)=2.55927
alpha=0.01 , beta=0.3 , n=18 , x*=(-0.346573,3.5163e-09) , f(x*)=2.55927
alpha=0.01 , beta=0.5 , n=27 , x*=(-0.346573,-5.55478e-08) , f(x*)=2.55927
alpha=0.01 , beta=0.7 , n=211 , x*=(-0.346574,-8.27861e-08) , f(x*)=2.55927
alpha=0.01 , beta=0.9 , n=182 , x*=(-0.346574,8.60921e-08) , f(x*)=2.55927
alpha=0.1 , beta=0.1 , n=52 , x*=(-0.346573,3.82462e-18) , f(x*)=2.55927
alpha=0.1 , beta=0.3 , n=18 , x*=(-0.346573,1.02756e-08) , f(x*)=2.55927
alpha=0.1 , beta=0.5 , n=31 , x*=(-0.346573,-5.93928e-08) , f(x*)=2.55927
alpha=0.1 , beta=0.7 , n=34 , x*=(-0.346573,7.51079e-08) , f(x*)=2.55927
alpha=0.1 , beta=0.9 , n=50 , x*=(-0.346574,8.4915e-08) , f(x*)=2.55927
alpha=0.25 , beta=0.1 , n=53 , x*=(-0.346573,3.43581e-18) , f(x*)=2.55927
alpha=0.25 , beta=0.3 , n=18 , x*=(-0.346573,1.02756e-08) , f(x*)=2.55927
alpha=0.25 , beta=0.5 , n=31 , x*=(-0.346574,4.55454e-08) , f(x*)=2.55927
alpha=0.25 , beta=0.7 , n=31 , x*=(-0.346573,-6.80368e-08) , f(x*)=2.55927        
alpha=0.25 , beta=0.9 , n=36 , x*=(-0.346573,6.50043e-08) , f(x*)=2.55927
alpha=0.4 , beta=0.1 , n=56 , x*=(-0.346573,-7.33616e-18) , f(x*)=2.55927
alpha=0.4 , beta=0.3 , n=18 , x*=(-0.346573,1.03814e-08) , f(x*)=2.55927
alpha=0.4 , beta=0.5 , n=31 , x*=(-0.346573,4.03006e-08) , f(x*)=2.55927
alpha=0.4 , beta=0.7 , n=21 , x*=(-0.346573,-3.6215e-08) , f(x*)=2.55927
alpha=0.4 , beta=0.9 , n=31 , x*=(-0.346573,5.9396e-08) , f(x*)=2.55927
alpha=0.5 , beta=0.1 , n=57 , x*=(-0.346573,-8.24054e-18) , f(x*)=2.55927
alpha=0.5 , beta=0.3 , n=22 , x*=(-0.346573,-3.53989e-09) , f(x*)=2.55927
alpha=0.5 , beta=0.5 , n=30 , x*=(-0.346573,-4.54355e-08) , f(x*)=2.55927
alpha=0.5 , beta=0.7 , n=21 , x*=(-0.346573,2.7451e-08) , f(x*)=2.55927
alpha=0.5 , beta=0.9 , n=26 , x*=(-0.346573,-1.09918e-08) , f(x*)=2.55927
*/