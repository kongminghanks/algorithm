#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        int n; cin>>n;
        vector<int> a(n+1,0); 
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]>3) a[i]=7-a[i];
        }
        int l=0; int r=0;
        int cnt=0;
        while(r<n){
            while(a[l]==a[r]) ++r;
            cnt+=((r-l)/2);
            l=r;
        }
        cout<<cnt<<endl;
    }
    return 0;
}