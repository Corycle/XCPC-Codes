/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
class Matrix{
public:
    int n,m;
    double **a;
    void Init(){
        a=new double*[n];
        for(int i=0;i<n;i++)a[i]=new double[m];
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)a[i][j]=0;
    }
    Matrix():n(0),m(0),a(NULL){};
    Matrix(int A):n(A),m(A){Init();}
    Matrix(int A,int B):n(A),m(B){Init();}
    Matrix(const Matrix &A):n(A.n),m(A.m){
        Init();
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)a[i][j]=A.a[i][j];
    }
    ~Matrix(){
        if(a!=NULL){
            for(int i=0;i<n;i++)if(a[i]!=NULL)delete [] a[i];
            delete [] a;
        }
    }
    friend Matrix operator*(const Matrix &A,const Matrix &B){
        Matrix C(A.n,B.m);
        for(int i=0;i<A.n;i++){
            for(int j=0;j<B.m;j++){
                for(int k=0;k<A.m;k++){
                    C.a[i][j]+=A.a[i][k]*B.a[k][j];
                }
            }
        }
        return C;
    }
    void Input(){
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>a[i][j];
    }
    void Print(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)cout<<a[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    Matrix Jacobi(){
        Matrix res(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)res.a[i][j]=0;
                else res.a[i][j]=-a[i][j]/a[i][i];
            }
        }
        return res;
    }
    Matrix Gauss_Seidel(){
        Matrix res(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j<i){
                    for(int k=0;k<n;k++){
                        res.a[i][k]+=res.a[j][k]*(-a[i][j]/a[i][i]);
                    }
                }
                if(j>i)res.a[i][j]+=-a[i][j]/a[i][i];
            }
        }
        return res;
    }
    Matrix Eigen(){
        Matrix tmp(*this);
        Matrix res(n,1);
        for(int i=0;i<n;i++){
            int t=i;
            for(int j=i;j<n;j++)if(abs(tmp.a[j][i])>abs(tmp.a[t][i]))t=j;
            swap(tmp.a[t],tmp.a[i]);
            if(abs(tmp.a[i][i])<eps)continue;
            res.a[i][0]=tmp.a[i][i];
            for(int j=i+1;j<n;j++){
                double p=tmp.a[j][i]/tmp.a[i][i];
                for(int k=i;k<n;k++)tmp.a[j][k]-=p*tmp.a[i][k];
            }
        }
        return res;
    }
};
int main(){
//	freopen("_.in","r",stdin);
//	freopen("_.out","w",stdout);
	Matrix a(3);
    a.Input();
    Matrix c1(a.Jacobi());
    Matrix d1(c1.Eigen());
    c1.Print();
    d1.Print();
    Matrix c2(a.Gauss_Seidel());
    Matrix d2(c2.Eigen());
    c2.Print();
    d2.Print();
	return 0;
}
