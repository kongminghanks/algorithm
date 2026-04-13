#include <bits/stdc++.h>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
char a[12][12];
int dist[12][12];
int N,M;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin>>T;
    
    for(int t=1;t<=T;t++){
        cin>>N>>M;
        vector<pair<int,int>> start;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                cin>>a[i][j];
                if(a[i][j]=='#') start.push_back({i,j});
            }
        }

        int ans=1e9;

        for(int i=0;i<(int)start.size();i++){
            for(int j=0;j<=i;j++){
                memset(dist,-1,sizeof(dist));
                bool ok=true;

                pair<int,int> s1=start[i];
                pair<int,int> s2=start[j];

                queue<pair<int,int>> q;
                q.push({s1.first,s1.second});
                q.push({s2.first,s2.second});
                dist[s1.first][s1.second]=0;
                dist[s2.first][s2.second]=0;

                while(!q.empty()){
                    auto [x,y]=q.front();
                    q.pop();

                    for(int k=0;k<4;k++){
                        int nx=x+dx[k];
                        int ny=y+dy[k];

                        if(nx<1||nx>N||ny<1||ny>M) continue;

                        if(a[nx][ny]=='#'&&dist[nx][ny]==-1){
                            dist[nx][ny]=dist[x][y]+1;
                            q.push({nx,ny});
                        }
                    }
                }

                for(auto [x,y]:start){
                    if(dist[x][y]==-1){
                        ok=false;
                        break;
                    }
                }

                int mx=0;
                if(ok){
                    for(auto [x,y]:start){
                        mx=max(mx,dist[x][y]);
                    }
                    ans=min(ans,mx);
                }
            }
        }
        if(ans==1e9) cout<<"Case "<<t<<": "<<-1<<endl;
        else cout<<"Case "<<t<<": "<<ans<<endl;
    }
    return 0;
}