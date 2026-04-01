#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin>>n>>m;
    vector<vector<char>> a(n+2,vector<char>(m+2));
    pair<int,int> start;
    pair<int,int> end;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]=='S'){
                start.first=i;
                start.second=j;
            }else if(a[i][j]=='E'){
                end.first=i;
                end.second=j;            }
        }
    }
    string s;
    cin>>s;
    for(int i=0;i<n+2;i++){
        a[i][0]='#';
        a[i][m+1]='#';
    }
    for(int j=1;j<m+1;j++){
        a[0][j]='#';
        a[n+1][j]='#';
    }
    int ans=0;
    vector<int> p={0,1,2,3};
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    do{
        int x=start.first;
        int y=start.second;
        bool ok=false;
        for(char ch : s){
            int d=p[ch-'0'];
            x+=dx[d];
            y+=dy[d];
            if(a[x][y]=='#'){
                break;
            }else if(a[x][y]=='E'){
                ok=true;
                break;
            }
        }
        if(ok){
            ++ans;
        }
    }while(next_permutation(p.begin(),p.end()));
    cout<<ans;
    return 0;
}