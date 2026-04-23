#include <bits/stdc++.h>
using namespace std;

struct Node{
    int z,x,y,t;
};

char maze[2][12][12];
bool vis[2][12][12];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int N,M,T;

bool bfs(){
    queue<Node> q;
    q.push({0,0,0,0});
    vis[0][0][0]=true;

    while(!q.empty()){
        Node curr=q.front();
        q.pop();

        if(curr.t>T) continue;
        if(maze[curr.z][curr.x][curr.y]=='P') return true;

        for(int k=0;k<4;k++){
            int nx=curr.x+dx[k];
            int ny=curr.y+dy[k];
            int nz=curr.z;

            if(nx<0||nx>=N||ny<0||ny>=M||maze[nz][nx][ny]=='*') continue;

            if(maze[nz][nx][ny]=='#'){
                nz^=1;
            }

            if(vis[nz][nx][ny]==false){
                vis[nz][nx][ny]=true;
                if(curr.t+1<=T) q.push({nz,nx,ny,curr.t+1});
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int C; cin>>C;
    while(C--){
        cin>>N>>M>>T;
        for(int k=0;k<2;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                    cin>>maze[k][i][j];
                }
            }
        }
        for(int k=0;k<2;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                    if(maze[k][i][j]=='#'&&maze[1^k][i][j]=='*'){
                        maze[k][i][j]='*';
                    }
                    if(maze[k][i][j]=='#'&&maze[1^k][i][j]=='#'){
                        maze[k][i][j]='*';
                        maze[1^k][i][j]='*';
                    }
                }
            }
        }
        memset(vis,false,sizeof(vis));
        if(bfs()) cout<<"YES";
        else cout<<"NO";
    }
    return 0;
}