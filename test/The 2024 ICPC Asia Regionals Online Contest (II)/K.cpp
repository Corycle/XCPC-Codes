#include <bits/stdc++.h>
using namespace std;


#define int long long



const int maxn=805;
const int Mod = 998244353;

using ll = long long;
ll x[maxn];
ll y[maxn];
int n;
ll k;

int len,L;
ll R[maxn];
void prepare(ll n)
{
    n+=2;
    len=1,L=0;while(len<=n+n) {len<<=1;L++;}
    for(ll i=0;i<len;i++)R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
}


ll Pow(ll x,ll p)
{
    if(p==0) return 1;
    if(p==1) return x;
    ll mid = Pow(x,p/2);
    if(p%2) return mid*mid%Mod*x%Mod;
    return mid*mid%Mod;
}


void ntt(ll a[], ll n, ll f)
{
    for(ll i=0;i<n;++i) if(i<R[i])swap(a[i],a[R[i]]);
    for(ll i=1;i<n;i<<=1)
    {
        ll Wn =Pow(3,Mod-1+f*(Mod-1)/(i<<1));
        for(ll j=0;j<n;j+=(i<<1))
        {
            ll W=1;
            for(ll k=0;k<i;++k)
            {
                ll x=a[j+k],y=W*a[j+k+i]%Mod;
                a[j+k]=(x+y)%Mod;a[j+k+i]=(x-y+Mod)%Mod;
                W=(W*Wn)%Mod;
            }
        }
    }
    if(f==-1){
        ll inv = Pow(n,Mod-2);
        for(ll i=0;i<n;++i)a[i]=(a[i]*inv)%Mod;
    }
}
void fuckntt(ll A[],ll B[],ll Ans[],int n1,int n2)
{
    prepare(max(n1,n2));
    for(int i=n1;i<=len;++i) A[i]=0;
    for(int i=n2;i<=len;++i) B[i]=0;
    ntt(A,len,1);ntt(B,len,1);
    for(ll i=0;i<len;++i) Ans[i]=A[i]*B[i]%Mod;
    ntt(Ans,len,-1);
}

ll ret[maxn];

ll jie[maxn];
ll invj[maxn];

ll C(int n,int k)
{
    return jie[n]*invj[k]%Mod*invj[n-k]%Mod;
}

ll tmp[maxn];


void solve(int a,int b,int c,int d,int dep)
{

ll cov1[maxn];
ll cov2[maxn];


    if(d<c||b<a)
    {
        ret[0]=1;
        ret[1]=-1;
        return;
    }

    if(dep==-1)
    {
        int i;
        for(i=0;i<=min(b-a+1,d-c+1);++i)
        {
            ret[i] =C(b-a+1,i)*C(d-c+1,i)%Mod*jie[i]%Mod;
        }
        ret[i]=-1;
        return;
    }


    int cnt1 = b,cnt3=a;
    for(int i=a;i<=b;++i)
    {
        if(x[i]&(1ll<<dep))
        {
            tmp[cnt1--] = x[i];
        }
        else
        {
            tmp[cnt3++] = x[i];
        }
    }

    for(int i=a;i<=b;++i) x[i]=tmp[i];

    int cnt2 = d,cnt4=c;
    for(int i=c;i<=d;++i)
    {
        if(y[i]&(1ll<<dep))
        {
            tmp[cnt2--] = y[i];
        }
        else
        {
            tmp[cnt4++] = y[i];
        }
    }

    for(int i=c;i<=d;++i) y[i]=tmp[i];



    if(k&(1ll<<dep))
    {
        solve(a,cnt1,cnt2+1,d,dep-1);
        int i1=0,i2=0;
        for(i1=0;ret[i1]!=-1;++i1) cov1[i1]=ret[i1];
        solve(cnt1+1,b,c,cnt2,dep-1);
        for(i2=0;ret[i2]!=-1;++i2) cov2[i2]=ret[i2];
        fuckntt(cov1,cov2,ret,i1,i2);
        ret[i1+i2-1]=-1;
    }
    else
    {
ll cov3[maxn];
ll cov4[maxn];
ll cov5[maxn];
        solve(a,cnt1,c,cnt2,dep-1);
        int i1=0,i2=0;
        for(i1=0;ret[i1]!=-1;++i1) cov1[i1]=ret[i1];
        solve(cnt1+1,b,cnt2+1,d,dep-1);
        for(i2=0;ret[i2]!=-1;++i2) cov2[i2]=ret[i2];
        int n1=cnt1-a+1,n2=b-cnt1,n3=cnt2-c+1,n4=d-cnt2;
        int mx = min(b-a+1,d-c+1);
        for(int i=0;i<=mx;++i) ret[i]=0;
        ret[mx+1]=-1;
        for(int i=0;i<i1&&i<=n1&&i<=n3;++i)
        {
            for(int j=0;j<i2&&j<=n2&&j<=n4;++j)
            {
                int xx,yy;
                for(xx=0;xx<=n1-i&&xx<=n4-j;++xx) cov3[xx] = C(n1-i,xx)*C(n4-j,xx)%Mod*jie[xx]%Mod;
                for(yy=0;yy<=n3-i&&yy<=n2-j;++yy) cov4[yy] = C(n3-i,yy)*C(n2-j,yy)%Mod*jie[yy]%Mod;
                fuckntt(cov3,cov4,cov5,xx,yy);
                for(int k=0;k<xx+yy-1;++k)
                {
                    ret[i+j+k]=(ret[i+j+k]+cov5[k]*cov1[i]%Mod*cov2[j])%Mod;
                }
            }
        }
    }

    //cout<<"t "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<dep<<endl;
    //cout<<"dep "<<a<<" "<<cnt1<<" "<<b<<" "<<c<<" "<<cnt2<<" "<<d<<endl;
    //for(int i=a;i<=b;++i) cout<<((x[i]>>dep)&1)<<" ";cout<<endl;
    //for(int i=c;i<=d;++i) cout<<((y[i]>>dep)&1)<<" ";cout<<endl;
    //for(int i=0;ret[i]!=-1;++i) cout<<ret[i]<<" ";cout<<endl;


}

signed main()
{
    ios::sync_with_stdio(0);

    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>x[i];
    }
    for(int i=1;i<=n;++i)
    {
        cin>>y[i];
    }


    jie[0]=1,invj[0]=1;
    for(int i=1;i<maxn;++i)
    {
        jie[i]=jie[i-1]*i%Mod;
        invj[i]=Pow(jie[i],Mod-2);
    }

    solve(1,n,1,n,59);

    for(int i=1;i<=n;++i) cout<<ret[i]<<"\n";

    return 0;
}