//classic two-pointer technique
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct fri{
    ll m,s;
};
bool fun(fri x,fri y){
    return x.m<y.m;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll d;
    cin>>n>>d;
    vector<fri> a(n,{0,0});
    for(int i=0;i<n;i++){
        cin>>a[i].m>>a[i].s;
    }
    sort(a.begin(),a.end(),fun);  //The reason why sort it by m is the difference request is towards m, which could be solved by a sliding window.
    int l=0;
    ll ans=0;
    ll sum=0;
    for(int r=0;r<n;r++){
        sum+=a[r].s;
        while(a[r].m-a[l].m>=d){
            sum-=a[l].s;
            ++l;
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}