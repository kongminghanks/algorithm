#include <bits/stdc++.h>
using namespace std;

int vis[105][105][105];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int S,N,M;
    while(cin>>S>>N>>M&&S!=0&&N!=0&&M!=0){
        if(S%2){
            cout<<"NO"<<endl;
            continue;
        }

        memset(vis,-1,sizeof(vis));
        bool ok=false;

        queue<tuple<int,int,int>> q;

        q.push({S,0,0});
        vis[S][0][0]=0;

        while(!q.empty()){
            auto [a,b,c]=q.front();
            q.pop();

            if(a==S/2&&b==S/2){
                cout<<vis[a][b][0]<<endl;
                ok=true;
                break;
            }else if(a==S/2&&c==S/2){
                cout<<vis[a][0][c]<<endl;
                ok=true;
                break;
            }else if(b==S/2&&c==S/2){
                cout<<vis[0][b][c]<<endl;
                ok=true;
                break;
            }

            if(a>0&&b<N&&vis[max(0,a-(N-b))][min(N,b+a)][c]==-1){
                vis[max(0,a-(N-b))][min(N,b+a)][c]=vis[a][b][c]+1;
                q.push({max(0,a-(N-b)),min(N,b+a),c});
            }
            if(a>0&&c<M&&vis[max(0,a-(M-c))][b][min(M,c+a)]==-1){
                vis[max(0,a-(M-c))][b][min(M,c+a)]=vis[a][b][c]+1;
                q.push({max(0,a-(M-c)),b,min(M,c+a)});
            }
            if(b>0&&c<M&&vis[a][max(0,b-(M-c))][min(M,c+b)]==-1){
                vis[a][max(0,b-(M-c))][min(M,c+b)]=vis[a][b][c]+1;
                q.push({a,max(0,b-(M-c)),min(M,c+b)});
            }
            if(b>0&&a<S&&vis[min(S,a+b)][max(0,b-(S-a))][c]==-1){
                vis[min(S,a+b)][max(0,b-(S-a))][c]=vis[a][b][c]+1;
                q.push({min(S,a+b),max(0,b-(S-a)),c});
            }
            if(c>0&&a<S&&vis[min(S,a+c)][b][max(0,c-(S-a))]==-1){
                vis[min(S,a+c)][b][max(0,c-(S-a))]=vis[a][b][c]+1;
                q.push({min(S,a+c),b,max(0,c-(S-a))});
            }
            if(c>0&&b<N&&vis[a][min(N,b+c)][max(0,c-(N-b))]==-1){
                vis[a][min(N,b+c)][max(0,c-(N-b))]=vis[a][b][c]+1;
                q.push({a,min(N,b+c),max(0,c-(N-b))});
            }
        }
        if(!ok) cout<<"NO"<<endl;
    }
    return 0;
}