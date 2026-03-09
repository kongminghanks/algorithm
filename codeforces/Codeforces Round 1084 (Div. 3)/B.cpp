#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        int n; cin>>n;
        vector<int> a(n,0);
        bool isnondecreasing=true;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=1;i<n;i++){
            if(a[i]<a[i-1]){
                isnondecreasing=false;
                break;
            }
        }
        if(isnondecreasing==false) cout<<1<<endl;
        else cout<<n<<endl;
    }
    return 0;
}