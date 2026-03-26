//Easy prefix
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    vector<ll> a(n+1,0);
    vector<ll> prefix(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        prefix[i]=prefix[i-1]+a[i];
    }
    sort(a.begin(),a.end());
    vector<ll> prefix0(n+1,0);
    for(int i=1;i<=n;i++){
        prefix0[i]=prefix0[i-1]+a[i];
    }
    int m; cin>>m;
    int type;
    int l,r;
    while(m--){
        cin>>type>>l>>r;
        if(type==1){
            cout<<prefix[r]-prefix[l-1]<<endl;
        }else if(type==2){
            cout<<prefix0[r]-prefix0[l-1]<<endl;
        }else cout<<"Input invalid"<<endl;
    }
    return 0;
}