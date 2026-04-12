#include <iostream>
#include <queue>
#include <set>
using namespace std;

string merge(string x,string y,int len){
    string s;
    for(int i=0;i<len;i++){
        s=s+y[i];
        s=s+x[i];
    }
    return s;
}

void split(string s,string &s1,string &s2){
    int len=s.size();
    s1="";
    s2="";
    for(int i=0;i<len;i++){
        if(i<len/2) s1=s1+s[i];
        else s2=s2+s[i];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin>>N;
    for(int tt=1;tt<=N;tt++){
        int C; cin>>C;
        string s1,s2,target;
        cin>>s1>>s2>>target;
        bool ok=false;
        set<string> vis;
        queue<pair<string,int>> q;

        q.push({merge(s1,s2,C),1});
        vis.insert(merge(s1,s2,C));

        while(!q.empty()){
            auto [s,step]=q.front();
            q.pop();

            if(s==target){
                cout<<tt<<" "<<step<<endl;
                ok=true;
                break;
            }

            split(s,s1,s2);
            string nxt=merge(s1,s2,C);
            if(vis.find(nxt)==vis.end()){
                vis.insert(nxt);
                q.push({nxt,step+1});
            }
        }
        if(ok==false) cout<<tt<<" "<<-1<<endl;
    }
    return 0;
}