#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while(tt--){
        int n,s,x;cin>>n>>s>>x;
        int sum=0;
        while(n--){
            int m;cin>>m;
            sum+=m;
        }
        if(sum<=s&&(s-sum)%x==0) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}