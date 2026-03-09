#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while(tt--){
        int n;cin>>n;
        if(n==2||n==3) cout<<n<<endl;
        else if(n%2) cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}