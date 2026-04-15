#include <bits/stdc++.h>
using namespace std;

char a[205][205];
int visY[205][205];
int visM[205][205];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int main(){
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m){
        memset(visY,-1,sizeof(visY));
        memset(visM,-1,sizeof(visM));
        pair<int,int> Y;
        pair<int,int> M;
        vector<pair<int,int>> kfc;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                if(a[i][j]=='@') kfc.push_back({i,j});
                if(a[i][j]=='Y'){
                    Y.first=i;
                    Y.second=j;
                }else if(a[i][j]=='M'){
                    M.first=i;
                    M.second=j;
                }
            }
        }

        queue<pair<int,int>> YY;
        YY.push({Y.first,Y.second});
        visY[Y.first][Y.second]=0;
        while(!YY.empty()){
            auto [x,y]=YY.front();
            YY.pop();

            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx<1||nx>n||ny<1||ny>m) continue;

                if((visY[nx][ny]==-1||visY[nx][ny]>visY[x][y]+1)&&a[nx][ny]!='#'){
                    visY[nx][ny]=visY[x][y]+1;
                    YY.push({nx,ny});
                }
            }
        }

        queue<pair<int,int>> MM;
        MM.push({M.first,M.second});
        visM[M.first][M.second]=0;
        while(!MM.empty()){
            auto [x,y]=MM.front();
            MM.pop();

            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx<1||nx>n||ny<1||ny>m) continue;

                if((visM[nx][ny]==-1||visM[nx][ny]>visM[x][y]+1)&&a[nx][ny]!='#'){
                    visM[nx][ny]=visM[x][y]+1;
                    MM.push({nx,ny});
                }
            }
        }

        int ans=1e9;
        for(auto [x,y]:kfc){
            if(visY[x][y]!=-1&&visM[x][y]!=-1){
                ans=min(ans,visY[x][y]+visM[x][y]);
            }
        }
        cout<<ans*11<<endl;
    }
}