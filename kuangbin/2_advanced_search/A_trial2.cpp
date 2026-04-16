#include <bits/stdc++.h>
using namespace std;

int dx[4]={1,0,0,-1};
int dy[4]={0,-1,1,0};
char dir[4]={'d','l','r','u'};

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
            cout<<"unsolvable\n";
            continue;
        }

        unordered_map<string,int> mp;
        vector<string> st;
        vector<int> pre;
        vector<char> op;

        queue<int> q;

        st.push_back(s);
        pre.push_back(-1);
        op.push_back(' ');
        mp[s]=0;

        q.push(0);

        int end_id = -1;

        while(!q.empty()){
            int u=q.front(); q.pop();
            string cur=st[u];

            if(cur==tar){
                end_id=u;
                break;
            }

            int pos=cur.find('x');
            int x=pos/3, y=pos%3;

            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx<0||nx>=3||ny<0||ny>=3) continue;

                string nxt=cur;
                swap(nxt[pos], nxt[nx*3+ny]);

                if(!mp.count(nxt)){
                    int id=st.size();
                    mp[nxt]=id;
                    st.push_back(nxt);
                    pre.push_back(u);
                    op.push_back(dir[k]);
                    q.push(id);
                }
            }
        }

        // 回溯
        string ans="";
        while(end_id!=0){
            ans+=op[end_id];
            end_id=pre[end_id];
        }
        reverse(ans.begin(),ans.end());

        cout<<ans<<"\n";
    }
}