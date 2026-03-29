#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]>a[i-1]) ans+=a[i]-a[i-1]; //Actually, you need to think from the last to the first.
    }                                     //Make this thing nondecreasing, and then it all depends on a[1].
    cout<<ans;
    return 0;
}