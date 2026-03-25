#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        int n,k; cin>>n>>k;
        string s; cin>>s;
        int ans=0;
        s=string(k,'0')+s+string(k,'0');
        s=s+'1';
        s='1'+s;
        int l=0;
        int r=0;
        int len=s.size();
        while(r<len){
            if(l==r) ++r;
            if(r>=len) break;
            while(s[r]=='0') ++r;
            ans+=(r-l)/(k+1)-1;    //Please record this formula, which is vital and straight-forward.
            l=r;
        }
        cout<<ans<<endl;
    }
    return 0;
}