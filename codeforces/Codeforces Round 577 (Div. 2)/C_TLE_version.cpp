//brute force is useless in such a problem
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    while(k>0){
        int mid=a[n/2];
        auto left=a.begin()+n/2;
        auto right=upper_bound(a.begin(),a.end(),mid);
        int len=right-left;
        if(len<=k&&len>0){
            auto it=left;
            while(it!=right){
                (*it)++;
                it++;
            }
            k-=len;
            sort(a.begin(),a.end());
        }else break;
    }
    cout<<a[n/2];
    return 0;
}