#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        int n,h,l; cin>>n>>h>>l;
        int maxx=max(h,l);
        int minn=min(h,l);
        int matter=0;
        int x;
        int cnt=0;
        for(int i=0;i<n;i++){
            cin>>x;
            if(x<=maxx) cnt++;
            if(x>minn&&x<=maxx) matter++;
        }
        matter>cnt/2? cout<<cnt-matter<<endl : cout<<matter+(cnt-2*matter)/2<<endl;
    }
    return 0;
}