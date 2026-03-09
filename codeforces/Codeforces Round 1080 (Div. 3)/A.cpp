#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        int n; cin>>n;
        vector<int> a(n);
        int cnt1=0;
        int cnt67=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==1) cnt1++;
            if(a[i]==67) cnt67++;
        }
        if(cnt67) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}