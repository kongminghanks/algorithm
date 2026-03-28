//c++ version
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        int k,a1,b1,a2,b2;
        cin>>k>>a1>>b1>>a2>>b2;
        if(a1+a2>b1+b2+k) cout<<"NO"<<endl;
        else if(a1+a2==b1+b2+k&&a1>b1&&a2>b2) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}