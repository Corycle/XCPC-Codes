/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=1005;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
bool Flag;
char a[N][N];
int n,m,num,vis[N][N][4],to[N][N][4],vst[N][N],ans[N][N][4];
void DFS(int x,int y,int dir,int flag){
    if(flag)ans[x][y][dir]=num;
    if(!vst[x][y]&&to[x][y][dir]!=(dir^2)){
        vst[x][y]=1;
        num++;
    }
    if(vis[x][y][dir]){
        ans[x][y][dir]=ans[x][y][to[x][y][dir]]=num;
        return;
    }
    vis[x][y][dir]=1;
    int tx=x,ty=y,tdir=to[x][y][dir]^2;
    if(to[x][y][dir]==0)tx--;
    if(to[x][y][dir]==1)ty++;
    if(to[x][y][dir]==2)tx++;
    if(to[x][y][dir]==3)ty--;
    if(tx>=1&&tx<=n&&ty>=1&&ty<=m){
        DFS(tx,ty,tdir,flag);
    }
    else Flag=false;
    if(flag){
        if(Flag)ans[x][y][to[x][y][dir]]=num;
    }
    else ans[x][y][dir]=ans[x][y][to[x][y][dir]]=num;
    vis[x][y][dir]=0;
    vst[x][y]=0;
}
char s[10];
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++){
        scanf("%s",a[i]+1);
        for(int j=1;j<=m;j++){
            if(a[i][j]=='-'){
                to[i][j][0]=0;to[i][j][1]=3;to[i][j][2]=2;to[i][j][3]=1;
            }
            if(a[i][j]=='|'){
                to[i][j][0]=2;to[i][j][1]=1;to[i][j][2]=0;to[i][j][3]=3;
            }
            if(a[i][j]=='\\'){
                to[i][j][0]=1;to[i][j][1]=0;to[i][j][2]=3;to[i][j][3]=2;
            }
            if(a[i][j]=='/'){
                to[i][j][0]=3;to[i][j][1]=2;to[i][j][2]=1;to[i][j][3]=0;
            }
        }
    }
    memset(ans,-1,sizeof(ans));
    for(int i=1;i<=m;i++){
        num=0;Flag=true;DFS(1,i,0,1);
        num=0;Flag=true;DFS(n,i,2,1);
    }
    for(int i=1;i<=n;i++){
        num=0;Flag=true;DFS(i,1,3,1);
        num=0;Flag=true;DFS(i,m,1,1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // cout<<'('<<i<<","<<j<<") :: ";
            for(int k=0;k<4;k++){
                if(ans[i][j][k]==-1){
                    num=0;
                    DFS(i,j,k,0);
                }
                // cout<<ans[i][j][k]<<" ";
            }
            // cout<<endl;
        }
    }
    int T=read();
    while(T--){
        int x=read(),y=read(),dir=0;
        scanf("%s",s);
        if(s[0]=='a')dir=0;
        if(s[0]=='b')dir=2;
        if(s[0]=='l')dir=3;
        if(s[0]=='r')dir=1;
        printf("%d\n",ans[x][y][dir]);
    }
	return 0;
}
