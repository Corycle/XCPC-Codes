/*====Corycle====*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int M=1005;
const int N=105;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}
unordered_map<string,int>id;
int n,m,cnt,maxPoints,avePoints,deg[N];
vector<int>E[N],courseTable[N],availableCourse;
struct Course{
    int points;
    string name;
    vector<string>preCourse;
}a[N];
int lastCourse[M];
bool vis[M],used[N];
void Prepare(){
    cnt=0;
    for(int i=1;i<=n;i++){
        used[i]=false;
        deg[i]=0;
        E[i].clear();
    }
    for(int i=1;i<=m;i++)courseTable[i].clear();
}
void Calc(){
    vis[0]=true;
    for(auto x:availableCourse){
        for(int i=maxPoints;i>=a[x].points;i--){
            if(!vis[i]&&vis[i-a[x].points]){
                vis[i]=true;
                lastCourse[i]=x;
            }
        }
    }
}
bool cmp(int x,int y){return a[x].name<a[y].name;}
void PutCourses(int t,int Points){
    while(Points){
        courseTable[t].push_back(lastCourse[Points]);
        Points-=a[lastCourse[Points]].points;
        cnt++;
    }
    sort(courseTable[t].begin(),courseTable[t].end(),cmp);
}
void Clear(){
    availableCourse.clear();
    for(int i=0;i<=maxPoints;i++)vis[i]=lastCourse[i]=0;
}
bool Solve(int standardPoints){
    Prepare();
    for(int i=1;i<=n;i++){
        for(auto course:a[i].preCourse){
            int x=id[course];
            E[x].push_back(i);
            deg[i]++;
        }
    }
    for(int t=1;t<=m;t++){
        if(cnt==n)break;
        for(int i=1;i<=n;i++){
            if(!deg[i]&&!used[i])availableCourse.push_back(i);
        }
        if(availableCourse.empty())return false;
        Calc();
        bool flag=false;
        for(int i=standardPoints;i<=maxPoints;i++){
            if(vis[i]){
                PutCourses(t,i);
                flag=true;
                break;
            }
        }
        if(!flag){
            for(int i=standardPoints;i>=0;i--){
                if(vis[i]){
                    PutCourses(t,i);
                    flag=true;
                    break;
                }
            }
        }
        for(auto x:courseTable[t]){
            for(auto y:E[x])deg[y]--;
            used[x]=true;
        }
        Clear();
    }
    return cnt==n;
}
void PrintCourseTable(){
    for(int i=1;i<=m;i++){
        int sumPoints=0;
        printf("Term %2d :\n",i);
        for(auto x:courseTable[i]){
            printf("    %s, credit: %2d\n",a[x].name.c_str(),a[x].points);
            sumPoints+=a[x].points;
        }
        printf("    total credit = %d\n",sumPoints);
    }
}
void PrintErrorMessage(){
    puts("ERROR: Failed to schedule courses.");
    exit(1);
}
void Input(){
    n=read();m=read();maxPoints=read();
    for(int i=1;i<=n;i++){
        cin>>a[i].name;
        a[i].points=read();
        int num=read();
        id[a[i].name]=i;
        while(num--){
            string s;
            cin>>s;
            a[i].preCourse.push_back(s);
        }
        if(a[i].points>maxPoints){
            puts("ERROR: There are too many credits for a certain course.");
            exit(1);
        }
    }
}
void Work(){
    puts("Choose the arrange mode:");
    puts("(1) Make the learning burden of students as even as possible throughout each semester.");
    puts("(2) Focus the course as much as possible on the first few semesters.");
    int mode=read();
    if(mode==1){
        int standardPoints=-1;
        for(int i=0;i<=maxPoints;i++){
            if(Solve(i)){
                standardPoints=i;
                break;
            }
        }
        if(standardPoints==-1)PrintErrorMessage();
        Solve(standardPoints);
    }
    else if(mode==2){
        bool flag=Solve(maxPoints);
        if(!flag)PrintErrorMessage();
    }
    else{
        puts("ERROR: Illegal mode number.");
        exit(1);
    }
}
int main(){
    Input();
    Work();
    PrintCourseTable();
	return 0;
}
