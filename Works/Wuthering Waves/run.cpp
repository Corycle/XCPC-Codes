/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int N=50;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
int dlt10,flag9,flag11;
int cnt[N][N],b[N],e[N],vis[N];
int Rand(){return rand()*rand()+rand();}
int Random(int n){return Rand()%n+1;}
struct Player{
    int id,up,pos;
    string name;
    Player(string Name="default",int ID=0,int Up=0,int Pos=0):id(ID),name(Name),up(Up),pos(Pos){}
}a[N];
void Init(){
    dlt10=0;
    flag9=0;
    flag11=0;

    //Day1
    // a[1]=Player(" 守岸人 ",6,0,0);
    // a[2]=Player(" 卡卡罗 ",1,1,0);
    // a[3]=Player("  今汐  ",4,2,0);
    // a[4]=Player("  长离  ",3,3,0);
    // a[5]=Player("   椿   ",5,4,0);
    // a[6]=Player(" 珂莱塔 ",2,5,0);
    // for(int i=1;i<=6;i++)b[i]=i;

    //Day2
    // a[1]=Player(" 卡卡罗 ",1,0,0);
    // a[2]=Player(" 珂莱塔 ",2,0,-1);
    // a[3]=Player("  长离  ",3,2,-1);
    // a[4]=Player("  今汐  ",4,0,-2);
    // a[5]=Player("   椿   ",5,4,-2);
    // a[6]=Player(" 守岸人 ",6,0,-3);
    // for(int i=1;i<=6;i++)b[i]=i;
    // random_shuffle(b+1,b+6+1);

    //Day3
    a[1]=Player(" 洛可可 ",7,0,0);
    a[2]=Player(" 布兰特 ",8,1,0);
    a[3]=Player("坎特蕾拉",9,2,0);
    a[4]=Player("  赞妮  ",10,3,0);
    a[5]=Player("卡提希娅",11,4,0);
    a[6]=Player("  菲比  ",12,5,0);
    for(int i=1;i<=6;i++)b[i]=i;
}
void Move(int t,int x){
    for(int i=1;i<=6;i++){
        if(a[i].up==t)a[i].up=0;
    }
    for(int i=1;i<=6;i++){
        if(a[i].up==0&&a[i].pos==a[t].pos+x){
            a[i].up=t;
            break;
        }
    }
    a[t].pos+=x;
    int p=a[t].up;
    while(p){
        a[p].pos+=x;
        p=a[p].up;
    }
}
bool CheckLast(int id){
    int pos=inf;
    for(int i=1;i<=6;i++){
        if(a[i].id==id){pos=a[i].pos;break;}
    }
    for(int i=1;i<=6;i++){
        if(a[i].id==id)continue;
        if(a[i].pos<pos)return false;
        if(a[a[i].up].id==id)return false;
    }
    return true;
}
int FindDown(int t){
    for(int i=1;i<=6;i++){
        if(a[i].up==t)return i;
    }
    return 0;
}
int Count(int p){
    int res=0;
    for(int i=1;i<=6;i++)if(a[i].pos==p)res++;
    return res;
}
void MakeTop(int t){
    int x=FindDown(t);
    if(x)a[x].up=a[t].up;
    a[t].up=0;
    for(int i=1;i<=6;i++){
        if(i==t)continue;
        if(a[i].up==0&&a[i].pos==a[t].pos){
            a[i].up=t;
            break;
        }
    }
}
void GetResult(){
    for(int i=1;i<=6;i++)vis[i]=0;
    for(int i=1;i<=6;i++){
        int t=0;
        for(int j=1;j<=6;j++){
            if(vis[j])continue;
            if(a[j].pos>a[t].pos)t=j;
        }
        while(a[t].up)t=a[t].up;
        int x=FindDown(t);
        if(x)a[x].up=0;
        vis[t]=1;
        cnt[t][i]++;
    }
}
bool Check1(){return CheckLast(1);}
bool Check2(){return Random(100)<=28;}
bool Check3(){return Random(100)<=65;}
bool Check4(){return Random(100)<=40;}
bool Check5(){return Random(100)<=50;}
bool Check9(int t,int x){
    if(flag9)return false;
    int Minid=0;
    for(int i=1;i<=6;i++){
        if(a[i].id==9)continue;
        if(a[i].pos>a[t].pos&&a[i].pos<a[t].pos+x){
            if(!Minid)Minid=i;
            else if(a[i].pos<a[Minid].pos)Minid=i;
        }
    }
    if(Minid){
        int x1=a[Minid].pos-a[t].pos,x2=x-x1;
        Move(t,x1);
        int p=t;
        while(1){
            int q=FindDown(p);
            if(q==0)break;
            p=q;
        }
        Move(p,x2);
        flag9=1;
        return true;
    }
    return false;
}
bool Check11(){return CheckLast(11);}
bool Check12(){return Random(100)<=50;}
void Work(){
    while(1){
        for(int i=1;i<=6;i++){
            int t=b[i],id=a[t].id,x=Random(3);
            if(id==1&&Check1())x+=3;
            if(id==2&&Check2())x*=2;
            if(id==5&&Check5()){x+=Count(a[t].pos)-1;MakeTop(t);Move(t,x);goto ck;}
            if(id==6)x=Random(2)+1;
            if(id==7&&i==6)x+=2;
            if(id==8&&i==1)x+=2;
            if(id==9&&Check9(t,x))goto ck;
            if(id==10){x=Random(2)*2-1+dlt10;dlt10=(Count(a[t].pos)>1&&Random(100)<=40)?2:0;}
            if(id==11&&flag11&&Random(100)<=60)x+=2;
            if(id==12&&Check12())x+=1;

            Move(t,x);

            if(id==11&&Check11())flag11=1;

            ck:{}
            if(a[t].pos>=23){
                GetResult();
                return;
            }
        }
        random_shuffle(b+1,b+6+1);
        for(int i=1;i<=6;i++){
            int t=b[i],id=a[t].id;
            if(id==3&&Check3())while(a[t].id!=3)random_shuffle(b+1,b+6+1);
            if(id==4&&Check4())MakeTop(t);
        }
    }
}
int main(){
    srand(time(NULL));
	int T=100000;
    for(int i=1;i<=T;i++){
        Init();
        Work();
    }
    cout<<"T = "<<T<<endl;
    cout<<"  姓名   |  1位率  |  2位率  |  3位率  |  4位率  |  5位率  |  6位率  | 平均位次 |"<<endl;
    for(int i=1;i<=6;i++){
        cout<<a[i].name<<" | ";
        double x=0;
        for(int j=1;j<=6;j++){
            double p=1.0*cnt[i][j]/T;
            printf("%-6.2lf%% | ",p*100);
            x+=p*j;
        }
        printf(" %.4lf  |\n",x);
    }
	return 0;
}
