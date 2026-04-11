#include <iostream>
#include <cstring>
using namespace std;

int M,N;
int a[17][17];
int flip[17][17];

int get(int x,int y){
    int res=a[x][y];

    if(flip[x][y]) res^=1;
    if(x>0&&flip[x-1][y]) res^=1;
    if(x<M-1&&flip[x+1][y]) res^=1;
    if(y>0&&flip[x][y-1]) res^=1;
    if(y<N-1&&flip[x][y+1]) res^=1;

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>M>>N;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>a[i][j];
        }
    }

    int ans=1e9;
    int best[17][17];

    for(int s=0;s<(1<<N);s++){
        memset(flip,0,sizeof(flip));

        for(int j=0;j<N;j++){
            if(s&(1<<j)){
                flip[0][j]=1;
            }
        }

        for(int i=1;i<M;i++){
            for(int j=0;j<N;j++){
                if(get(i-1,j)==1){
                    flip[i][j]=1;
                }
            }
        }
        bool ok=true;
        for(int j=0;j<N;j++){
            if(get(M-1,j)==1){
                ok=false;
                break;
            }
        }
        if(!ok) continue;

        int cnt=0;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                cnt+=flip[i][j];
            }
        }

        if(cnt<ans){
            ans=cnt;
            memcpy(best,flip,sizeof(flip));
        }
    }
    if(ans==1e9) cout<<"IMPOSSIBLE"<<endl;
    else{
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                cout<<best[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}