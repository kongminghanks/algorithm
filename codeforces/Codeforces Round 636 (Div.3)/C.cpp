#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        int n; cin>>n;
        vector<ll> a(n,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
        } 
        ll ans=0;
        ll maxx=a[0];
        for(int i=1;i<n;i++){
            if((maxx>0&&a[i]>0)||(maxx<0&&a[i]<0)){
                maxx=max(maxx,a[i]);
            }else{
                ans+=maxx;
                maxx=a[i];
            }
        }
        ans+=maxx;     //Don't forget the last piece of sequence.
        cout<<ans<<endl;
    }
    return 0;
}