#include<bits/stdc++.h>
#define Point Vector2f
using namespace std;
const int N=105;
const double eps=1e-6;
double alpha,beta,lambda;
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
    friend double operator*(Vector2f A,Vector2f B){
        return A.x*B.x+A.y*B.y;
    }
}x,d;
struct Matrix2f{
    double a[2][2];
    Matrix2f(double a1=0,double a2=0,double a3=0,double a4=0){
        a[0][0]=a1;a[0][1]=a2;a[1][0]=a3;a[1][1]=a4;
    }
    friend Matrix2f operator*(Matrix2f A,double B){
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                A.a[i][j]*=B;
        return A;
    }
    friend Vector2f operator*(Matrix2f A,Vector2f B){
        return Vector2f(A.a[0][0]*B.x+A.a[0][1]*B.y,A.a[1][0]*B.x+A.a[1][1]*B.y);
    }
    double det(){
        return a[0][0]*a[1][1]-a[0][1]*a[1][0];
    }
    Matrix2f inv(){
        return Matrix2f(a[1][1],-a[1][0],-a[0][1],a[0][0])*(1/det());
    }
};
double f(Point A){
    return exp(A.x+3*A.y-0.1)+exp(A.x-3*A.y-0.1)+exp(-A.x-0.1);
}
Vector2f df(Point A){
    Vector2f res;
    res.x=exp(A.x+3*A.y-0.1)+exp(A.x-3*A.y-0.1)-exp(-A.x-0.1);
    res.y=3*exp(A.x+3*A.y-0.1)-3*exp(A.x-3*A.y-0.1);
    return res;
}
Matrix2f ddf(Point A){
    Vector2f dfx=df(A);
    Matrix2f ddfx;
    ddfx.a[0][0]=f(A);
    ddfx.a[0][1]=dfx.y;
    ddfx.a[1][0]=dfx.y;
    ddfx.a[1][1]=9*exp(A.x+3*A.y-0.1)+9*exp(A.x-3*A.y-0.1);
    return ddfx;
}
double Calc(){
    double res=1;
    while(f(x+d*res)>f(x)-alpha*res*lambda)res*=beta;
    return res;
}
bool Check(Point A){
    d=ddf(A).inv()*df(A)*(-1);
    lambda=d*(ddf(A)*d);
    return lambda/2<eps;
}
int main(){
    alpha=0.1;
    beta=0.7;
    int n=0;
    x=Point(0.5,0.5);
    while(!Check(x)){
        Vector2f t=df(x);
        n++;
        x=x+d*Calc();
        cout<<"alpha="<<alpha<<" , beta="<<beta<<" , n="<<n<<" , x*=("<<x.x<<","<<x.y<<") , f(x*)="<<f(x)<<endl;
    }
    return 0;
}
/*
Output:
alpha=0.1 , beta=0.7 , n=1 , x*=(0.104036,0.317753) , f(x*)=3.80711
alpha=0.1 , beta=0.7 , n=2 , x*=(-0.142089,0.131482) , f(x*)=2.73669
alpha=0.1 , beta=0.7 , n=3 , x*=(-0.307122,0.0270591) , f(x*)=2.56565
alpha=0.1 , beta=0.7 , n=4 , x*=(-0.34491,0.00107954) , f(x*)=2.55928
alpha=0.1 , beta=0.7 , n=5 , x*=(-0.346571,1.79689e-06) , f(x*)=2.55927
*/