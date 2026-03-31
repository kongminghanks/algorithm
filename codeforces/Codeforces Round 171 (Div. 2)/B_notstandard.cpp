#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll t;
    cin>>n>>t;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=1; int r=1;
    ll ans=0;
    int maxx=0;
    while(r<=n){
        while(r<=n&&ans+a[r]<=t){
            ans+=a[r];
            ++r;
        }
        maxx=max(maxx,r-l);
        if(r>n) break;
        ans+=a[r];
        ++r;
        while(l<=r&&ans>t){
            ans-=a[l];
            ++l;
        }
    }
    cout<<maxx;
    return 0;
}