#include <bits/stdc++.h>
using namespace std;

const int D=101;
struct bag{
    double m,v,av;
};
vector<bag> bags(D);
bool fun(bag a,bag b){
    return a.av>b.av;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    double N,T; cin>>N>>T;
    for(int i=1;i<=N;i++){
        cin>>bags[i].m>>bags[i].v;
        bags[i].av=bags[i].v/bags[i].m;
    }
    sort(bags.begin()+1,bags.begin()+N+1,fun);
    double val=0.0;
    for(int i=1;i<=N;i++){
        if(T>=bags[i].m){
            val+=bags[i].v;
            T-=bags[i].m;
        }else{
            val+=T*bags[i].av;
            break;
        }
    }
    cout<<fixed<<setprecision(2)<<val;
    return 0;
}