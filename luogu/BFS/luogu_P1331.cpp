#include <bits/stdc++.h>
using namespace std;

int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int R,C;
    cin>>R>>C;

    vector<vector<char>> grid(R,vector<char>(C));
    vector<vector<bool>> vis(R,vector<bool>(C,false));

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>grid[i][j];
        }
    }

    int ans=0;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(grid[i][j]=='#'&&vis[i][j]==false){
                queue<pair<int,int>> pq;
                vector<pair<int,int>> cells;

                pq.push({i,j});
                vis[i][j]=true;

                int maxr=i;
                int minr=i;
                int maxc=j;
                int minc=j;

                while(!pq.empty()){
                    auto [r,c]=pq.front();
                    pq.pop();
                    cells.push_back({r,c});
                    maxr=max(maxr,r);
                    minr=min(minr,r);
                    maxc=max(maxc,c);
                    minc=min(minc,c);

                    for(int k=0;k<4;k++){
                        int nr=r+dr[k];
                        int nc=c+dc[k];
                        if(nr<0||nr>=R||nc<0||nc>=C) continue;
                        if(grid[nr][nc]=='#'&&vis[nr][nc]==false){
                            vis[nr][nc]=true;
                            pq.push({nr,nc});
                        }
                    }
                }
                int area=(maxr-minr+1)*(maxc-minc+1);
                if(area!=(int)cells.size()){
                    cout<<"Bad placement.";
                    return 0;
                }
                ans++;
            }
        }
    }
    cout<<"There are "<<ans<<" ships.";
    return 0;
}