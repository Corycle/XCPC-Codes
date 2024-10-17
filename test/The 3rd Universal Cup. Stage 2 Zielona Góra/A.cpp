#include <bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
vector<int>vt[maxn];
vector<int>tv[maxn];
int good[maxn],doog[maxn];
void dfs(int x)
{
    good[x]=1;
    for(auto i:vt[x])
    {
        if(good[i]==0)
        {
            dfs(i);
        }
    }
}
void dfs2(int x)
{
    doog[x]=1;
    for(auto i:tv[x])
    {
        if(doog[i]==0)
        {
            dfs2(i);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        vt[a].push_back(b);
        tv[b].push_back(a);
    }
    dfs(1);dfs2(n);
    int V=0,E=0;
    for(int i=1;i<=n;++i)
    {
        if(good[i]&&doog[i]) V++;
        for(auto j:vt[i])
        {
            if(good[i]&&doog[i]&&good[j]&&doog[j])
            {
                E++;
            }
        }
    }
    cout<<(good[1]&&doog[1]&&good[n]&&doog[n]?E-V+2:0);
    return 0;
}