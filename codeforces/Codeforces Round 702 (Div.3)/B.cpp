#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        int n; cin>>n;
        int core=n/3;
        int cnt=0;
        vector<int> a(n);
        vector<int> count(3,0);
        for(int i=0;i<n;i++){
            int x; cin>>x;
            a[i]=x%3;
            if(a[i]==0) count[0]++;
            else if(a[i]==1) count[1]++;
            else if(a[i]==2) count[2]++;
        }
        while(count[0]!=core||count[1]!=core||count[2]!=core){
            for(int i=0;i<3;i++){
                if(count[i]>core){
                    cnt++;
                    count[i]--;
                    count[(i+1)%3]++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}