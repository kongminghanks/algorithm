//a more elegant way of greedy
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int mid=n>>1;
    ll ans=a[mid];
    for(int i=mid;i<n-1;i++){
        ll diff=a[i+1]-a[i];
        ll cnt=i-mid+1;
        if(k>=cnt*diff){
            k-=cnt*diff;
            ans=a[i+1];
        }else{
            ans+=(k/cnt);
            k=0;
            break;
        }
    }
    if(k>0){
        ll cnt=n-mid;
        ans+=(k/cnt);
    }
    cout<<ans;
    return 0;
}