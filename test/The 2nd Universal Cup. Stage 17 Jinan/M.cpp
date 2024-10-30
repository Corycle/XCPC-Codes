#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
ll read(){
    ll s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
struct Point{
    ll x,y;
    bool tag;
    Point(ll a=0,ll b=0,bool c=false){
        x=a;y=b;tag=c;
    }
    Point operator-(const Point &b) const{
        return Point(x-b.x,y-b.y,false);
    }
}P[2003];
ll Cross(Point A,Point B,Point C){ //AB x AC
    return (A.x-C.x)*(B.y-C.y)-(A.y-C.y)*(B.x-C.x);
}
ll Dist(Point A,Point B){
    return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
}
bool cmp(Point A,Point B){
    ll x=Cross(A,B,P[1]);
    if(x>0) return true;
    if(x<0) return false;
    return Dist(A,P[1])<Dist(B,P[1]);
}
int n;
int top,a[2003];
vector<Point> q;
const double eps = 1e-12;
const double pi = acos(-1);
double ang(Point p){
    if(fabs(p.x)<eps){
        if(p.y>0) return pi/2;
        else return 3*pi/2;
    }
    if(fabs(p.y)<eps){
        if(p.x>0) return 0;
        else return pi;
    }
    double res = atan(p.y/(double)p.x);
    if(p.x<0) return res+pi;
    if(p.y<0) return res+2*pi;
    return res;
}
int solve(vector<double> v, double x){
    // cout<<"Solving...\n";
    // cout<<x<<endl;
    // for(auto t:v) cout<<t<<",";
    if(x-v[0]<-eps||x-v[top-1]>eps) return 0;
    if(fabs(x-v[0])<eps||fabs(x-v[top-1])<eps) return -1;
    int l=1,r=top-1,mid,ans;
    while(l<=r){
        mid=(l+r)/2;
        if(v[mid]>=x-eps) r=mid-1,ans=mid;
        else l=mid+1;
    }
    if(fabs(x-v[ans])<eps) return -1;
    return ans;
}
int main(){
    n=read();
    int Minx=inf,Miny=inf,id=0;
    for(int i=1;i<=n;++i){
        P[i].x=read();
        P[i].y=read();
        if(P[i].y<Miny||(P[i].y==Miny&&P[i].x<Minx)){
            Minx=P[i].x;
            Miny=P[i].y;
            id=i;
        }
    }
    swap(P[1],P[id]);
    sort(P+2,P+n+1,cmp);
    a[++top]=1; a[++top]=2;
    for(int i=3;i<=n;++i){
        while(top>=2&&Cross(P[i],P[a[top]],P[a[top-1]])>0) top--;
        a[++top]=i;
    }
    for(int i=1;i<=top;++i) q.push_back(P[a[i]]),P[a[i]].tag=true;
    ll ans = 0;
    for(int i=1;i<=n;++i) if(!P[i].tag){
        set<int> s;
        vector<double> v;
        for(auto p:q) v.push_back(ang(p-P[i]));
        sort(v.begin(),v.end());
        for(int j=1;j<=n;++j) if(!P[j].tag&&i!=j)
            s.insert(solve(v,ang(P[j]-P[i])));
        s.insert(-1);
        // cout<<"S: ";
        // for(auto xx:s) cout<<xx<<" ";
        // cout<<endl;
        // cout<<"P: "<<P[i].x<<" "<<P[i].y<<endl;
        ans += top+1-s.size();
        // cout<<ans<<endl;
    }
    cout<<ans+1;
}