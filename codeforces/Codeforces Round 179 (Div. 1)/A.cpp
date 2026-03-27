//Besides the operation towards the array itself, the number of different types of operation could also use Difference array and prefix.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5+1e5;
int n,m,k;
vector<ll> a(N,0);
vector<ll> diff(N,0);
vector<ll> cnt(N,0);
struct op{
    ll l,r,d;
}op[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        diff[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=m;i++){
        cin>>op[i].l>>op[i].r>>op[i].d;
    }
    int x,y;
    while(k--){
        cin>>x>>y;
        cnt[x]++;
        cnt[y+1]--;
    }
    for(int i=1;i<=m;i++){
        cnt[i]+=cnt[i-1];
    }
    for(int i=1;i<=m;i++){
        ll times=cnt[i];
        diff[op[i].l]+=times*op[i].d;
        diff[op[i].r+1]-=times*op[i].d;
    }
    for(int i=1;i<=n;i++){
        a[i]=a[i-1]+diff[i];
        cout<<a[i]<<" ";
    }
    return 0;
}