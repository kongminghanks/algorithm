#include <bits/stdc++.h>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin>>n>>m;
    vector<vector<char>> a(n+2,vector<char>(m+2,'0'));
    vector<vector<bool>> vis(n+2,vector<bool>(m+2,false));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    queue<pair<int,int>> q;
    q.push({0,0});
    vis[0][0]=true;
    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(nx<0||nx>n+1||ny<0||ny>m+1) continue;
            if(a[nx][ny]=='0'&&vis[nx][ny]==false){
                vis[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            if(a[i][j]=='0'&&vis[i][j]==false) ans++;
        }
    }
    cout<<ans;
    return 0;
}