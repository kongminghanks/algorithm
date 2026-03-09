//去看CF题解吧
#include <bits/stdc++.h>
using namespace std;

const int N=205;
vector<int> a(N,0);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        int n; cin>>n;
        int cnt0=0; int cnt1=0;
        for(int i=1;i<=n;i++){cin>>a[i]; if(a[i]==0) cnt0++; if(a[i]==1) cnt1++;}
        if(cnt0==0) cout<<"NO"<<endl;
        else if(cnt0==1) cout<<"YES"<<endl;
        else if(cnt1==0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}