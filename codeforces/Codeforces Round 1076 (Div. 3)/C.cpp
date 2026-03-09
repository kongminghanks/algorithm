#include <bits/stdc++.h>

using namespace std;

const int N=(2*1e5)+10;
vector<int> a(N,0);
vector<int> tree(N,0);
int lowbit(int x){return x&(-x);}
void update(int x,int d){
    while(x<=N){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
int sum(int x){
    int ans=0;
    while(x>0){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
void initTree(vector<int>& p){
    for(int i=0;i<N;i++) p[i]=0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while(tt--){
        initTree(tree);
        initTree(a);
        int n,q;cin>>n>>q;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){int x;cin>>x;a[i]=max(a[i],x);}
        for(int i=n-1;i>=1;i--){a[i]=max(a[i],a[i+1]);}
        for(int i=1;i<=n;i++) update(i,a[i]);
        while(q--){
            int l,r;cin>>l>>r;
            cout<<sum(r)-sum(l)+a[l]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}