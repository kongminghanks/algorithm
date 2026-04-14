#include <bits/stdc++.h>
using namespace std;

const int N=1005;
char a[N][N];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int fire_time[N][N];
bool vis[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin>>tt;
    while(tt--){
        memset(fire_time,-1,sizeof(fire_time));
        memset(vis,false,sizeof(vis));
        bool ok=false;
        int R,C; cin>>R>>C;
        pair<int,int> J;
        queue<pair<int,int>> fire;
        queue<tuple<int,int,int>> Joe;

        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                cin>>a[i][j];
                if(a[i][j]=='J'){
                    J.first=i;
                    J.second=j;
                }else if(a[i][j]=='F'){
                    fire.push({i,j});
                    fire_time[i][j]=0;
                }
            }
        }

        Joe.push({J.first,J.second,0});
        vis[J.first][J.second]=true;

        while(!fire.empty()){
            auto [x,y]=fire.front();
            fire.pop();

            
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx<1||nx>R||ny<1||ny>C) continue;

                if(fire_time[nx][ny]==-1&&a[nx][ny]!='#'){
                    fire_time[nx][ny]=fire_time[x][y]+1;
                    fire.push({nx,ny});
                }
            }
        }

        while(!Joe.empty()){
            auto [x,y,t]=Joe.front();
            Joe.pop();

            if(x==1||x==R||y==1||y==C){
                ok=true;
                cout<<t+1<<endl;
                break;
            }

            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx<1||nx>R||ny<1||ny>C) continue;

                if(vis[nx][ny]==false&&a[nx][ny]!='#'&&(fire_time[nx][ny]==-1||t+1<fire_time[nx][ny])){
                    vis[nx][ny]=true;
                    Joe.push({nx,ny,t+1});
                }
            }
        }

        if(!ok) cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}