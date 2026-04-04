#include <bits/stdc++.h>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    vector<vector<bool>> vis(n,vector<bool>(m,false));

    char x;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>x;
            if(x!='0') a[i][j]=1;
            else a[i][j]=0;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==1&&vis[i][j]==false){
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    auto [x,y]=q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        if(nx<0||nx>=n||ny<0||ny>=m) continue;
                        if(a[nx][ny]==1&&vis[nx][ny]==false){
                            vis[nx][ny]=true;
                            q.push({nx,ny});
                        }
                    }
                }
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}