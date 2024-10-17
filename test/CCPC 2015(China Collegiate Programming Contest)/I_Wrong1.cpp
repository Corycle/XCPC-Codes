/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int Mod=1e9+7;
const int N=205;
const int M=70;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int n,m,f[2][N][M][5][5][5],g[2][N][M][5][5][5];
int mod(int x){return x>=Mod?x-Mod:x;}
void Update(int t,int i,int j,int x,int y,int dx,int dy,int dz){
	if(x+dx>4||y+dy>4)return;
	int sum=(dx+dy+dz)/3,op=((dx+dy+dz)%3==2),z=4-dz;
	for(int k=0;k<=4;k++){
		f[t][i][j][x][y][z]=mod(f[t][i][j][x][y][z]+f[t^op][i-1][j-sum][k][x+dx][y+dy]);
	}
}
void Prepare(){
	f[0][3][0][4][4][4]=1;
	f[0][3][1][1][4][4]=1;
	f[0][3][2][0][3][3]=1;
	f[0][3][1][3][3][3]=1;
	f[0][3][2][2][2][2]=1;
	f[0][3][3][1][1][1]=1;
	f[0][3][4][0][0][0]=1;
	f[1][3][0][2][4][4]=1;
	f[1][3][1][1][3][3]=1;
	f[1][3][2][0][2][2]=1;
	for(int i=4;i<N;i++){
		for(int j=0;j<M;j++){
			for(int x=0;x<=4;x++){
				for(int y=0;y<=4;y++){
					for(int t=0;t<2;t++){
						Update(t,i,j,x,y,0,0,0);
						Update(t,i,j,x,y,3,0,0);
						Update(t,i,j,x,y,4,1,1);
						Update(t,i,j,x,y,1,1,1);
						Update(t,i,j,x,y,2,2,2);
//						Update(t,i,j,x,y,3,3,3);
//						Update(t,i,j,x,y,4,4,4);
					}
					Update(1,i,j,x,y,2,0,0);
					Update(1,i,j,x,y,3,1,1);
					Update(1,i,j,x,y,4,2,2);
				}
			}
		}
	}
	memcpy(g,f,sizeof(g));
}
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	Prepare();
	int T=read();
	for(int Case=1;Case<=T;Case++){
		n=read();m=read();
		printf("Case #%d: ",Case);
		if(m==2){printf("%d\n",n);continue;}
		if(n==2&&m==5){puts("2");continue;}
		int ans=0;m/=3;
		for(int t=0;t<2;t++)memcpy(f[t][n],g[t][n],sizeof(f[t][n]));
		for(int i=n+1;i<=n+2;i++){
			for(int t=0;t<2;t++)memset(f[t][i],0,sizeof(f[t][i]));
			for(int j=0;j<M;j++){
				for(int x=0;x<=4;x++){
					for(int y=0;y<=4;y++){
						for(int t=0;t<2;t++){
							Update(t,i,j,x,y,0,0,0);
							Update(t,i,j,x,y,3,0,0);
//							Update(t,i,j,x,y,4,1,1);
//							Update(t,i,j,x,y,1,1,1);
//							Update(t,i,j,x,y,2,2,2);
//							Update(t,i,j,x,y,3,3,3);
//							Update(t,i,j,x,y,4,4,4);
						}
						Update(1,i,j,x,y,2,0,0);
//						Update(1,i,j,x,y,3,1,1);
//						Update(1,i,j,x,y,4,2,2);
					}
				}
			}
		}
		for(int x=0;x<=4;x++)ans=mod(ans+f[1][n+2][m][x][4][4]);
		printf("%d\n",ans);
	}
	return 0;
}
