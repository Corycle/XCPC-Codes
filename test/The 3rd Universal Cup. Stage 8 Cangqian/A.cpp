#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=4e6+5;
int ptr,ed;
char n[maxn];
char lastn[maxn];
void add(__int128 tba)
{
    for(int i=ptr;i<ed;++i) lastn[i]=n[i];
    int p = ed-1;
    for(;p>=ptr;--p)
    {
        tba=tba+(n[p]-'0');
        n[p] = (char)(tba%10+'0');
        tba=tba/10;
    }
    while(tba!=0)
    {
        ptr--;
        n[ptr]=(char)(tba%10+'0');
        tba=tba/10;
    }
}
void ctrlZ(){
    for(int i=ptr;i<ed;++i) n[i]=lastn[i];
}
string ts(int t)
{
    stringstream ss;
    ss<<t;
    string tt;
    ss>>tt;
    return tt;
}
void mian()
{
    ptr = 1145;
    int m;
    cin>>(n+ptr)>>m;

    for(int i=0;i<=30;++i)
    {
        n[--ptr] = '0';
    } 

    string M=ts(m);

    for(ed=ptr;n[ed]!='\0';++ed);

    add(1);

    for(int i=ptr;i<ed;++i)
    {
        int j = i;
        bool ist = true;
        for(auto k:M)
        {
            if(n[j++]!=k) ist = false;
        }
        if(ist)
        {
            bool top = false;
            for(int i=ptr;i<ed;++i)
            {
                if(n[i]!='0') top=true;
                if(top) cout<<n[i];
            }
            cout<<"\n";
            return;
        }
    }

    __int128 sto=2*m;
    for(__int128 k=1;k<=m;k*=10){
        add(k);
            for(int i=ptr;i<ed;++i)
            {
                int j = i;
                bool ist = true;
                for(auto k:M)
                {
                    if(n[j++]!=k) ist = false;
                }
                if(ist)
                {
                    sto=min(sto,k);
                }
            }
        ctrlZ();
    }

    string fuck = "0";
    for(int i=1;i<=18;++i) fuck.push_back(n[ed-19+i]);

    //cout<<fuck<<endl;

    int lgm = M.size();

    string ff = "1";
    for(int i=1;i<=18;++i) ff.push_back('9');

    for(int i=1;i<=19-lgm;++i)
    {
        string F = fuck;
        for(int j=0;j<lgm;++j)
        {
            F[i+j] = M[j];
        }

        //cout<<F<<endl;

        for(int j=lgm;i+j<19;++j)
        {
            F[i+j]='0';
        }
        
        if(F>fuck)
        {
            ff = min(ff,F);
        }

    }
    //cout<<ff<<endl;

    __int128 orz = 0;
    
    for(int i=0;i<19;++i)
    {
        orz=(orz*10)+(ff[i]-(int )fuck[i]);
    }


    __int128 md=0;
    for(int i=ptr;i<ed;++i)
    {
        md = ((md*10) + n[i]-'0')%m;
    }

    md = (m*10-md)%m;

    //cout<<"shit "<<(int)orz<<" "<<(int)md<<endl;

    md=min(md,orz);
    md=min(md,sto);

    add(md);

    bool top = false;

    for(int i=ptr;i<ed;++i)
    {
        if(n[i]!='0') top=true;
        if(top) cout<<n[i];
    }

    cout<<'\n';

}
signed main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        mian();
    }
    return 0;
}