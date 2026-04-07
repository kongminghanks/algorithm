#include <bits/stdc++.h>
using namespace std;

int n;

int pos[20];
bool usedCol[20];
bool diag1[40];
bool diag2[40];

int total=0;
vector<vector<int>> ans;

void dfs(int row){
    if(row==n+1){
        total++;

        if((int)ans.size()<3){
            ans.push_back(vector<int>(pos+1,pos+n+1));
        }
        return;
    }

    for(int c=1;c<=n;c++){
        if(!usedCol[c]&&!diag1[row-c+n]&&!diag2[row+c]){
            pos[row]=c;
            usedCol[c]=true;
            diag1[row-c+n]=true;
            diag2[row+c]=true;

            dfs(row+1);

            usedCol[c]=false;
            diag1[row-c+n]=false;
            diag2[row+c]=false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    dfs(1);
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<total;
    return 0;
}