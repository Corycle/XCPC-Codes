#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
const int N = 200005, inf = 8e18;
struct Point{int x,y;signed level;}P[N];
int Cross(Point A,Point B,Point C){
    return (A.x-C.x)*(B.y-C.y)-(A.y-C.y)*(B.x-C.x);
}
double disl(Point A,Point B){
    return sqrt((double)(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
int Area(Point A,Point B,Point C){
    // cout<<"AREA" <<A.x<<" "<<A.y<<" "<<B.x<<" "<<B.y<<" "<<C.x<<" "<<C.y<<" "<< abs(Cross(A,B,C))<<endl;
    return abs(Cross(A,B,C));
}
double dis(Point A,Point B,Point C){
    return Area(A,B,C)/disl(B,C);
}
bool cmp(Point A,Point B){
    if(A.level!=B.level) return A.level<B.level;
    int tmp=Cross(A,B,P[1]);
    if(tmp>0) return true;
    else return false;
}
vector<Point> v1,v2;
int ans[N];
int tuosh(){
    int n1 = v1.size();
    int n2 = v2.size();
    int res = 0;
    for(int i=0;i<n1;++i) if(dis(v1[i],v2[1],v2[2])<=dis(v1[(i+1)%n1],v2[1],v2[2]) && dis(v1[i],v2[1],v2[2])<=dis(v1[(i-1+n1)%n1],v2[1],v2[2])) ans[1]=i;
    res = Area(v2[1],v2[2],v1[ans[1]]);
    for(int i=1;i<n2;++i){
        int j=ans[i-1];
        do{
            if(dis(v1[j],v2[i],v2[(i+1)%n2])<=dis(v1[(j+1)%n1],v2[i],v2[(i+1)%n2]) && dis(v1[j],v2[i],v2[(i+1)%n2])<=dis(v1[(j-1+n1)%n1],v2[i],v2[(i+1)%n2])){
                ans[i]=j;
                res = min(res, Area(v2[i],v2[(i+1)%n2],v1[ans[i]]));
                break;
            }
            j=(j+1)%n1;
        }while(j!=ans[i-1]);
    }
    return res;
}
int a[N],top;
void work(){
    v1.clear();v2.clear();
    int n=read();
    int Minx,Miny,id;
    Minx=Miny=inf;
    for(int i=1;i<=n;++i){
        P[i].x=read(),P[i].y=read();
        P[i].level=0;
        if(P[i].y<Miny||(P[i].y==Miny&&P[i].x<Minx)){
            Minx=P[i].x;
            Miny=P[i].y;
            id=i;
        }
    }
    swap(P[1],P[id]);
    sort(P+2,P+n+1,cmp);
    top=0;
    a[++top]=1;a[++top]=2;
    for(int i=3;i<=n;++i){
        while(top>=2&&Cross(P[i],P[a[top]],P[a[top-1]])>=0) top--;
        a[++top]=i;
    }
    for(int i=1;i<=top;++i) P[a[i]].level=2, v2.push_back(P[a[i]]);


    int n2=0;
    for(int i=1;i<=n;++i) if(!P[i].level) ++n2;
    if(n2==0){
        puts("-1");
        return;
    }
    int minT = 8e18;
    if(n2==1){
        int m = v2.size();
        Point p;
        for(int i=1;i<=n;++i) if(!P[i].level) p=P[i];
        minT = Area(p,v2[0],v2[m-1]);
        for(int i=0;i<m-1;++i) minT=min(minT,Area(p,v2[i],v2[i+1]));
    }
    else if(n2==2){
        int m = v2.size();
        Point p;
        // cout<<"_____";
        for(int i=1;i<=n;++i) if(!P[i].level) p=P[i];
        minT = Area(p,v2[0],v2[m-1]);
        for(int i=0;i<m-1;++i) minT=min(minT,Area(p,v2[i],v2[i+1]));
        for(int i=1;i<=n;++i) if(!P[i].level) {p=P[i];break;}
        minT = min(minT,Area(p,v2[0],v2[m-1]));
        for(int i=0;i<m-1;++i) minT=min(minT,Area(p,v2[i],v2[i+1]));
        // cout<<"minT="<<minT<<endl;
    }
    else{
        Minx=Miny=inf;
        for(int i=1;i<=n;++i){
            if(P[i].level) continue;
            if(P[i].y<Miny||(P[i].y==Miny&&P[i].x<Minx)){
                Minx=P[i].x;
                Miny=P[i].y;
                id=i;
            }
        }
        swap(P[1],P[id]);
        sort(P+2,P+n+1,cmp);
        top=0;
        a[++top]=1;a[++top]=2;
        for(int i=3;i<=n2;++i){
            while(top>=2&&Cross(P[i],P[a[top]],P[a[top-1]])>=0) top--;
            a[++top]=i;
        }
        for(int i=1;i<=top;++i) v1.push_back(P[a[i]]);
        minT = tuosh();
    }

    int ans = 0;
    // cout<<"____"<<minT;
    int m = v2.size();
    for(int i=1;i<m-1;++i) ans+=Area(v2[0],v2[i],v2[i+1]);
    printf("%lld\n",ans-minT);
}
signed main(){
    int T=read();
    while(T--) work(),Clear();
}