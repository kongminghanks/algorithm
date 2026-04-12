#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

bool isprime(int x){
    if(x<2) return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}

bool vis[10000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        int a,b;
        cin>>a>>b;
        memset(vis,false,sizeof(vis));
        bool ok=false;

        queue<pair<int,int>> q;
        q.push({a,0});
        vis[a]=true;

        while(!q.empty()){
            auto [cur,step]=q.front();
            q.pop();

            if(cur==b){
                cout<<step<<endl;
                ok=true;
                break;
            }

            string s=to_string(cur);
            for(int i=0;i<4;i++){
                char old=s[i];

                for(char ch='0';ch<='9';ch++){
                    if(ch==old) continue;
                    if(i==0&&ch=='0') continue;

                    s[i]=ch;
                    int nxt=stoi(s);
                    if(isprime(nxt)==true&&vis[nxt]==false){
                        vis[nxt]=true;
                        q.push({nxt,step+1});
                    }
                }

                s[i]=old;
            }
        }
        if(ok==false) cout<<"Impossible"<<endl;
    }
    return 0;
}