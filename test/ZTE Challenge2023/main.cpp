/*====Corycle====*/
#include<bits/stdc++.h>
using namespace std;
inline char Getchar(FILE *file){
    static char buf[10000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,10000,file),p1==p2)?EOF:*p1++;
}
inline int read(FILE *file){
    char c=0;int x=0;
    if((c=Getchar(file))==EOF)return -1;
    while(c<'0'||c>'9')c=Getchar(file);
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=Getchar(file);}
    return x;
}
int n,m;
FILE *Fport,*Fflow,*Fresult;
struct Port{
    int id,w;
    friend bool operator<(Port A,Port B){return A.w<B.w;}
};
struct Flow{
    int id,w,t1,t2;
    friend bool operator<(Flow A,Flow B){
        return A.t1!=B.t1?A.t1>B.t1:A.t2>B.t2;
    }
};
struct Tflow{
    Flow F;
    friend bool operator<(Tflow A,Tflow B){
        // return A.F.w>B.F.w;
        return A.F.w!=B.F.w?A.F.w>B.F.w:A.F.t2<B.F.t2;
    }
};
vector<Port>P;
priority_queue<Flow>F,Pre;
priority_queue<Tflow>T;
void Init(){
    P.clear();n=m=0;
    while(!F.empty())F.pop();
    while(!T.empty())T.pop();
    while(!Pre.empty())Pre.pop();
}
bool Input(int idx){
    int pos=10;
    char s[30]="..//data//";
    char sp[15]="port.txt";
    char sf[15]="flow.txt";
    char sr[15]="result.txt";
    do{s[pos++]=idx%10+'0';idx/=10;}while(idx);
    reverse(s+10,s+pos);
    s[pos++]='/';s[pos++]='/';
    for(int i=0;i<8;i++)s[pos+i]=sp[i];Fport=fopen(s,"r");
    for(int i=0;i<8;i++)s[pos+i]=sf[i];Fflow=fopen(s,"r");
    if(Fport==NULL||Fflow==NULL)return false;
    for(int i=0;i<10;i++)s[pos+i]=sr[i];Fresult=fopen(s,"w");

    Init();
    while(1){
        n++;
        Port tmp={0,0};
        tmp.id=read(Fport);
        if(tmp.id==-1){n--;break;}
        tmp.w=read(Fport);
        P.push_back(tmp);
    }
    while(1){
        m++;
        Flow tmp={0,0,0,0};
        tmp.id=read(Fflow);
        if(tmp.id==-1){m--;break;}
        tmp.w=read(Fflow);
        tmp.t1=read(Fflow);
        tmp.t2=read(Fflow);
        F.push(tmp);
    }
    fclose(Fport);
    fclose(Fflow);
    return true;
}
void Solve(){
    int t=0;
    while(!(T.empty()&&F.empty())){
        if(T.empty()){
            Flow tmp=F.top();F.pop();
            t=tmp.t1;T.push((Tflow){tmp});
        }
        // while(!F.empty()&&F.top().t1<=t){
        //     Flow tmp=F.top();F.pop();
        //     T.push((Tflow){tmp});
        // }
        Flow x=T.top().F;T.pop();
        int pos=0;
        while(!Pre.empty()&&Pre.top().t1<=t){
            Flow tmp=Pre.top();Pre.pop();
            P[tmp.id].w+=tmp.w;
        }
        for(int i=0;i<n;i++)if(P[i].w>P[pos].w)pos=i;
        if(P[pos].w>=x.w){
            P[pos].w-=x.w;
            Flow y=x;
            y.id=pos;
            y.t1=t+x.t2;
            Pre.push(y);
            fprintf(Fresult,"%d,%d,%d\n",x.id,P[pos].id,t);
        }
        else{
            T.push((Tflow){x});
            if(!F.empty()&&!Pre.empty()&&F.top().t1<=Pre.top().t1){
                Flow tmp=F.top();F.pop();
                t=tmp.t1;T.push((Tflow){tmp});
            }
            else t=Pre.top().t1;
        }
    }
    while(!Pre.empty()){
        t=Pre.top().t1;
        Pre.pop();
    }
    cout<<t<<endl;
    fclose(Fresult);
}
int main(){
    for(int i=0;;i++){
        if(!Input(i))break;
        Solve();
    }
	return 0;
}
