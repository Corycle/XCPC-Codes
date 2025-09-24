#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e18;
const int MAP_SIZE=10;
const int MAXN=1e5+5;
const int PLANE_NUM=3;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
struct Point{
    int x,y;
    Point(int X=0,int Y=0):x(X),y(Y){}
    friend Point operator+(Point A,Point B){return Point(A.x+B.x,A.y+B.y);}
    friend Point operator-(Point A,Point B){return Point(A.x-B.x,A.y-B.y);}
    friend Point operator*(Point A,int x){return Point(A.x*x,A.y*x);}
};
struct Node{Point A;int t;}p[PLANE_NUM];
int n,m,a[MAP_SIZE][MAP_SIZE][2];
unordered_set<int> h[MAP_SIZE][MAP_SIZE][2];
bool Map(Point A){
    if(A.x<0||A.x>=MAP_SIZE||A.y<0||A.y>=MAP_SIZE)return true;
    return a[A.x][A.y][0]|a[A.x][A.y][1];
}
void MapUpdate(Point A,int d,int id=-1,int w=0){
    a[A.x][A.y][w]+=d;
    if(id!=-1){
        if(d==1)h[A.x][A.y][w].insert(id);
        if(d==-1)h[A.x][A.y][w].erase(id);
    }
}
bool Check(int x,int y,int t){
    Point A(x,y),D(dx[t],dy[t]),U(dx[t^2],dy[t^2]),L(dx[t^1],dy[t^1]),R(dx[t^3],dy[t^3]);
    return !(Map(A)|Map(A+D)|Map(A+D*2)|Map(A+D*3)|Map(A+D+L)|Map(A+D+L*2)|Map(A+D+R)|Map(A+D+R*2)|Map(A+D*3+L)|Map(A+D*3+R));
}
void Update(int x,int y,int t,int d,int id=-1){
    Point A(x,y),D(dx[t],dy[t]),U(dx[t^2],dy[t^2]),L(dx[t^1],dy[t^1]),R(dx[t^3],dy[t^3]);
    MapUpdate(A,d,id,1);
    MapUpdate(A+D,d,id);
    MapUpdate(A+D*2,d,id);
    MapUpdate(A+D*3,d,id);
    MapUpdate(A+D+L,d,id);
    MapUpdate(A+D+L*2,d,id);
    MapUpdate(A+D+R,d,id);
    MapUpdate(A+D+R*2,d,id);
    MapUpdate(A+D*3+L,d,id);
    MapUpdate(A+D*3+R,d,id);
}
struct States{
    int id,hash;
    Node a[PLANE_NUM];
    States(){}
    States(Node* A,int ID):id(ID){
        hash=0;
        for(int i=0;i<PLANE_NUM;i++){
            a[i]=A[i];
            hash=hash*100+A[i].A.x*10+A[i].A.y;
        }
    }
    void update(int d){
        for(int i=0;i<PLANE_NUM;i++){
            Update(a[i].A.x,a[i].A.y,a[i].t,d,id);
        }
    }
};
vector<States> S;
void PrintA(){
    for(int i=0;i<MAP_SIZE;i++){
        for(int j=0;j<MAP_SIZE;j++)cout<<a[i][j][0]<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<MAP_SIZE;i++){
        for(int j=0;j<MAP_SIZE;j++)cout<<a[i][j][1]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
void DFS(int x,int y,int num){
    if(num==PLANE_NUM){
        S.push_back(States(p,n++));
        return;
    }
    if(y==MAP_SIZE){DFS(x+1,0,num);return;}
    if(x==MAP_SIZE)return;
    DFS(x,y+1,num);
    if(Map((Point){x,y}))return;
    for(int i=0;i<4;i++){
        if(Check(x,y,i)){
            Update(x,y,i,1);
            p[num]=(Node){(Point){x,y},i};
            DFS(x,y+1,num+1);
            Update(x,y,i,-1);
        }
    }
}
multiset<int> F;
unordered_set<int> resID;
void Prepare(){
    DFS(0,0,0);
    cout<<"n="<<n<<endl;
    for(auto& s:S){
        s.update(1);
        F.insert(s.hash);
        resID.insert(s.id);
    }
    m=n;
}
bool vis[MAP_SIZE][MAP_SIZE],vst[MAXN];
ll Val(int x,int y){
    ll a1=a[x][y][0]*3,a2=a[x][y][1]*3,a0=m*3-a1-a2;
    if(m<=10)return -a2;
    return (a0-m)*(a0-m)*5+(a1-m)*(a1-m)*5+(a2-m)*(a2-m);
}
int Ask(int x,int y){
    cout<<(char)('a'+y)<<x+1<<endl;
    int t;
    cin>>t;
    return t;
}
void Work(){
    while(1){
        PrintA();
        ll minVal=inf;
        int x=-1,y=-1;
        for(int i=0;i<MAP_SIZE;i++){
            for(int j=0;j<MAP_SIZE;j++){
                if(vis[i][j])continue;
                ll v=Val(i,j);
                if(minVal>v){minVal=v;x=i;y=j;}
            }
        }
        if(minVal==inf)break;
        vis[x][y]=1;
        int t=Ask(x,y);
        if(t){
            for(int i=0;i<2;i++){
                if(i+1!=t)continue;
                for(auto k:h[x][y][i])vst[k]=1;
            }
        }
        else{
            for(auto k:resID)vst[k]=1;
            for(int i=0;i<2;i++){
                for(auto k:h[x][y][i])vst[k]=0;
            }
        }
        unordered_set<int> tmp=resID;
        for(auto k:tmp){
            if(vst[k])continue;
            S[k].update(-1);
            F.erase(F.find(S[k].hash));
            resID.erase(k);
            m--;
        }
        for(auto k:resID)vst[k]=0;
        if((*F.begin())==(*F.rbegin()))break;
    }
    for(int i=0;i<MAP_SIZE;i++){
        for(int j=0;j<MAP_SIZE;j++){
            if(vis[i][j])continue;
            if(h[i][j][1].size())Ask(i,j);
        }
    }
}
int main(){
    Prepare();
    Work();
	return 0;
}
