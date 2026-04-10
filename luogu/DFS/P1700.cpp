#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> g[105];
bool vis[105];

void dfs(int u){
    vis[u]=true;
    for(int v:g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    int a,b;
    for(int i=1;i<N;i++){
        cin>>a>>b;
        g[b].push_back(a);
    }

    int ans=-1;
    for(int i=1;i<=N;i++){
        memset(vis,false,sizeof(vis));
        dfs(i);

        bool ok=true;
        for(int j=1;j<=N;j++){
            if(!vis[j]){
                ok=false;
                break;
            }
        }
        if(ok){
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}