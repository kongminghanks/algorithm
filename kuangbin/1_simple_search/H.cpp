#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int A,B,C;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>A>>B>>C;
    bool ok=false;

    set<pair<int,int>> p;
    queue<tuple<int,int,int,string>> q;
    p.insert({0,0});
    q.push({0,0,0,""});

    while(!q.empty()){
        auto [a,b,step,s]=q.front();
        q.pop();

        string nxt;

        if(a==C||b==C){
            cout<<step<<endl;
            for(int i=0;i<(int)s.size();i++){
                if(s[i]=='1') cout<<"FILL(1)"<<endl;
                else if(s[i]=='2') cout<<"FILL(2)"<<endl;
                else if(s[i]=='3') cout<<"DROP(1)"<<endl;
                else if(s[i]=='4') cout<<"DROP(2)"<<endl;
                else if(s[i]=='5') cout<<"POUR(1,2)"<<endl;
                else if(s[i]=='6') cout<<"POUR(2,1)"<<endl;
            }
            ok=true;
            break;
        }

        if(a<A&&p.find({A,b})==p.end()){
            p.insert({A,b});
            nxt=s+'1';
            q.push({A,b,step+1,nxt});
        }

        if(b<B&&p.find({a,B})==p.end()){
            p.insert({a,B});
            nxt=s+'2';
            q.push({a,B,step+1,nxt});
        }

        if(a>0&&p.find({0,b})==p.end()){
            p.insert({0,b});
            nxt=s+'3';
            q.push({0,b,step+1,nxt});
        }

        if(b>0&&p.find({a,0})==p.end()){
            p.insert({a,0});
            nxt=s+'4';
            q.push({a,0,step+1,nxt});
        }

        if(b<B&&p.find({max(a-(B-b),0),min(b+a,B)})==p.end()){
            p.insert({max(a-(B-b),0),min(b+a,B)});
            nxt=s+'5';
            q.push({max(a-(B-b),0),min(b+a,B),step+1,nxt});
        }

        if(a<A&&p.find({min(a+b,A),max(b-(A-a),0)})==p.end()){
            p.insert({min(a+b,A),max(b-(A-a),0)});
            nxt=s+'6';
            q.push({min(a+b,A),max(b-(A-a),0),step+1,nxt});
        }
    }
    if(!ok) cout<<"impossible"<<endl;
    return 0;
}