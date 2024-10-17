#include<bits/stdc++.h>
using namespace std;
namespace FIFO_page_replacement{
    void Solve(vector<int>&Pages,int k){
        queue<int>Queue;
        unordered_map<int,bool>InQueue;
        int ans=0;
        for(auto x:Pages){
            if(InQueue[x])continue;
            ans++;
            if(Queue.size()==k){
                InQueue.erase(Queue.front());
                Queue.pop();
            }
            Queue.push(x);
            InQueue[x]=true;
        }
        cout<<"FIFO页面置换算法发生缺页错误的次数为: "<<ans<<endl;
    }
}
namespace LRU_page_replacement{
    void Solve(vector<int>&Pages,int k){
        unordered_map<int,int>Times;
        set<pair<int,int> >S;
        int ans=0,t=0;
        for(auto x:Pages){
            t++;
            if(Times[x]){
                S.erase(make_pair(Times[x],x));
                Times[x]=t;
                S.insert(make_pair(Times[x],x));
                continue;
            }
            ans++;
            if(S.size()==k){
                int y=S.begin()->second;
                S.erase(make_pair(Times[y],y));
                Times.erase(y);
            }
            Times[x]=t;
            S.insert(make_pair(Times[x],x));
        }
        cout<<"LRU 页面置换算法发生缺页错误的次数为: "<<ans<<endl;
    }
}
namespace optimal_page_replacement{
    void Solve(vector<int>&Pages,int k){
        int n=Pages.size(),ans=0;
        vector<int>Next;
        unordered_map<int,int>Pos,Times;
        set<pair<int,int> >S;
        Next.resize(n);
        for(int i=n-1;i>=0;i--){
            Next[i]=(Pos[Pages[i]]?Pos[Pages[i]]:n);
            Pos[Pages[i]]=i;
        }
        for(int i=0;i<n;i++){
            int x=Pages[i];
            Pos[x]=Next[i];
            if(Times[x])continue;
            ans++;
            while(!S.empty()&&S.begin()->first<i){
                int y=S.begin()->second;
                S.erase(S.begin());
                Times[y]=Pos[y];
                S.insert(make_pair(Times[y],y));
            }
            if(S.size()==k){
                set<pair<int,int> >::iterator it=--S.end();
                int y=it->second;
                S.erase(it);
                Times.erase(y);
            }
            Times[x]=Pos[x];
            S.insert(make_pair(Times[x],x));
        }
        cout<<"最优页面置换算法发生缺页错误的次数为: "<<ans<<endl;
    }
}
int main(){
    srand(time(NULL));
    vector<int>Pages;
	int n=100;
    // cin>>n;
    // for(int i=1;i<=n;i++){int x;cin>>x;Pages.push_back(x);}
    for(int i=1;i<=n;i++)Pages.push_back(rand()%10);
    for(int i=1;i<=7;i++){
        cout<<"页面帧数量为 "<<i<<endl;
        FIFO_page_replacement::Solve(Pages,i);
        LRU_page_replacement::Solve(Pages,i);
        optimal_page_replacement::Solve(Pages,i);
        cout<<endl;
    }
	return 0;
}
