#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        int n; cin>>n;
        int ans=n/2+n%2;
        for(int i=0;i<n;i++){
            if(i%2==0){
                ans-=i;
                cout<<ans<<" ";
            }else{
                ans+=i;
                cout<<ans<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}