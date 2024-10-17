/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int MAXN=105;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int N,M,F,P,T;
int g[MAXN][MAXN],f[MAXN][MAXN];
int a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN],idx[MAXN][MAXN];
struct node{
    int type,idx,fmt;
};
struct Node{
    int x,y,d;
    vector<node>a;
}A[MAXN*MAXN],B[MAXN*MAXN];
void Input(){
	N=read();M=read();F=read();P=read();
    A[0].x=read()+1;A[0].y=read()+1;b[A[0].x][A[0].y]=1;
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)g[i][j]=read();
    for(int i=1;i<=M;i++){
        B[i].x=read()+1;B[i].y=read()+1;B[i].d=read();
        b[B[i].x][B[i].y]=2;idx[B[i].x][B[i].y]=i;
    }
    for(int i=0;i<F;i++)for(int j=0;j<F;j++)f[i][j]=read();
    //lost the accuracy but for speed
    F=1;
}
int newid[MAXN*MAXN];
void Output(){
    int cnt=0;
    for(int i=1;i<=T;i++)newid[i]=i;
    for(int i=1;i<=MAXN*MAXN;i++){
        cnt=0;
        for(int j=1;j<=T;j++)if(A[j].d)newid[j]=++cnt;
        for(int j=0;j<=T;j++){
            A[j].d=0;
            for(auto tmp:A[j].a){
                if(tmp.type==1)A[j].d++;
                else if(A[tmp.idx].d)A[j].d++;
            }
        }
    }
    printf("%d\n",cnt);
    //delete the wrong Transmitter
    for(int i=0;i<=T;i++){
        if(!A[i].d)continue;
        printf("%d %d %d",A[i].x-1,A[i].y-1,A[i].d);
        for(auto tmp:A[i].a){
            if(tmp.type==1)printf(" %d %d %d",tmp.type,tmp.idx,tmp.fmt);
            else if(A[tmp.idx].d){
                printf(" %d %d %d",tmp.type,newid[tmp.idx],tmp.fmt);
            }
        }
        puts("");
    }
}
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
struct DijNode{
    int x,y,fmt,d;
    ll dis;
    friend bool operator<(DijNode A,DijNode B){
        return A.dis>B.dis;
    }
};
ll dis[MAXN][MAXN][MAXN][4];
bool vis[MAXN][MAXN][MAXN][4];
DijNode pre[MAXN][MAXN][MAXN][4];
void Dijkstra(){
    priority_queue<DijNode>q;
    memset(dis,0x3f,sizeof(dis));
    for(int i=0;i<4;i++){
        for(int fmt=0;fmt<F;fmt++){
            q.push((DijNode){A[0].x,A[0].y,fmt,i,0});
            dis[A[0].x][A[0].y][fmt][i]=0;
        }
    }
    while(!q.empty()){
        DijNode X=q.top();q.pop();
        if(vis[X.x][X.y][X.fmt][X.d])continue;
        vis[X.x][X.y][X.fmt][X.d]=1;
        for(int i=0;i<4;i++){
            DijNode Y=(DijNode){X.x+dx[i],X.y+dy[i],0,i,X.dis};
            if(Y.x<1||Y.x>N||Y.y<1||Y.y>N)continue;
            for(int fmt=0;fmt<F;fmt++){
                Y.fmt=fmt;
                Y.dis=X.dis+g[Y.x][Y.y]+f[X.fmt][Y.fmt]+(X.d!=i)*P;
                if(Y.dis<dis[Y.x][Y.y][Y.fmt][Y.d]){
                    // cout<<"Dij: "<<X.x<<" "<<X.y<<" -> "<<Y.x<<" "<<Y.y<<" "<<Y.dis<<endl;
                    dis[Y.x][Y.y][Y.fmt][Y.d]=Y.dis;
                    pre[Y.x][Y.y][Y.fmt][Y.d]=X;
                    if(!b[Y.x][Y.y])q.push(Y);
                }
            }
        }
    }
}
void GetTree(){//jump on pre[][][][] and get c[][]
    for(int i=1;i<=M;i++){
        DijNode X=(DijNode){B[i].x,B[i].y,0,0,0};
        // DijNode X=(DijNode){B[i].x,B[i].y,B[i].d,0,0};
        for(int j=1;j<4;j++){
            if(dis[X.x][X.y][X.fmt][j]<dis[X.x][X.y][X.fmt][X.d])X.d=j;
        }
        while(1){
            if(c[X.x][X.y])break;
            c[X.x][X.y]=1;
            if(X.x==A[0].x&&X.y==A[0].y)break;
            // cout<<"pre: "<<X.x<<" "<<X.y<<" ";
            X=pre[X.x][X.y][X.fmt][X.d];
            // cout<<X.x<<" "<<X.y<<endl;
        }
    }
    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=N;j++)cout<<c[i][j]<<" ";cout<<endl;
    // }
}
int vst[MAXN][MAXN],degvis[MAXN][MAXN];
struct Point{int x,y,d,lst;};
void GetAnswer(){//BFS
    queue<Point>q;
    q.push((Point){A[0].x,A[0].y,0,0});
    vst[A[0].x][A[0].y]=degvis[A[0].x][A[0].y]=1;
    while(!q.empty()){
        Point X=q.front();q.pop();
        // cout<<"BFS: "<<X.x<<" "<<X.y<<" "<<X.d<<" "<<X.lst<<endl;
        for(int i=0;i<4;i++){
            Point Y=(Point){X.x+dx[i],X.y+dy[i],i,X.lst};
            if(!c[Y.x][Y.y]||vst[Y.x][Y.y])continue;
            if(b[Y.x][Y.y]==2){//User
                //X.lst point to this User
                if(X.d!=i&&(A[X.lst].x!=X.x||A[X.lst].y!=X.y))continue;
                //if X is not a Transmitter and X can't arrive at Y
                int id=idx[Y.x][Y.y];
                A[X.lst].d++;
                A[X.lst].a.push_back((node){1,id,B[id].d});
                vst[Y.x][Y.y]=1;
            }
            else{//Others
                int deg=0,d=0;
                for(int j=0;j<4;j++){
                    Point Z=(Point){Y.x+dx[j],Y.y+dy[j],j,Y.lst};
                    if(c[Z.x][Z.y]&&!vst[Z.x][Z.y]&&!degvis[Z.x][Z.y]){
                        deg++;d=j;degvis[Z.x][Z.y]=1;
                    }
                }
                if(deg>=2||(deg==1&&d!=i)){
                    //Get a new Transmitter
                    T++;
                    A[T].x=Y.x;A[T].y=Y.y;
                    Y.lst=T;
                    //X.lst point to the new Transmitter
                    A[X.lst].d++;
                    A[X.lst].a.push_back((node){0,T,0});
                }
                if(!vst[Y.x][Y.y]){
                    q.push((Point){Y.x,Y.y,Y.d,Y.lst});
                    vst[Y.x][Y.y]=1;
                }
            }
        }
    }
}
void Solve(){
    Dijkstra();
    GetTree();
    GetAnswer();
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
    Input();
    Solve();
    Output();
	return 0;
}
