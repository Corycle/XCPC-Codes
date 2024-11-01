#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;
double gama;
struct Point{
    double x,y;
};
double f(Point A){
    return (A.x*A.x+gama*A.y*A.y)/2;
}
bool Check(Point A){
    A.y*=gama;
    return sqrt(A.x*A.x+A.y*A.y)<eps;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n=0;
        cin>>gama;
        Point x=(Point){gama,1};
        while(!Check(x)){
            n++;
            x.x=(1-2/(1+gama))*x.x;
            x.y=(1-2/(1+gama)*gama)*x.y;
        }
        cout<<"gama="<<gama<<" , n="<<n<<" , x*=("<<x.x<<","<<x.y<<") , f(x*)="<<f(x)<<endl;
    }
    return 0;
}
/*
Input:
9
1 3 10 100 1000 0.33 0.1 0.01 0.001
Output:
gama=1 , n=1 , x*=(0,0) , f(x*)=0
gama=3 , n=23 , x*=(3.57628e-07,-1.19209e-07) , f(x*)=8.52651e-14
gama=10 , n=83 , x*=(5.84165e-07,-5.84165e-08) , f(x*)=1.87687e-13
gama=100 , n=939 , x*=(6.97714e-07,-6.97714e-09) , f(x*)=2.45837e-13
gama=1000 , n=10535 , x*=(7.06988e-07,-7.06988e-10) , f(x*)=2.50166e-13
gama=0.33 , n=20 , x*=(3.65576e-07,1.1078e-06) , f(x*)=2.69316e-13
gama=0.1 , n=60 , x*=(5.90187e-07,5.90187e-06) , f(x*)=1.91576e-12
gama=0.01 , n=478 , x*=(7.04703e-07,7.04703e-05) , f(x*)=2.50786e-11
gama=0.001 , n=3628 , x*=(7.05924e-07,0.000705924) , f(x*)=2.49414e-10
*/