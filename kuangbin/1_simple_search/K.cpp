#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int maze[7][7];
vector<vector<pair<int,int>>> prex(7,vector<pair<int,int>>(7));
bool vis[7][7];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(vis,false,sizeof(vis));
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            cin>>maze[i][j];
        }
    }

    queue<pair<int,int>> q;
    q.push({1,1});
    prex[1][1]={-1,-1};
    vis[1][1]=true;

    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();

        if(x==5&&y==5){
            break;
        }

        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];

            if(nx<1||nx>5||ny<1||ny>5) continue;

            if(vis[nx][ny]==false&&maze[nx][ny]==0){
                vis[nx][ny]=true;
                prex[nx][ny]={x,y};
                q.push({nx,ny});
            }
        }
    }

    vector<pair<int,int>> path;

    int tx,ty;
    tx=5; ty=5;
    while(tx!=-1&&ty!=-1){
        path.push_back({tx,ty});
        auto [px,py]=prex[tx][ty];
        tx=px;
        ty=py;
    }
    reverse(path.begin(),path.end());

    for(int i=0;i<(int)path.size();i++){
        auto [x,y]=path[i];
        cout<<"("<<x-1<<", "<<y-1<<")"<<endl;
    }
    return 0;
}