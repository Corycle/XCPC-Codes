#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int> > A,B;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
void mian()
{
    A.clear();B.clear();
    int n,k;n=read();k=read();
    for(int i=1;i<=n;++i)
    {
        int c,w,f;
        c=read();w=read();f=read();
        if(w==2)
        {
            A.push_back(make_pair(f,c));
        }
        else
        {
            B.push_back(make_pair(f,c));
        }
    }
    if(!A.empty()) sort(A.begin(),A.end());
    if(!B.empty()) sort(B.begin(),B.end());
    int ans=0,dtc=k,cntA=((int)A.size())-1,cntB=((int)B.size())-1;
    while(cntA>=0&&cntB>=0){
        if(A[cntA]>=B[cntB]){
            if(dtc>=A[cntA].second*2){
                if(dtc==k) ans+=A[cntA].first;
                dtc-=A[cntA].second*2;
                --cntA;
            }
            else{
                if(dtc==k) ans+=A[cntA].first;
                A[cntA].second-=dtc/2;
                if(dtc&1){
                    B[cntB].second--;
                    if(B[cntB].second==0) --cntB;
                }
                dtc=k;

                int num=A[cntA].second*2/k;
                ans+=num*A[cntA].first;
                A[cntA].second%=k/2;
                if(A[cntA].second==0) --cntA;
            }
        }
        else{
            if(dtc>=B[cntB].second){
                if(dtc==k) ans+=B[cntB].first;
                dtc-=B[cntB].second;
                --cntB;
            }
            else{
                if(dtc==k) ans+=B[cntB].first;
                B[cntB].second-=dtc;
                dtc=k;

                int num=B[cntB].second/k;
                ans+=num*B[cntB].first;
                B[cntB].second%=k;
                if(B[cntB].second==0) --cntB;
            }
        }
    }
    while(cntA>=0){
        if(dtc>=A[cntA].second*2){
            if(dtc==k) ans+=A[cntA].first;
            dtc-=A[cntA].second*2;
            --cntA;
        }
        else{
            if(dtc==k) ans+=A[cntA].first;
            A[cntA].second-=dtc/2;
            dtc=k;

            int num=A[cntA].second*2/k;
            ans+=num*A[cntA].first;
            A[cntA].second%=k/2;
            if(A[cntA].second==0) --cntA;
        }
    }
    while(cntB>=0){
        if(dtc>=B[cntB].second){
            if(dtc==k) ans+=B[cntB].first;
            dtc-=B[cntB].second;
            --cntB;
        }
        else{
            if(dtc==k) ans+=B[cntB].first;
            B[cntB].second-=dtc;
            dtc=k;

            int num=B[cntB].second/k;
            ans+=num*B[cntB].first;
            B[cntB].second%=k;
            if(B[cntB].second==0) --cntB;
        }
    }
    printf("%lld\n",ans);
}
signed main()
{
    // ios::sync_with_stdio(0);
    int t;
    t=read();
    for(int i=1;i<=t;++i)
    {
        mian();
    }
    return 0;
}