#include <bits/stdc++.h>
using namespace std;

struct State{
    int last_feed;
    vector<int> chosen;
    vector<int> current_v;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int v; cin>>v;
    vector<int> vm(v+1);
    for(int i=1;i<=v;i++) cin>>vm[i];
    int g; cin>>g;
    vector<vector<int>> gg(g+1,vector<int>(v+1));
    for(int i=1;i<=g;i++){
        for(int j=1;j<=v;j++){
            cin>>gg[i][j];
        }
    }

    queue<State> q;
    q.push({0,{},vector<int>(v+1,0)});

    while(!q.empty()){
        State curr=q.front();
        q.pop();

        bool ok=true;
        for(int i=1;i<=v;i++){
            if(curr.current_v[i]<vm[i]){
                ok=false;
                break;
            }
        }

        if(ok){
            cout<<curr.chosen.size();
            for(int feed:curr.chosen){
                cout<<" "<<feed;
            }
            cout<<endl;
            return 0;
        }

        for(int i=curr.last_feed+1;i<=g;i++){
            State next_state=curr;
            next_state.last_feed=i;
            next_state.chosen.push_back(i);

            for(int j=1;j<=v;j++){
                next_state.current_v[j]+=gg[i][j];
            }

            q.push(next_state);
        }
    }
    return 0;
}