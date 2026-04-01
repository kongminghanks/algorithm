#include <bits/stdc++.h>
using namespace std;

struct students{
    int l,r;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        int n; cin>>n;
        vector<students> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].r;
        a[0].l=a[1].l;
        int t=0;     //t is the last occupied time point
        for(int i=1;i<=n;i++){
            if(a[i].l>t){
                t=a[i].l;
                cout<<t<<" ";
            }else if(a[i].l<=t&&a[i].r>t){
                ++t;
                cout<<t<<" ";
            }else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}