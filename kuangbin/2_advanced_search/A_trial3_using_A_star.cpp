#include <bits/stdc++.h>
using namespace std;

int get_h(const string& s){
    int h=0;
    for(int i=0;i<9;i++){
        if(s[i]=='x') continue;
        int val=s[i]-'1';
        h+=abs(i/3-val/3)+abs(i%3-val%3);
    }
    return h;
}

struct Node{
    string s;
    int g,h;
    bool operator>(const Node& other) const {
        return (g+h)>(other.g+other.h);
    }
};

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
char dir[4]={'l','r','u','d'};

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
        s=ch;
        for(int i=1;i<9;i++){
            cin>>ch;
            s+=ch;
        }

        if(!check(s)){
            cout<<"unsolvable"<<endl;
            continue;
        }

        unordered_map<string,int> g_score;
        unordered_map<string,pair<string,char>> parent;
        priority_queue<Node,vector<Node>,greater<Node>> pq;

        pq.push({s,0,get_h(s)});
        g_score[s]=0;

        bool ok=false;

        while(!pq.empty()){
            Node cur=pq.top();
            pq.pop();

            if(cur.s==tar){
                ok=true;
                break;
            }

            int pos=cur.s.find('x');
            int x=pos/3;
            int y=pos%3;

            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx<0||nx>2||ny<0||ny>2) continue;

                int npos=3*nx+ny;
                string nxt=cur.s;
                swap(nxt[pos],nxt[npos]);

                if(g_score.find(nxt)==g_score.end()||g_score[nxt]>cur.g+1){
                    g_score[nxt]=cur.g+1;
                    parent[nxt]={cur.s,dir[k]};
                    pq.push({nxt,g_score[nxt],get_h(nxt)});
                }
            }
        }

        if(ok){
            string path="";
            string curr=tar;
            while(curr!=s){
                path+=parent[curr].second;
                curr=parent[curr].first;
            }
            reverse(path.begin(),path.end());
            cout<<path<<endl;
        }else{
            cout<<"unsolvable"<<endl;
        }
    }
    return 0;
}