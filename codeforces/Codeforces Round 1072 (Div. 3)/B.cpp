#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while(tt--){
        int s,k,m;cin>>s>>k>>m;
        if(k>s){
            if((m%k)>=s) cout<<0<<endl;
            else if((m%k)<s) cout<<s-(m%k)<<endl;
        }else{
            int x=m%(2*k);
            if(x==0) cout<<s<<endl;
            else if(x>0&&x<k) cout<<s-x<<endl;
            else if(x==k) cout<<k<<endl;
            else if(x>k) cout<<2*k-x<<endl;
        }
    }
    return 0;
}