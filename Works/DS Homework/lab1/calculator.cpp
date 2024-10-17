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
    printf("����ʽ%3d:\n",i);
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
    puts("����һ��һԪϡ�����ʽ�򵥼���������ѡ������Ҫ�Ĺ��ܣ�");
    puts("(1) ���벢����һ���µĶ���ʽ��");
    puts("(2) ����ѽ����Ķ���ʽ��");
    puts("(3) ����ʽa��b��ӣ���������ʽa+b��");
    puts("(4) ����ʽa��b�������������ʽa-b��");
    puts("(5) �������ʽ��x����ֵ��������xֵ���������ʽֵ��");
    puts("(6) �˳���������");
}
void Print1(){
    system("cls");
    puts("�밴���и�ʽ����һ������ʽ��");
    puts("n c1 e1 c2 e2 ... cn en");
    puts("����n�Ƕ���ʽ��������ci,ei�ֱ��ǵ�i���ϵ����ָ�������а�ָ���������У�");
}
void Print2(){
    system("cls");
    puts("�������ѽ����Ķ���ʽ�������¸�ʽ�����");
    puts("n c1 e1 c2 e2 ... cn en");
    puts("����n�Ƕ���ʽ��������ci,ei�ֱ��ǵ�i���ϵ����ָ�������а�ָ���������У�");
    for(int i=1;i<=tot;i++)PrintPoly(i);
}
void Print3(){
    Print2();
    puts("��ѡ�����ʽa�Ͷ���ʽb�ı�ţ����ǽ������µĶ���ʽa+b��");
}
void Print4(){
    Print2();
    puts("��ѡ�����ʽa�Ͷ���ʽb�ı�ţ����ǽ������µĶ���ʽa-b��");
}
void Print5(){
    Print2();
    puts("��ѡ�����ʽa�ͱ���x�����ǽ��������ʽa��x����ֵ��");
}
void PrintError1(){
    puts("����ʽ��Ŵ���");
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
    printf("�ѽ��� ����ʽ%d\n",tot);
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
    printf("�ѽ��� ����ʽ%d = ����ʽ%d + ����ʽ%d\n",tot,a,b);
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
    printf("�ѽ��� ����ʽ%d = ����ʽ%d - ����ʽ%d\n",tot,a,b);
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
    printf("�� x = %d ����ֵΪ %lld\n",x,ans);
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
