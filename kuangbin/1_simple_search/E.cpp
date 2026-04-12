#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N=205;
bool vis[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n&&n!=0){
        memset(vis,false,sizeof(vis));
        queue<pair<string,int>> q;
        q.push({"1",1%n});
        vis[1%n]=true;
        
        while(!q.empty()){
            auto [s,r]=q.front();
            q.pop();

            if(r==0){
                cout<<s<<endl;
                break;
            }

            string s1=s+'0';
            string s2=s+'1';
            int nr1=(10*r)%n;
            int nr2=(10*r+1)%n;
            if(vis[nr1]==false){
                vis[nr1]=true;
                q.push({s1,nr1});
            }
            if(vis[nr2]==false){
                vis[nr2]=true;
                q.push({s2,nr2});
            }
        }
    }
    return 0;
}