#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx[8]={0,0,-1,1,-1,-1,1,1};
int dy[8]={-1,1,0,0,-1,1,-1,1};
char a[105][105];
bool vis[105][105];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,n;
    while(cin>>m>>n&&m!=0){
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
            }
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(vis[i][j]==false&&a[i][j]=='@'){
                    ans++;
                    vis[i][j]=true;

                    queue<pair<int,int>> q;

                    q.push({i,j});
                    while(!q.empty()){
                        auto [x,y]=q.front();
                        q.pop();

                        for(int k=0;k<8;k++){
                            int nx=x+dx[k];
                            int ny=y+dy[k];

                            if(nx<1||nx>m||ny<1||ny>n) continue;

                            if(vis[nx][ny]==false&&a[nx][ny]=='@'){
                                vis[nx][ny]=true;
                                q.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}