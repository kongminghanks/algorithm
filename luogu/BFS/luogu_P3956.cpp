#include <bits/stdc++.h>
using namespace std;

const int INF=1e9;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,n; cin>>m>>n;
    vector<vector<int>> a(m+1,vector<int>(m+1,-1));
    int x,y,c;
    while(n--){
        cin>>x>>y>>c;
        a[x][y]=c;
    }
    // dist[x][y][canMagic]
    vector dist(m+1,vector(m+1,vector<int>(2,INF)));
    //pq_tuple<current_cost,x,y,canMagic,current_color>
    priority_queue<
        tuple<int,int,int,int,int>,
        vector<tuple<int,int,int,int,int>>,
        greater<>
    >pq;

    dist[1][1][1]=0;
    pq.push({0,1,1,1,a[1][1]});

    while(!pq.empty()){
        auto [d,x,y,canMagic,color]=pq.top();
        pq.pop();
        if(d>dist[x][y][canMagic]) continue;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<1||nx>m||ny<1||ny>m) continue;
            if(a[nx][ny]!=-1){
                int cost=(a[nx][ny]==color ? 0:1);
                if(dist[nx][ny][1]>d+cost){
                    dist[nx][ny][1]=d+cost;
                    pq.push({dist[nx][ny][1],nx,ny,1,a[nx][ny]});
                }
            }else{
                if(canMagic==1){
                    if(dist[nx][ny][0]>d+2){
                        dist[nx][ny][0]=d+2;
                        pq.push({dist[nx][ny][0],nx,ny,0,color});
                    }
                }
            }
        }
    }
    
    int ans=min(dist[m][m][0],dist[m][m][1]);
    if(ans==INF) cout<<-1;
    else cout<<ans;
    return 0;
}