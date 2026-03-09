#include <bits/stdc++.h>
using namespace std;

const int N=205;
struct card{
    int val;
    int color;   //red:0  blue:1
}a[N];

bool cmp(struct card a,struct card b){
    return a.val<b.val;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        int n; cin>>n;
        int sao=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].val;
            a[i].color=sao;
            sao=sao^1;
        }
        sort(a+1,a+n+1,cmp);
        bool matter=true;
        for(int i=2;i<=n;i++){
            if(a[i].color==a[i-1].color){matter=false;break;}
        }
        matter==true? cout<<"YES"<<endl :cout<<"NO"<<endl;
    }
    return 0;
}