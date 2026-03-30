#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> p(n),a(n);
    for(int i=0;i<n;i++) cin>>p[i];
    vector<int> blocks;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0||a[i]!=a[i-1]){
            blocks.push_back(a[i]);
        }
    }
    int k=0;
    int len=blocks.size();
    for(int i=0;i<n;i++){
        if(k<len&&p[i]==blocks[k]) ++k;
    }
    if(k==len) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}