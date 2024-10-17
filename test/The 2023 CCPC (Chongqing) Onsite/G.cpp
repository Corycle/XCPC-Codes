#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int read(){
    int s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
    return s*f;
}
int n,m,K;
struct Pokemon{
    int a,b,c,d,hp,e,w,nowe;
}P[N];
Pokemon NewPokemon(){
    Pokemon res;
    res.hp=read();
    res.a=read();
    res.b=read();
    res.c=read();
    res.d=read();
    res.e=read();
    res.w=read();
    res.nowe=0;
    return res;
}
void Attact(deque<Pokemon>& A,deque<Pokemon>& B){
    Pokemon a=A.front(),b=B.front();
    int w1=max(0,a.a-b.c);
    int w2=max(0,a.b-b.d);
    int w3=(a.nowe>=a.e?a.w:0);
    if(w1>=w2&&w1>=w3){
        a.nowe++;
        b.hp-=w1;
    }
    else if(w2>=w1&&w2>=w3){
        a.nowe++;
        b.hp-=w2;
    }
    else{
        a.nowe-=a.e;
        b.hp-=w3;
    }
    A.pop_front();
    A.push_back(a);
    if(b.hp<=0)B.pop_front();
    else{
        B.pop_front();
        B.push_front(b);
    }
}
deque<Pokemon>A,B;
int main(){
    n=read();m=read();K=read();
    for(int i=1;i<=n;i++)A.push_back(NewPokemon());
    for(int i=1;i<=m;i++)B.push_back(NewPokemon());
    while(K--){
        Attact(A,B);
        if(B.empty()){puts("Alice");return 0;}
        Attact(B,A);
        if(A.empty()){puts("Bob");return 0;}
    }
    puts("Draw");
    return 0;
}