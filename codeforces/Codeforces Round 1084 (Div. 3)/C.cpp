#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    stack<char> a;
    while(tt--){
        int n; cin>>n;
        while(n--){
            char ch; cin>>ch;
            if(a.empty()) a.push(ch);
            else{
                if(a.top()==ch){
                    a.pop();
                }else{
                    a.push(ch);
                }
            }
        }
        if(a.empty()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        while(a.size()) a.pop();
    }
    return 0;
}