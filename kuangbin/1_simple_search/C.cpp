#include <iostream>
#include <queue>
using namespace std;

int N,K;
bool vis[100005]={false};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>K;

    queue<pair<int,int>> q;
    q.push({N,0});
    vis[N]=true;

    while(!q.empty()){
        auto [n,t]=q.front();
        q.pop();

        if(n==K){
            cout<<t;
            return 0;
        }

        if(n>0&&vis[n-1]==false){
            vis[n-1]=true;
            q.push({n-1,t+1});
        }

        if(n<100000&&vis[n+1]==false){
            vis[n+1]=true;
            q.push({n+1,t+1});
        }

        if(2*n<=100000&&vis[2*n]==false){
            vis[2*n]=true;
            q.push({2*n,t+1});
        }
    }
    return 0;
}