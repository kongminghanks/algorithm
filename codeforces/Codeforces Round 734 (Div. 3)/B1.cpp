#include <bits/stdc++.h>
using namespace std;

vector<int> a(26,0);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    string s;
    int num=0;
    while(tt--){
        a.assign(a.size(),0);
        cin>>s;
        int len=s.size();
        for(int i=0;i<len;i++){
            num=s[i]-'a';
            a[num]++;
        }
        int cnt1=0; int cnt2=0;
        for(int i=0;i<26;i++){
            if(a[i]==1) cnt1++;
            else if(a[i]>=2) cnt2++;
        }
        cout<<cnt2+cnt1/2<<endl;
    }
    return 0;
}