//TLE
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5+1e5;
int n,m,k;
vector<ll> a(N,0);
vector<ll> diff(N,0);
struct op{
    int l,r;
    ll d;
}op[N];
void lr(int l,int r,ll d){
    diff[l]+=d;
    diff[r+1]-=d;
}
void fun(int x,int y){
    for(int i=x;i<=y;i++){
        lr(op[i].l,op[i].r,op[i].d);
    }
}
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
        fun(x,y);
    }
    for(int i=1;i<=n;i++){
        a[i]=a[i-1]+diff[i];
        cout<<a[i]<<" ";
    }
    return 0;
}