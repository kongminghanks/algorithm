#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

int dL[6]={-1,1,0,0,0,0};
int dR[6]={0,0,-1,1,0,0};
int dC[6]={0,0,0,0,-1,1};
struct node{
    int L,R,C;
};
const int N=35;
char a[N][N][N];
bool vis[N][N][N];
int L,R,C,ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>L>>R>>C&&L!=0&&R!=0&&C!=0){
        node start;
        ans=0;
        bool ok=false;
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=L;i++){
            for(int j=1;j<=R;j++){
                for(int k=1;k<=C;k++){
                    cin>>a[i][j][k];
                    if(a[i][j][k]=='S'){
                        start.L=i;
                        start.R=j;
                        start.C=k;
                    }
                }
            }
        }

        queue<tuple<int,int,int,int>> q;
        q.push({start.L,start.R,start.C,0});
        vis[start.L][start.R][start.C]=true;
        while(!q.empty()){
            auto [l,r,c,dis]=q.front();
            q.pop();
            if(a[l][r][c]=='E'){
                cout<<"Escaped in "<<dis<<" minute(s)."<<endl;
                ok=true;
                break;
            }
            for(int k=0;k<6;k++){
                int nl=l+dL[k];
                int nr=r+dR[k];
                int nc=c+dC[k];

                if(nl<1||nl>L||nr<1||nr>R||nc<1||nc>C) continue;

                if(a[nl][nr][nc]!='#'&&vis[nl][nr][nc]==false){
                    vis[nl][nr][nc]=true;
                    q.push({nl,nr,nc,dis+1});
                }
            }
        }
        if(!ok) cout<<"Trapped!"<<endl;
    }
    return 0;
}