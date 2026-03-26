#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s; cin>>s;
    int len=s.size();
    vector<int> prefix(len+1,0);
    for(int i=2;i<=len;i++){
        if(s[i-2]==s[i-1]) prefix[i]=prefix[i-1]+1;
        else prefix[i]=prefix[i-1];
    }
    int m; cin>>m;
    int l,r;
    while(m--){
        cin>>l>>r;
        cout<<prefix[r]-prefix[l]<<endl;  //P.S the ans is prefix[r]-prefix[l], not prefix[r]-prefix[l-1], 'cause it needs to be a pair.
    }
    return 0;
}