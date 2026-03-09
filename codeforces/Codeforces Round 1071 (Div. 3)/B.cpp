#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        int n; cin>>n;
        vector<int> a(n,0);
        vector<int> diff(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i) diff[i]=a[i]-a[i-1];
            ans+=abs(diff[i]);
        }
        int maxx=0;
        for(int i=0;i<n-2;i++){
            maxx=max(maxx,abs(diff[i+1])+abs(diff[i+2])-abs(diff[i+1]+diff[i+2]));
        }
        int begin=abs(diff[1]);
        int end=abs(diff[n-1]);
        maxx=max(begin,max(end,maxx));
        cout<<ans-maxx<<endl;
    }
    return 0;
}