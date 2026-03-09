#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
vector<int> a(N,0);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while(tt--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int pos=-1;
        for(int i=1;i<=n;i++){
            if(i+a[i]!=n+1){
                pos=i;
                break;
            }
        }
        if(pos!=-1){
            int j;
            for(int i=pos;i<=n;i++){
                if(a[i]==n+1-pos){
                    j=i;
                    break;
                }
            }
            while(pos<j) swap(a[pos++],a[j--]);
        }
        for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<'\n';
    }
    return 0;
}