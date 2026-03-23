//This version ignored the concept of subsequence, resulting in null two-pointer technnique and absurd tack.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        int n; cin>>n;
        vector<ll> a(n,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int l=0; int r=0;
        int maxlen=0;
        ll maxsum=-1e15;
        while(r<n){
            if(l==r) ++r;
            int matter=1;
            ll sum=a[l];
            while(a[l]*a[r]*matter<0&&r<n){
                sum+=(ll)a[r];
                ++r;
                matter=(-1)*matter;
            }
            if(r-l>maxlen){
                maxlen=r-l;
                maxsum=sum;
            }else if(r-l==maxlen){
                maxsum=max(maxsum,sum);
            }
            l=r;
        }
        cout<<maxsum<<endl;
    }
    return 0;
}