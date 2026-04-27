#include <bits/stdc++.h>
using namespace std;

struct State{
    int x,y,time;
};

struct Castle{
    char dir;
    int t,v,x,y;
};

bool safe[105][105][1005];
bool vis[105][105][1005];
bool is_castle[105][105];

int dx[3]={1,0,0};
int dy[3]={0,1,0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,n,k,d;
    while(cin>>m>>n>>k>>d){
        memset(vis,false,sizeof(vis));
        memset(safe,true,sizeof(safe));
        memset(is_castle,false,sizeof(is_castle));

        vector<Castle> castles(k);
        for(int i=0;i<k;i++){
            cin>>castles[i].dir>>castles[i].t>>castles[i].v>>castles[i].x>>castles[i].y;
            is_castle[castles[i].x][castles[i].y]=true;
        }
        if(is_castle[m][n]){
            cout<<"Bad luck!"<<endl;
            continue;
        }
        for(const auto& c:castles){
            for(int start_t=0;start_t<=d;start_t+=c.t){
                for(int dt=1;;++dt){
                    int nx=c.x;
                    int ny=c.y;
                    if(c.dir=='N') nx-=c.v*dt;
                    else if(c.dir=='S') nx+=c.v*dt;
                    else if(c.dir=='E') ny+=c.v*dt;
                    else if(c.dir=='W') ny-=c.v*dt;

                    if(nx<0||nx>m||ny<0||ny>n) break;

                    int curr_t=start_t+dt;
                    if(curr_t>d) break;
                    safe[nx][ny][curr_t]=false;

                    if(is_castle[nx][ny]==true) break;
                }
            }
        }

        queue<State> q;
        q.push({0,0,0});
        vis[0][0][0]=true;
        int ans=-1;

        while(!q.empty()){
            State curr=q.front();
            q.pop();

            if(curr.x==m&&curr.y==n){
                ans=curr.time;
                break;
            }

            for(int i=0;i<3;i++){
                int nx=curr.x+dx[i];
                int ny=curr.y+dy[i];
                int nt=curr.time+1;

                if(nx>m||ny>n) continue;

                if((m-nx)+(n-ny)>(d-nt)) continue;

                if(is_castle[nx][ny]) continue;

                if(safe[nx][ny][nt]==true&&vis[nx][ny][nt]==false){
                    vis[nx][ny][nt]=true;
                    q.push({nx,ny,nt});
                }
            }
        }

        if(ans!=-1) cout<<ans<<endl;
        else cout<<"Bad luck!"<<endl;
    }
    return 0;
}