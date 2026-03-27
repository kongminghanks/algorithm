//A rough version, perhaps it can't work
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
vector<stone> a(n+1,{0,0});
vector<lr> b(m,{0,0});
vector<ll> prefix(n+1,0);
vector<ll> prefix1(n+1,0);
vector<ll> prefix2(n+1,0);
void prefix12(ll ww){
    for(int i=1;i<=n;i++){
        if(a[i].w>=ww){
            prefix1[i]=prefix1[i-1]+a[i].w;
            prefix2[i]=prefix2[i-1]+a[i].w*a[i].v;
        }
        else{
            prefix1[i]=prefix1[i-1];
            prefix2[i]=prefix2[i-1];
        }
    }
}
void prefixx(ll ww){
    for(int i=1;i<=n;i++){
        if(a[i].w>=ww){
            prefix[i]=prefix[i-1]+a[i].w*prefix2[i-1]+a[i].w*a[i].v*prefix1[i-1]+a[i].w*a[i].w*a[i].v;
        }
        else{
            prefix[i]=prefix[i-1];
        }
    }
}
ll check(ll ww){
    prefix12(ww);
    prefixx(ww);
    ll ans=0;
    for(int i=0;i<m;i++){
        ans+=prefix[b[i].r]-prefix[b[i].l-1];
    }
    return ans-s;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m>>s;
    ll maxw=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].w>>a[i].v;
        maxw=max(maxw,a[i].w);
    }
    for(int i=0;i<m;i++){
        cin>>b[i].l>>b[i].r;
    }
    ll l0=0; ll r0=maxw;
    ll minnow=s;
    bool flag=false;
    while(l0<=r0){
        ll mid=l0+(r0-l0)/2;
        if(check(mid)>0){
            minnow=min(minnow,llabs(check(mid)));
            l0=mid+1;
        }else if(check(mid)<0){
            minnow=min(minnow,llabs(check(mid)));
            r0=mid-1;
        }else if(check(mid)==0){
            flag=true;
            cout<<0;
            break;
        }
    }
    if(flag==false) cout<<minnow;
    return 0;
}