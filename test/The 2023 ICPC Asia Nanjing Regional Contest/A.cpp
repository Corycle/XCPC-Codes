#pragma GCC optimize("unroll-lopps")
#pragma GCC target("avx2,bmi,popcnt,fma")
#include<bits/stdc++.h>
using namespace std;
const int maxn=4e3+5;
char mp[maxn][maxn];
int fx[4][2];
bitset<maxn>bs [maxn];
int n,m;
int bmap(int x,int y)
{
    return (x+n-1)*(2*m)+y+m-1;
}
void bfs(int x,int y)
{
    queue<pair<int,int> >q;
    q.emplace(x,y);
    auto& b=bs[bmap(x,y)];
    b[bmap(0,0)]=1;
    while(!q.empty())
    {
        auto tmp=q.front();
        q.pop();
        for(int k=0;k<4;++k)
        {
            int xx=tmp.first+fx[k][0]-x;
            int yy=tmp.second+fx[k][1]-y;
            if(mp[xx+x][yy+y]=='.' && b[bmap(xx,yy)]==0)
            {
                b[bmap(xx,yy)]=1;
                q.emplace(xx+x,yy+y);
            }
        }
    }
}
bool bit(bitset<maxn>&a,bitset<maxn>&b)
{
    return b==(a|b);
}
void mian()
{
    cin>>n>>m;
    for(int i=0;i<=n+1;++i)
    {
        for(int j=0;j<=m+1;++j)
        {
            mp[i][j]=0;
        }
    }
    for(int i=1;i<=n;++i)
    {
        cin>>(mp[i]+1);
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(mp[i][j]=='.') bs[bmap(i,j)]^=bs[bmap(i,j)],bfs(i,j);
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            //cout<<"t: "<<bs[bmap(i,j)]<<endl;
            if(mp[i][j]!='.') continue;
            int can=0;
            for(int k=1;k<=n;++k)
            {
                for(int l=1;l<=m;++l)
                {
                    if(mp[k][l]!='.') continue;
                    if(i!=k || j!=l) can=can | bit(bs[bmap(i,j)],bs[bmap(k,l)]);
                }
            }
            if(can==0)
            {
                ++ans;
            }
        }
    }
    cout<<ans<<"\n";
}
signed main()
{
    fx[0][0]=1;
    fx[0][1]=0;
    fx[1][0]=-1;
    fx[1][1]=0;
    fx[2][0]=0;
    fx[2][1]=1;
    fx[3][0]=0;
    fx[3][1]=-1;
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        mian();
    }
    return 0;
}