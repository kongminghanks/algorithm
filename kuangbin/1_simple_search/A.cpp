#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N=10;
vector<vector<char>> a(N,vector<char>(N));
int n,k,total;
bool usedCol[N]={false};

void dfs(int row,int cnt){
    
    if(cnt==k){
        total++;
        return;
    }

    if(row>n) return;

    dfs(row+1,cnt);       //not put

    for(int i=1;i<=n;i++){//put
        if(a[row][i]=='#'&&usedCol[i]==false){
            usedCol[i]=true;
            dfs(row+1,cnt+1);
            usedCol[i]=false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>k&&n!=-1&&k!=-1){
        total=0;
        memset(usedCol,false,sizeof(usedCol));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
            }
        }
        dfs(1,0);
        cout<<total<<endl;
    }
    return 0;
}