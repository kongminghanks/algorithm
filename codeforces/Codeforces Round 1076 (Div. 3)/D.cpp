#include <bits/stdc++.h>
using namespace std;

const int N=10+2*1e5;
vector<int> a(N,0);
vector<int> b(N,0);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while(tt--){
        int n;cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        sort(a.begin()+1,a.begin()+n+1,greater<int>());
        long long ans=0;
        int cnt=0;
        int carry=0;
        for(int i=1,j=1,k=1;i<=n;){
            while(j<=n&&a[i]==a[j]) ++j;
            cnt=j-i+carry;
            while(k<=n&&cnt>=b[k]){
                cnt-=b[k];
                ++k;
            }
            carry=cnt;
            ans=max(ans,(long long)(k-1)*a[i]);
            i=j;
        }
        cout<<ans<<endl;
    }
    return 0;
}