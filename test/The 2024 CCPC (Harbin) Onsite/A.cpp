#include <bits/stdc++.h>
using namespace std;
#define int long long

int fuck = 1;

class node
{
public:
    node* l;
    node* r;
    int id;
    node()
    {
        l=r=nullptr;
        id = ++fuck;
    }
    node(int f)
    {
        l=r=nullptr;
        id = f;
    }
};

vector<node*> T;

const int inf = (1ll<<61)-1;

node* solve(int l,int r,int bit,bool sig=false)
{
    node* tmp;
    if(sig) tmp = new node(2);
    else tmp = new node();

    int L = (bool)(l&(1ll<<bit));
    int R = (bool)(r&(1ll<<bit));


    if(bit==0)
    {
        if(L==R)
        {
            if(L)
            {
                tmp->r = T[90];
                return tmp;
            }
            else
            {
                tmp->l = T[90];
                return tmp;
            }
        }
        else
        {
            tmp->l = tmp->r = T[90];
            return tmp;
        }
    }

    if(L==R)
    {
        if(L)
        {
            tmp->r = solve(l,r,bit-1);
        }
        else
        {
            tmp->l = solve(l,r,bit-1);
        }
    }
    else if(r==inf)
    {
        tmp->l = solve(l,inf,bit-1);
        tmp->r = T[bit];
    }
    else if(l==0)
    {
        tmp->r = solve(0,r,bit-1);
        tmp->l = T[bit];
    }
    else
    {
        tmp->l = solve(l,inf,bit-1);
        tmp->r = solve(0,r,bit-1);
    }

    return tmp;

}

vector<pair<int,int> > vt[100000];

int mxn = 0;

void dfs(node* x)
{
    if(x->id!=10090&&x->id>=10000)
    {
        mxn = max(mxn,x->id-10000);
    }
    if(x->l!=nullptr)
    {
        vt[x->id].emplace_back(x->l->id,0);
        dfs(x->l);
    }
    if(x->r!=nullptr)
    {
        vt[x->id].emplace_back(x->r->id,1);
        dfs(x->r);
    }
}

int tid(int x)
{
    if(x==10090||x==10000) return 1;
    if(x>=10000) return fuck + x - 10000;
    return x;
}

int highbit(int x)
{
    for(int i=60;i>=0;--i)
    {
        if(x&(1ll<<i))
        {
            return i;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int l,r;
    cin>>l>>r;

    for(int i=0;i<=100;++i) T.push_back(new node(i+1e4));

    int ll = highbit(l);
    int rr = highbit(r);

    if(ll==rr)
    {
        node* ans = solve(l,r,ll);
        dfs(ans);
    }
    else
    {
        node* ans1 = solve(l,inf,ll);
        node* ans3 = solve(0,r^(1ll<<rr),rr-1);
        node* ans2 = new node(2);
        ans2->r = ans3;
        dfs(ans1);
        dfs(ans2);

        for(int i=ll+1;i<rr;++i)
        {
            vt[2].emplace_back(10000+i,1);
            mxn=max(mxn,i);
        }
    }

    cout<<fuck+mxn<<"\n";

    cout<<"0\n";

    for(int i=2;i<=fuck;++i)
    {
        cout<<vt[i].size();
        for(auto i:vt[i])
        {
            cout<<" "<<tid(i.first)<<" "<<i.second;
        }
        cout<<"\n";
    }

    for(int i=1;i<=mxn;++i)
    {
        cout<<"2 ";
        cout<<tid(10000+i-1)<<" 0 "<<tid(10000+i-1)<<" 1\n";
    }


}
