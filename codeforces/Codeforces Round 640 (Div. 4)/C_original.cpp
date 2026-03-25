//My original thought about the problem, which needs subtle implemention, resulting in a less elegant solution but can AC.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        ll n,k; cin>>n>>k;
        if(k>n&&k%(n-1)) cout<<k/(n-1)*n+k%(n-1)<<endl;
        else if(k>n&&k%(n-1)==0) cout<<k/(n-1)*n-1<<endl;
        else if(k==n) cout<<n+1<<endl;
        else if(k<n) cout<<k<<endl;
    }
    return 0;
}