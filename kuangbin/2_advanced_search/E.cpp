#include <bits/stdc++.h>
using namespace std;

string dna[10];
int pos[10];
int n;
int max_depth;

int get_h(){
    int h=0;
    for(int i=0;i<n;i++){
        int remaining=dna[i].length()-pos[i];
        if(remaining>h) h=remaining;
    }
    return h;
}

bool dfs(int step){
    int h=get_h();

    if(step+h>max_depth) return false;

    if(h==0) return true;

    int backup[10];
    memcpy(backup,pos,sizeof(pos));

    char bases[4]={'A','C','G','T'};
    for(int i=0;i<4;i++){
        bool moved=false;

        for(int j=0;j<n;j++){
            if(pos[j]<(int)dna[j].length()&&dna[j][pos[j]]==bases[i]){
                pos[j]++;
                moved=true;
            }
        }

        if(moved){
            if(dfs(step+1)) return true;
            memcpy(pos,backup,sizeof(pos));
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin>>tt;
    while(tt--){
        cin>>n;
        int longest=0;
        for(int i=0;i<n;i++){
            cin>>dna[i];
            longest=max((int)dna[i].length(),longest);
        }

        max_depth=longest;
        while(true){
            memset(pos,0,sizeof(pos));
            if(dfs(0)){
                cout<<max_depth<<endl;
                break;
            }
            max_depth++;
        }
    }
    return 0;
}