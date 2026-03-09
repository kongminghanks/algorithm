#include <bits/stdc++.h>
using namespace std;

const int N=2*(1e5)+5;
vector<int> a(N,0);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        int n; cin>>n;
        string s; cin>>s;
        int cnt=0;
        for(int i=1;i<=n;i++){
            a[i]=(int)(s[i-1]-'0');
            if(a[i]==1) cnt++;
        }
        if(cnt==0){
            cout<<(n+2)/3<<endl;
            continue;
        }
        int l=1; int r=1;
        while(r<=n&&a[r]==0) r++;
        l=r;
        cnt+=(r/3);
        while(r<=n&&l<=r){
            if(a[l]==1&&l==r) r++;
            while(r<=n&&a[r]==0) r++;
            if(r<=n&&a[r]==1){cnt+=(r-l-1)/3; l=r;}
        }
        if(r==n+1) cnt+=((r-l)/3);
        cout<<cnt<<endl;
    }
    return 0;
}