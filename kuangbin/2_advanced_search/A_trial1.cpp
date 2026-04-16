#include <bits/stdc++.h>
using namespace std;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

bool check(string s){
    int cnt=0;
    for(int i=0;i<9;i++){
        if(s[i]=='x') continue;
        for(int j=i+1;j<9;j++){
            if(s[j]=='x') continue;
            if(s[i]>s[j]) cnt++;
        }
    }
    return cnt%2==0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string tar="12345678x";
    string s;
    char ch;
    while(cin>>ch){
        bool ok=false;
        s=ch;
        for(int i=1;i<9;i++){
            cin>>ch;
            s+=ch;
        }
        
        if(!check(s)){
            cout<<"unsolvable"<<endl;
            continue;
        }
        unordered_map<string,char> dist;
        unordered_map<string,string> prex;
        queue<string> q;

        q.push(s);
        dist[s]='z';

        while(!q.empty()){
            auto cur=q.front();
            q.pop();

            if(cur==tar){
                ok=true;
                break;
            }

            int pos=cur.find('x');
            int x=pos/3;
            int y=pos%3;

            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx<0||nx>2||ny<0||ny>2) continue;

                int npos=3*nx+ny;
                string nxt=cur;
                swap(nxt[pos],nxt[npos]);

                if(dist.count(nxt)==0){
                    q.push(nxt);
                    prex[nxt]=cur;
                    if(k==0){
                        dist[nxt]='l';
                    }else if(k==1){
                        dist[nxt]='r';
                    }else if(k==2){
                        dist[nxt]='u';
                    }else if(k==3){
                        dist[nxt]='d';
                    }
                }
            }
        }

        if(!ok){
            cout<<"unsolvable"<<endl;
            continue;
        }

        vector<char> path;

        string t=tar;
        while(dist[t]!='z'){
            path.push_back(dist[t]);
            t=prex[t];
        }
        reverse(path.begin(),path.end());

        for(char i:path) cout<<i;
        cout<<endl;
    }    
    return 0;
}