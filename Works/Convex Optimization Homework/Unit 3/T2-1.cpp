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
    double l=0,r=10;
    while(r-l>eps){
        double m1=l+(r-l)/3;
        double m2=r-(r-l)/3;
        if(f(x-dfx*m1)<f(x-dfx*m2))r=m2;
        else l=m1;
    }
    return l;
}
bool Check(Point A){
    dfx=df(A);
    return dfx.norm()<eps;
}
int main(){
    int n=0;
    x=Point(0.5,0.5);
    while(!Check(x)){
        n++;
        x=x-dfx*Calc();
        cout<<"n="<<n<<" , x*=("<<x.x<<","<<x.y<<") , f(x*)="<<f(x)<<endl;
    }
    return 0;
}
/*
Output:
n=1 , x*=(0.3208,-0.0278829) , f(x*)=3.1594
n=2 , x*=(-0.145565,0.130395) , f(x*)=2.73238
n=3 , x*=(-0.193205,-0.00997607) , f(x*)=2.59009
n=4 , x*=(-0.304211,0.0276957) , f(x*)=2.56617
n=5 , x*=(-0.314408,-0.00235017) , f(x*)=2.56062
n=6 , x*=(-0.337957,0.00564108) , f(x*)=2.55955
n=7 , x*=(-0.340037,-0.000489727) , f(x*)=2.55932
n=8 , x*=(-0.344835,0.00113839) , f(x*)=2.55928
n=9 , x*=(-0.345255,-9.9288e-05) , f(x*)=2.55927
n=10 , x*=(-0.346223,0.000229292) , f(x*)=2.55927
n=11 , x*=(-0.346308,-2.00151e-05) , f(x*)=2.55927
n=12 , x*=(-0.346503,4.61665e-05) , f(x*)=2.55927
n=13 , x*=(-0.34652,-4.03401e-06) , f(x*)=2.55927
n=14 , x*=(-0.346559,9.29524e-06) , f(x*)=2.55927
n=15 , x*=(-0.346563,-8.22829e-07) , f(x*)=2.55927
n=16 , x*=(-0.346571,1.88485e-06) , f(x*)=2.55927
n=17 , x*=(-0.346571,-1.74758e-07) , f(x*)=2.55927
n=18 , x*=(-0.346573,3.88954e-07) , f(x*)=2.55927
n=19 , x*=(-0.346573,-3.79913e-08) , f(x*)=2.55927
n=20 , x*=(-0.346573,8.64806e-08) , f(x*)=2.55927
n=21 , x*=(-0.346573,-1.5327e-08) , f(x*)=2.55927
*/