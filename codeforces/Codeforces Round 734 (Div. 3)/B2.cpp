#include <bits/stdc++.h>
using namespace std;

const int N=2*(1e5)+5;
int ans[N];
map<int,vector<int>> a;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        int n,k; cin>>n>>k;
        a.clear();
        memset(ans,0,n*sizeof(int));
        for(int i=0;i<n;i++){
            int x; cin>>x;
            if((int)a[x].size()<k){
                a[x].push_back(i);
            }
        }
        int m=0;
        int color=0;
        for(auto it:a){
            m+=it.second.size();
        }
        m-=m%k;
        for(auto it:a){
            for(auto i:it.second){
                ans[i]=++color;
                color%=k;
                --m;
                if(m==0) break;
            }
            if(m==0) break;
        }
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}