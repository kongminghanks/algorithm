#include <bits/stdc++.h>
using namespace std;

int n,sum;
int a[13];
bool used[13];
int C[13];
bool found=false;

void dfs(int pos,int curSum){
    if(found) return;
    if(curSum>sum) return;
    if(pos==n){
        if(curSum==sum){
            for(int i=0;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
            found=true;
        }
        return;
    }

    for(int i=1;i<=n;i++){
        if(!used[i]){
            used[i]=true;
            a[pos]=i;
            dfs(pos+1,curSum+C[pos]*a[pos]);
            used[i]=false;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>sum;
    C[0]=C[n-1]=1;
    for(int i=1;i<n-1;i++){
        C[i]=C[i-1]*(n-i)/i;
    }
    dfs(0,0);
    return 0;
}