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
int dlt10,flag9,flag11,n;
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

    // Day 1
    n=6;
    a[1]=Player(" 守岸人 ",6,0,0);
    a[2]=Player(" 卡卡罗 ",1,0,0);
    a[3]=Player("  今汐  ",4,0,0);
    a[4]=Player("  长离  ",3,0,0);
    a[5]=Player("   椿   ",5,0,0);
    a[6]=Player(" 珂莱塔 ",2,0,0);
    for(int i=1;i<=n;i++)b[i]=i;
    random_shuffle(b+1,b+n+1);
    for(int i=2;i<=n;i++)a[b[i]].up=b[i-1];

    // Day 2
    // n=6;
    // a[1]=Player(" 卡卡罗 ",1,0,0);
    // a[2]=Player(" 珂莱塔 ",2,0,-1);
    // a[3]=Player("  长离  ",3,2,-1);
    // a[4]=Player("  今汐  ",4,0,-2);
    // a[5]=Player("   椿   ",5,4,-2);
    // a[6]=Player(" 守岸人 ",6,0,-3);
    // for(int i=1;i<=n;i++)b[i]=i;
    // random_shuffle(b+1,b+n+1);

    // Day 3
    // n=6;
    // a[1]=Player(" 洛可可 ",7,0,0);
    // a[2]=Player(" 布兰特 ",8,0,0);
    // a[3]=Player("坎特蕾拉",9,0,0);
    // a[4]=Player("  赞妮  ",10,0,0);
    // a[5]=Player("卡提希娅",11,0,0);
    // a[6]=Player("  菲比  ",12,0,0);
    // for(int i=1;i<=n;i++)b[i]=i;
    // random_shuffle(b+1,b+n+1);
    // for(int i=2;i<=n;i++)a[b[i]].up=b[i-1];

    // Day 4
    // n=6;
    // a[1]=Player("坎特蕾拉",9,0,0);
    // a[2]=Player(" 洛可可 ",7,0,-1);
    // a[3]=Player("卡提希娅",11,2,-1);
    // a[4]=Player(" 布兰特 ",8,0,-2);
    // a[5]=Player("  赞妮  ",10,4,-2);
    // a[6]=Player("  菲比  ",12,0,-3);
    // for(int i=1;i<=n;i++)b[i]=i;
    // random_shuffle(b+1,b+n+1);

    // Day 5
    // n=4;
    // a[1]=Player(" 卡卡罗 ",1,0,0);
    // a[2]=Player("  今汐  ",4,0,0);
    // a[3]=Player(" 守岸人 ",6,0,0);
    // a[4]=Player("  长离  ",3,0,0);
    // for(int i=1;i<=n;i++)b[i]=i;
    // random_shuffle(b+1,b+n+1);
    // for(int i=2;i<=n;i++)a[b[i]].up=b[i-1];

    // Day 6
    // n=4;
    // a[1]=Player(" 守岸人 ",6,0,0);
    // a[2]=Player("  今汐  ",4,0,-1);
    // a[3]=Player(" 卡卡罗 ",1,2,-1);
    // a[4]=Player("  长离  ",3,0,-2);
    // for(int i=1;i<=n;i++)b[i]=i;
    // random_shuffle(b+1,b+n+1);

    // Day 7
    // n=4;
    // a[1]=Player(" 洛可可 ",7,0,0);
    // a[2]=Player("  菲比  ",12,0,0);
    // a[3]=Player(" 布兰特 ",8,0,0);
    // a[4]=Player("  赞妮  ",10,0,0);
    // for(int i=1;i<=n;i++)b[i]=i;
    // random_shuffle(b+1,b+n+1);
    // for(int i=2;i<=n;i++)a[b[i]].up=b[i-1];

}
void Move(int t,int x){
    for(int i=1;i<=n;i++){
        if(a[i].up==t)a[i].up=0;
    }
    for(int i=1;i<=n;i++){
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
    for(int i=1;i<=n;i++){
        if(a[i].id==id){pos=a[i].pos;break;}
    }
    for(int i=1;i<=n;i++){
        if(a[i].id==id)continue;
        if(a[i].pos<pos)return false;
        if(a[a[i].up].id==id)return false;
    }
    return true;
}
int FindDown(int t){
    for(int i=1;i<=n;i++){
        if(a[i].up==t)return i;
    }
    return 0;
}
int Count(int p){
    int res=0;
    for(int i=1;i<=n;i++)if(a[i].pos==p)res++;
    return res;
}
void MakeTop(int t){
    int x=FindDown(t);
    if(x)a[x].up=a[t].up;
    a[t].up=0;
    for(int i=1;i<=n;i++){
        if(i==t)continue;
        if(a[i].up==0&&a[i].pos==a[t].pos){
            a[i].up=t;
            break;
        }
    }
}
void GetResult(){
    for(int i=1;i<=n;i++)vis[i]=0;
    for(int i=1;i<=n;i++){
        int t=0;
        for(int j=1;j<=n;j++){
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
    for(int i=1;i<=n;i++){
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
        for(int i=1;i<=n;i++){
            int t=b[i],id=a[t].id,x=Random(3);
            if(id==1&&Check1())x+=3;
            if(id==2&&Check2())x*=2;
            if(id==4&&Check4())MakeTop(t);
            if(id==5&&Check5()){x+=Count(a[t].pos)-1;MakeTop(t);Move(t,x);goto ck;}
            if(id==6)x=Random(2)+1;
            if(id==7&&i==n)x+=2;
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
        random_shuffle(b+1,b+n+1);
        for(int i=1;i<=n;i++){
            int t=b[i],id=a[t].id;
            if(id==3&&Check3()){
                while(a[b[n]].id!=3)random_shuffle(b+1,b+n+1);
            }
        }
    }
}
int main(){
    srand(time(NULL));
    int T=10000000;
    for(int i=1;i<=T;i++){
        Init();
        Work();
    }
    cout<<"T = "<<T<<endl;
    cout<<"|   姓名   |";
    for(int i=1;i<=n;i++)cout<<"  "<<i<<"位率  |";
    cout<<" 平均位次 |"<<endl;
    for(int i=1;i<=n;i++){
        cout<<"| "<<a[i].name<<" | ";
        double x=0;
        for(int j=1;j<=n;j++){
            double p=1.0*cnt[i][j]/T;
            printf("%-6.2lf%% | ",p*100);
            x+=p*j;
        }
        printf(" %.4lf  |\n",x);
    }
	return 0;
}
/*
Result:

Day 1:
|   姓名   |  1位率  |  2位率  |  3位率  |  4位率  |  5位率  |  6位率  | 平均位次 |     
|  守岸人  | 16.51 % | 20.70 % | 19.30 % | 17.59 % | 15.23 % | 10.68 % |  3.2635  |     
|  卡卡罗  | 12.93 % | 18.78 % | 20.72 % | 22.18 % | 20.18 % | 5.21  % |  3.3353  |     
|   今汐   | 12.56 % | 12.46 % | 13.92 % | 15.91 % | 19.50 % | 25.65 % |  3.9428  |     
|   长离   | 8.72  % | 12.32 % | 13.32 % | 14.57 % | 17.87 % | 33.18 % |  4.2009  |     
|    椿    | 28.98 % | 15.03 % | 15.57 % | 14.63 % | 13.34 % | 12.45 % |  3.0566  |     
|  珂莱塔  | 20.29 % | 20.71 % | 17.16 % | 15.12 % | 13.89 % | 12.83 % |  3.2009  |

Day 2:
T = 10000000
|   姓名   |  1位率  |  2位率  |  3位率  |  4位率  |  5位率  |  6位率  | 平均位次 |     
|  卡卡罗  | 12.69 % | 18.35 % | 20.81 % | 22.76 % | 20.70 % | 4.69  % |  3.3448  |     
|  珂莱塔  | 22.82 % | 21.87 % | 17.58 % | 14.82 % | 12.68 % | 10.22 % |  3.0332  |     
|   长离   | 8.62  % | 12.18 % | 13.56 % | 15.26 % | 18.82 % | 31.57 % |  4.1819  |     
|   今汐   | 12.62 % | 12.62 % | 14.42 % | 16.40 % | 19.35 % | 24.58 % |  3.9098  |     
|    椿    | 25.96 % | 13.94 % | 14.54 % | 14.01 % | 14.10 % | 17.45 % |  3.2871  |     
|  守岸人  | 17.28 % | 21.03 % | 19.09 % | 16.75 % | 14.35 % | 11.49 % |  3.2432  |

Day 3:
T = 10000000
|   姓名   |  1位率  |  2位率  |  3位率  |  4位率  |  5位率  |  6位率  | 平均位次 |     
|  洛可可  | 16.87 % | 16.47 % | 16.36 % | 16.39 % | 16.51 % | 17.40 % |  3.5141  |     
|  布兰特  | 16.45 % | 16.34 % | 16.49 % | 16.63 % | 16.76 % | 17.33 % |  3.5292  |     
| 坎特蕾拉 | 14.74 % | 15.73 % | 16.51 % | 16.92 % | 17.05 % | 19.04 % |  3.6293  |     
|   赞妮   | 18.39 % | 18.25 % | 16.88 % | 15.55 % | 14.55 % | 16.38 % |  3.3876  |
| 卡提希娅 | 14.46 % | 14.80 % | 16.00 % | 17.73 % | 19.84 % | 17.16 % |  3.6517  |     
|   菲比   | 19.10 % | 18.40 % | 17.75 % | 16.78 % | 15.29 % | 12.68 % |  3.2880  |

Day 4:
T = 10000000
|   姓名   |  1位率  |  2位率  |  3位率  |  4位率  |  5位率  |  6位率  | 平均位次 |      
| 坎特蕾拉 | 15.54 % | 16.79 % | 17.68 % | 17.82 % | 17.01 % | 15.17 % |  3.4948  |      
|  洛可可  | 18.19 % | 17.74 % | 17.50 % | 17.02 % | 15.91 % | 13.65 % |  3.3567  |      
| 卡提希娅 | 14.76 % | 15.03 % | 16.22 % | 18.14 % | 20.49 % | 15.37 % |  3.6066  |      
|  布兰特  | 16.89 % | 16.72 % | 16.84 % | 16.94 % | 16.72 % | 15.88 % |  3.4752  |      
|   赞妮   | 16.87 % | 16.73 % | 15.47 % | 14.56 % | 14.55 % | 21.82 % |  3.5867  |      
|   菲比   | 17.76 % | 16.99 % | 16.29 % | 15.52 % | 15.33 % | 18.11 % |  3.4800  |

Day 5:
T = 10000000
|   姓名   |  1位率  |  2位率  |  3位率  |  4位率  | 平均位次 |
|  守岸人  | 36.52 % | 30.28 % | 20.69 % | 12.51 % |  2.0920  |
|   今汐   | 23.95 % | 20.37 % | 26.73 % | 28.95 % |  2.6068  |
|  卡卡罗  | 26.35 % | 34.18 % | 33.53 % | 5.94  % |  2.1905  |
|   长离   | 13.19 % | 15.16 % | 19.05 % | 52.60 % |  3.1107  |

Day 6:
T = 10000000
|   姓名   |  1位率  |  2位率  |  3位率  |  4位率  | 平均位次 |
|  守岸人  | 34.91 % | 29.46 % | 21.37 % | 14.26 % |  2.1498  |
|   今汐   | 23.20 % | 19.26 % | 25.74 % | 31.80 % |  2.6614  |
|  卡卡罗  | 26.72 % | 34.58 % | 32.16 % | 6.54  % |  2.1854  |
|   长离   | 15.17 % | 16.71 % | 20.72 % | 47.39 % |  3.0034  |

Day 7:
T = 10000000
|   姓名   |  1位率  |  2位率  |  3位率  |  4位率  | 平均位次 |
|  洛可可  | 26.62 % | 25.31 % | 24.87 % | 23.20 % |  2.4465  |
|   菲比   | 25.88 % | 26.11 % | 26.14 % | 21.87 % |  2.4400  |
|  布兰特  | 26.78 % | 25.75 % | 25.13 % | 22.34 % |  2.4303  |
|   赞妮   | 20.72 % | 22.83 % | 23.86 % | 32.59 % |  2.6832  |

*/