#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        int a,b,c; cin>>a>>b>>c;
        bool isok=false;
        if(((2*b-c>0)&&(2*b-c)%a==0)
        ||((2*b-a>0)&&(2*b-a)%c==0)
        ||((a+c)%2==0&&((a+c)>>1)%b==0)) isok=true;
        if(isok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}