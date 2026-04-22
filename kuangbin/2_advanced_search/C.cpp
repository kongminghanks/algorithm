#include <bits/stdc++.h>
using namespace std;

int adj[21][3];  //adjacency list
int path[21];    //record temporary node of the depth
bool vis[21];
int cnt=0;
int start_node;

void dfs(int u,int depth){
    path[depth]=u;

    if(depth==20){
        for(int i=0;i<3;i++){
            if(adj[u][i]==start_node){
                cnt++;
                cout<<cnt<<": ";
                for(int j=1;j<=20;j++) cout<<path[j]<<" ";
                cout<<start_node<<endl;
                return;
            }
        }
        return;
    }

    vis[u]=true;
    for(int i=0;i<3;i++){
        int v=adj[u][i];
        if(!vis[v]){
            dfs(v,depth+1);
        }
    }
    vis[u]=false;   //never forget about backtracking
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i=1;i<=20;i++){
        for(int j=0;j<3;j++){
            cin>>adj[i][j];
        }
        sort(adj[i],adj[i]+3);
    }

    while(cin>>start_node&&start_node!=0){
        cnt=0;
        memset(vis,false,sizeof(vis));
        dfs(start_node,1);  //initialize the depth as 1
    }
    return 0;
}