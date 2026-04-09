#include <bits/stdc++.h>
using namespace std;

map<string,int> a;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s0; cin>>s0;
    string tar="123804765";
    unordered_map<string,int> dist;
    queue<string> q;
    q.push(s0);
    dist[s0]=0;

    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    while(!q.empty()){
        string cur=q.front();
        q.pop();
        if(cur==tar){
            cout<<dist[cur]<<endl;
            return 0;
        }

        int pos=cur.find('0');
        int x=pos/3;
        int y=pos%3;

        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];

            if(nx<0||nx>2||ny<0||ny>2) continue;

            int npos=nx*3+ny;
            string nxt=cur;
            swap(nxt[pos],nxt[npos]);

            if(!dist.count(nxt)){
                dist[nxt]=dist[cur]+1;
                q.push(nxt);
            }
        }
    }
    return 0;
}