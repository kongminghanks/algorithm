#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[1005],sum[1005],ans,n,c;

void dfs(int cur,ll x){
    if(x>c) return;
    if(sum[cur-1]+x<=c){
        ans=max(ans,sum[cur-1]+x);    //prefix utilization
        return;
    }
    ans=max(ans,x);
    dfs(cur-1,x);
    dfs(cur-1,x+a[cur-1]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    dfs(n+1,0);
    cout<<ans<<endl;
    return 0;
}