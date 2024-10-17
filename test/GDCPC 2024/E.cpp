#include <bits/stdc++.h>
using namespace std;
const int maxn=55;
int mp[maxn][maxn];
int main()
{
    //freopen("shit.in","r",stdin);
    ios::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;

    int fx[4][2];
    fx[0][0]=1;
    fx[0][1]=0;
    fx[1][0]=-1;
    fx[1][1]=0;
    fx[2][0]=0;
    fx[2][1]=1;
    fx[3][0]=0;
    fx[3][1]=-1;

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>mp[i][j];
        }
    }

    int mn=INT_MAX/3;


    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {

            //cout<<"test "<<i<<" "<<j<<endl;
            queue<pair<int,int> > q[maxn*3];
            int dis[maxn][maxn];
            for(int k=1;k<maxn;++k)
            {
                for(int l=1;l<maxn;++l)
                {
                    dis[k][l]=INT_MAX/3;
                }
            }
            q[0].emplace(make_pair(i,j));
            dis[i][j]=0;

            int mx = 0;

            int cnt=0;

            while(cnt<maxn*3)
            {
                if(q[cnt].empty())
                {++cnt; continue;}
                int a = q[cnt].front().first;
                int b=q[cnt].front().second;
                mx=max(mx,dis[a][b]+(mp[a][b]));
                q[cnt].pop();
                for(int f=0;f<4;++f)
                {
                    int c=a+fx[f][0];
                    int d=b+fx[f][1];

                    if(c<=0||d<=0||c>n||d>m) continue;
                    int del = (mp[a][b]!=mp[c][d]);
                    if(dis[c][d]>dis[a][b]+del)
                    {
                        dis[c][d] = dis[a][b]+del;
                        q[dis[c][d]].emplace(c,d);
                    }
                }
            }


            mn=min(mn,mx);

            //cout<<mx<<endl;
        }
    }

    cout<<mn;

    cout<<endl;
}
