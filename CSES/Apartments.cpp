//It's an obvious greedy problem which can be conquered by sorting and two-pointer technique.
//I've seen a problem much more complex than this one, which is that different person has different k value.
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> applicant(n,0);
    vector<int> apartment(m,0);
    for(int i=0;i<n;i++) cin>>applicant[i];
    for(int i=0;i<m;i++) cin>>apartment[i];
    sort(applicant.begin(),applicant.end());
    sort(apartment.begin(),apartment.end());
    int i=0; int j=0;
    int ans=0;
    while(i<n&&j<m){
        if(apartment[j]<applicant[i]-k){
            ++j;
        }else if(apartment[j]>applicant[i]+k){
            ++i;
        }else{
            ++ans;
            ++i;
            ++j;
        }
    }
    cout<<ans;
    return 0;
}