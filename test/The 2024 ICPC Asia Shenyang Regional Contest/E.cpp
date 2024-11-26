#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=16;
const int M=1<<16;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
char s[4][4];
ll dis[N][M];
bool vis[N][M];
int n,m,Sta,a[9],sta[M];
int b[9]={1,2,4,8,5,10,3,12,15};
struct Node{
    int x,t;
    ll dis;
    friend bool operator<(Node A,Node B){
        return A.dis>B.dis;
    }
};
void Dijksta(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            dis[i][j]=1e18;
            vis[i][j]=0;
        }
    }
    priority_queue<Node>q;
    q.push((Node){15,0,0});
    dis[15][0]=0;
    while(q.size()){
        Node x=q.top();q.pop();
        if(vis[x.x][x.t])continue;
        vis[x.x][x.t]=1;
        // cout<<"Solve: "<<x.x<<" "<<x.t<<" "<<x.dis<<endl;
        for(int i=0;i<9;i++){
            Node y=(Node){x.x^b[i],x.t|(1<<(x.x^b[i])),x.dis+a[i]};
            // cout<<": "<<y.x<<" "<<y.t<<" "<<y.dis<<endl;
            if(dis[y.x][y.t]>y.dis){
                dis[y.x][y.t]=y.dis;
                q.push(y);
            }
        }
    }
}
int main(){
    int T=read();
    a[0]=a[1]=a[2]=a[3]=read();
    a[6]=a[7]=read();
    a[4]=a[5]=read();
    a[8]=read();
    Dijksta();
    for(int x=0;x<16;x++){
        for(int i=M-1;i>=0;i--){
            for(int j=0;j<16;j++){
                dis[x][i]=min(dis[x][i],dis[x][i|(1<<j)]);
            }
        }
    }
    while(T--){
        n=read();
        Sta=0;
        for(int i=0;i<n;i++){
            scanf("%s%s",s[0],s[1]);
            int x=(s[0][0]-'0')+(s[0][1]-'0')*2+(s[1][0]-'0')*4+(s[1][1]-'0')*8;
            Sta|=(1<<x);
        }
        ll ans=1e18;
        for(int i=0;i<16;i++)ans=min(ans,dis[i][Sta]);
        printf("%lld\n",ans);
    }
    return 0;
}