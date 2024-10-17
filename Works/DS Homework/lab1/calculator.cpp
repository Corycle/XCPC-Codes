#include<iostream>
#include<windows.h>
#define ll long long
using namespace std;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
class LinkNode{
public:
    int c,e;
    LinkNode *next;
    LinkNode(int C=0,int E=0,LinkNode *Next=NULL):c(C),e(E),next(Next){}
};
int tot=0;
LinkNode *L[105];
ll Pow(ll x,int y){
    ll ans=1;
    while(y){if(y&1)ans*=x;x*=x;y>>=1;}
    return ans;
}
void PrintPoly(int i){
    printf("多项式%3d:\n",i);
    int num=L[i]->c;
    cout<<num<<" ";
    LinkNode *p=L[i];
    while(num--){
        p=p->next;
        cout<<p->c<<" "<<p->e<<" ";
    }
    cout<<endl;
}
void Print0(){
    system("cls");
    puts("这是一个一元稀疏多项式简单计算器，请选择你需要的功能：");
    puts("(1) 输入并建立一个新的多项式。");
    puts("(2) 输出已建立的多项式。");
    puts("(3) 多项式a和b相加，建立多项式a+b。");
    puts("(4) 多项式a和b相减，建立多项式a-b。");
    puts("(5) 计算多项式在x处的值；即给定x值，计算多项式值。");
    puts("(6) 退出计算器。");
}
void Print1(){
    system("cls");
    puts("请按下列格式输入一个多项式：");
    puts("n c1 e1 c2 e2 ... cn en");
    puts("其中n是多项式的项数，ci,ei分别是第i项的系数和指数，序列按指数降序排列；");
}
void Print2(){
    system("cls");
    puts("下面是已建立的多项式，按如下格式输出：");
    puts("n c1 e1 c2 e2 ... cn en");
    puts("其中n是多项式的项数，ci,ei分别是第i项的系数和指数，序列按指数降序排列；");
    for(int i=1;i<=tot;i++)PrintPoly(i);
}
void Print3(){
    Print2();
    puts("请选择多项式a和多项式b的编号，我们将建立新的多项式a+b：");
}
void Print4(){
    Print2();
    puts("请选择多项式a和多项式b的编号，我们将建立新的多项式a-b：");
}
void Print5(){
    Print2();
    puts("请选择多项式a和变量x，我们将计算多项式a在x处的值：");
}
void PrintError1(){
    puts("多项式编号错误。");
    system("pause");
}
void Work1(){
    Print1();
    int n=read();
    L[++tot]=new LinkNode(n);
    LinkNode *p=L[tot];
    for(int i=1;i<=n;i++){
        int c=read(),e=read();
        p->next=new LinkNode(c,e);
        p=p->next;
    }
    printf("已建立 多项式%d\n",tot);
    PrintPoly(tot);
    system("pause");
}
void Work2(){
    Print2();
    system("pause");
}
void Work3(){
    Print3();
    int a=read(),b=read();
    if(a<1||a>tot||b<1||b>tot){
        PrintError1();
        return;
    }
    int num=0;
    L[++tot]=new LinkNode();
    LinkNode *p1=L[a]->next,*p2=L[b]->next,*p=L[tot];
    while(p1!=NULL&&p2!=NULL){
        if(p1->e<p2->e)swap(p1,p2);
        if(p1->e==p2->e){
            int c=p1->c+p2->c;
            if(c!=0){
                p->next=new LinkNode(c,p1->e);
                p=p->next;
                num++;
            }
            p1=p1->next;
            p2=p2->next;
        }
        else{
            p->next=new LinkNode(p1->c,p1->e);
            p=p->next;
            p1=p1->next;
            num++;
        }
    }
    while(p1!=NULL){
        p->next=new LinkNode(p1->c,p1->e);
        p=p->next;
        p1=p1->next;
        num++;
    }
    while(p2!=NULL){
        p->next=new LinkNode(p2->c,p2->e);
        p=p->next;
        p2=p2->next;
        num++;
    }
    L[tot]->c=num;
    printf("已建立 多项式%d = 多项式%d + 多项式%d\n",tot,a,b);
    PrintPoly(tot);
    system("pause");
}
void Work4(){
    Print4();
    int a=read(),b=read();
    if(a<1||a>tot||b<1||b>tot){
        PrintError1();
        return;
    }
    int t=1,num=0;
    L[++tot]=new LinkNode();
    LinkNode *p1=L[a]->next,*p2=L[b]->next,*p=L[tot];
    while(p1!=NULL&&p2!=NULL){
        if(p1->e<p2->e){swap(p1,p2);t=-t;}
        if(p1->e==p2->e){
            int c=p1->c-p2->c;
            if(c!=0){
                p->next=new LinkNode(t*c,p1->e);
                p=p->next;
                num++;
            }
            p1=p1->next;
            p2=p2->next;
        }
        else{
            p->next=new LinkNode(t*p1->c,p1->e);
            p=p->next;
            p1=p1->next;
            num++;
        }
    }
    if(t==-1)swap(p1,p2);
    while(p1!=NULL){
        p->next=new LinkNode(p1->c,p1->e);
        p=p->next;
        p1=p1->next;
        num++;
    }
    while(p2!=NULL){
        p->next=new LinkNode(-p2->c,p2->e);
        p=p->next;
        p2=p2->next;
        num++;
    }
    L[tot]->c=num;
    printf("已建立 多项式%d = 多项式%d - 多项式%d\n",tot,a,b);
    PrintPoly(tot);
    system("pause");
}
void Work5(){
    Print5();
    int a=read();
    ll x=read(),ans=0;
    if(a<1||a>tot){
        PrintError1();
        return;
    }
    int num=L[a]->c;
    LinkNode *p=L[a];
    while(num--){
        p=p->next;
        ans+=Pow(x,p->e)*p->c;
    }
    PrintPoly(a);
    printf("在 x = %d 处的值为 %lld\n",x,ans);
    system("pause");
}
int main(){
    while(1){
        Print0();
        int Type=read();
        if(Type==1)Work1();
        if(Type==2)Work2();
        if(Type==3)Work3();
        if(Type==4)Work4();
        if(Type==5)Work5();
        if(Type==6)return 0;
    }
	return 0;
}
