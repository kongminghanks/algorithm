#include <bits/stdc++.h>
using namespace std;

int dx[4]={1,0,0,-1};
int dy[4]={0,-1,1,0};
char dir[4]={'d','l','r','u'};

int get_h(const string& s,const int pos_in_target[]){
    int h=0;
    for(int i=0;i<9;i++){
        if(s[i]=='X') continue;
        int val=s[i]-'1';
        int target_pos=pos_in_target[val];
        h+=abs(i/3-target_pos/3)+abs(i%3-target_pos%3);
    }
    return h;
}

int count_inversions(string s){
    int cnt=0;
    for(int i=0;i<9;i++){
        if(s[i]=='X') continue;
        for(int j=i+1;j<9;j++){
            if(s[j]=='X') continue;
            if(s[j]<s[i]) cnt++;
        }
    }
    return cnt;
}

bool is_solvable(const string& start,const string& target){
    int cnt1=count_inversions(start);
    int cnt2=count_inversions(target);
    return cnt1%2==cnt2%2;
}

struct Node{
    string s;
    int g,h;
    string path;
    bool operator>(const Node& other) const {
        if((g+h)!=(other.g+other.h)){
            return (g+h)>(other.g+other.h);
        }
        return path>other.path;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin>>T;
    string start,target;
    for(int tt=1;tt<=T;tt++){
        cin>>start>>target;
        int pos_in_target[9];
        for(int i=0;i<9;i++){
            if(target[i]=='X') continue;
            pos_in_target[target[i]-'1']=i;
        }

        if(!is_solvable(start,target)){
            cout<<"Case "<<tt<<": unsolvable"<<endl;
            continue;
        }

        unordered_map<string,int> g_score;
        priority_queue<Node,vector<Node>,greater<Node>> pq;

        pq.push({start,0,get_h(start,pos_in_target),""});
        g_score[start]=0;

        bool ok=false;

        string final_path="";
        while(!pq.empty()){
            Node cur=pq.top();
            pq.pop();

            if(cur.s==target){
                ok=true;
                final_path=cur.path;
                break;
            }

            int pos=cur.s.find('X');
            int x=pos/3;
            int y=pos%3;

            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx<0||nx>2||ny<0||ny>2) continue;

                int npos=3*nx+ny;
                string nxt=cur.s;
                swap(nxt[pos],nxt[npos]);

                if(g_score.find(nxt)==g_score.end()||g_score[nxt]>=cur.g+1){
                    g_score[nxt]=cur.g+1;
                    pq.push({nxt,g_score[nxt],get_h(nxt,pos_in_target),cur.path+dir[k]});
                }
            }
        }

        if(!ok){
            cout<<"Case "<<tt<<": unsolvable"<<endl;
            continue;
        }

        cout<<"Case "<<tt<<": "<<final_path.size()<<endl<<final_path<<endl;
    }
    return 0;
}