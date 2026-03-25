#include <bits/stdc++.h>
using namespace std;

const double eps=1e-4;
double w0,w,m;

void solve(double l,double r){
    double k=(l+r)/2.0;
    double a=w0;
    if(r-l<eps){
        cout<<fixed<<setprecision(1)<<k*100;
        exit(0);
    }
    for(int i=1;i<=m;i++){
        a=a*(1+k)-w;
    }
    if(a>0) solve(l,k);
    else if(a<0) solve(k,r);
    else if(a==0){
        cout<<fixed<<setprecision(1)<<k*100;
        exit(0);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>w0>>w>>m;
    double l=0.0;
    double r=4.0;
    solve(l,r);
    return 0;
}