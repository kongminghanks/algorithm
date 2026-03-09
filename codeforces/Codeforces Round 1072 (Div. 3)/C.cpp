#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while(tt--){
        int n,k;cin>>n>>k;
        int force=0;
        int l=n; int r=n;
        while(r>1){                //通过数学证明可得无论如何r-l<=1
            if(l<=k&&r>=k) break;
            force++;
            l/=2;
            r=r/2+r%2;
        }
        if(l<=k&&r>=k) cout<<force<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}








/*#include <bits/stdc++.h>
using namespace std;

const int N=(1e9)+10;
int dp[N][N];   //dp[n][k],代表总数n的堆里按题目要求能取到k个物品堆的时间
int apple(int n,int k){
    if(n<k) return -1;
    if(dp[n][k]!=-1) return dp[n][k];
    if(!n%2&&(apple(n/2,k)!=-1)) dp[n][k]=apple(n/2,k)+1;
    else if(n%2&&(apple(n/2,k)!=-1)&&(apple(n/2+1,k)!=-1)) dp[n][k]=min(apple(n/2,k),apple(n/2+1,k))+1;
    else if(n%2&&(apple(n/2,k)!=-1)) dp[n][k]=apple(n/2,k)+1;
    else if(n%2&&(apple(n/2+1,k)!=-1)) dp[n][k]=apple(n/2+1,k)+1;
    return dp[n][k];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=1e9;i++) dp[i][i]=0;
    int tt;cin>>tt;
    while(tt--){
        int n,k; cin>>n>>k;
        cout<<apple(n,k)<<'\n';
    }
    return 0;
}*/