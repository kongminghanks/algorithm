#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        int n; cin>>n;
        vector<int> a(n,0);
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a.rbegin(),a.rend());
        ll balance=0;              //It is advised to use ll, 'cause int maybe not enough.
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(a[i]%2==0) balance+=(ll)a[i];
            }else{
                if(a[i]%2) balance-=(ll)a[i];
            }
        }
        if(balance>0) cout<<"Alice"<<endl;
        else if(balance==0) cout<<"Tie"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}