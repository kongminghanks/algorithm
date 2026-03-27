#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct stone{
    ll w,v;
};
struct lr{
    int l,r;
};
int n,m;
ll s;
vector<stone> a;
vector<lr> b;
vector<ll> prefix1;
vector<ll> prefix2;

void prefix12(ll ww){
    for(int i=1;i<=n;i++){
        if(a[i].w>=ww){
            prefix1[i]=prefix1[i-1]+1;
            prefix2[i]=prefix2[i-1]+a[i].v;
        }
        else{
            prefix1[i]=prefix1[i-1];
            prefix2[i]=prefix2[i-1];
        }
    }
}

ll check(ll ww){
    prefix12(ww);
    ll ans=0;
    for(int i=0;i<m;i++){
        ll cnt = prefix1[b[i].r]-prefix1[b[i].l-1];
        ll sumv = prefix2[b[i].r]-prefix2[b[i].l-1];
        ans += cnt * sumv;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>s;
    a.resize(n+1);
    b.resize(m);
    prefix1.resize(n+1);
    prefix2.resize(n+1);
    ll maxw=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].w>>a[i].v;
        maxw=max(maxw,a[i].w);
    }
    for(int i=0;i<m;i++){
        cin>>b[i].l>>b[i].r;
    }
    ll l0=0, r0=maxw;
    ll minnow=LLONG_MAX;
    while(l0<=r0){
        ll mid=l0+(r0-l0)/2;
        ll val = check(mid);
        minnow=min(minnow,llabs(val - s));
        if(val > s){
            l0=mid+1;
        }else if(val < s){
            r0=mid-1;
        }else{
            cout<<0;
            return 0;
        }
    }
    cout<<minnow;
    return 0;
}