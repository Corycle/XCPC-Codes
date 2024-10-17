#include<bits/stdc++.h>
using namespace std;
#define int long long

map<string,int> mp;
//我们知道子年(Zi)数一、丑年(Chou)数二、寅年(Yin)数三、卯年(Mao)数四、辰年(Chen)数五、巳年(Si)数六、午年(Wu)数七、未年(Wei)数八、申年(Shen)数九、酉年(You)数十、戌年(Xu)数十一、亥年(Hai)数十二。
signed main()
{
mp["zi"]=1;
mp["chou"]=2;
mp["yin"]=3;
mp["mao"]=4;
mp["chen"]=5;
mp["si"]=6;
mp["wu"]=7;
mp["wei"]=8;
mp["shen"]=9;
mp["you"]=10;
mp["xu"]=11;
mp["hai"]=12;

string shit[2];
shit[0]="- -";
shit[1]="---";

//乾（☰）、兑（☱）、离（☲）、震（☳）、巽（☴）、坎（☵）、艮（☶）、坤（☷）。

map<int,vector<int> > gua;
gua[0] = vector<int>{0,0,0};

gua[1] = vector<int>{1,1,1};

gua[2] = vector<int>{0,1,1};

gua[3] = vector<int>{1,0,1};

gua[4] = vector<int>{0,0,1};

gua[5] = vector<int>{1,1,0};

gua[6] = vector<int>{0,1,0};

gua[7] = vector<int>{1,0,0};


    ios::sync_with_stdio(0);
    string yy;
    cin>>yy;
    for(auto& i : yy) i = tolower(i);
    int y=mp[yy];
    int m,d;
    cin>>m>>d;
    string hh;
    cin>>hh;
    for(auto& i : hh) i = tolower(i);
    int h=mp[hh];

    int shang = (y+m+d)%8;
    int xia=  (y+m+d+h)%8;

    vector<int> vt;

    vt.push_back(1);

    for(auto i: gua[shang])
    {
        cout<<shit[i]<<"\n";
        vt.push_back(i);
    }

    for(auto i: gua[xia])
    {
        cout<<shit[i]<<"\n";
        vt.push_back(i);
    }

    cout<<endl;

    int del =  (y+m+d+h)%6;

    if(del==0) del = 6;

    vt[7 - del] = 1 - vt[7-del];

    for(int i=1;i<=6;++i)
    {
        cout<<shit[vt[i]]<<endl;
    }

    return 0;
}