#include <bits/stdc++.h>
using namespace std;

string s,t;
vector<int> ss(26,0);
vector<int> tt(26,0);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin>>T;
    while(T--){
        s.clear();
        t.clear();
        ss.assign(26,0);
        tt.assign(26,0);
        cin>>s>>t;
        int lens=s.size();
        int lent=t.size();
        int x;
        for(int i=0;i<lens;i++){
            x=s[i]-'a';
            ss[x]++;
        }
        for(int i=0;i<lent;i++){
            x=t[i]-'a';
            tt[x]++;
        }
        bool im=true;
        for(int i=0;i<26;i++){
            if(ss[i]>tt[i]){
                im=false;
                break;
            }
        }
        if(im==false){
            cout<<"Impossible"<<endl;
            continue;
        }
        for(int i=0;i<26;i++){
            tt[i]=tt[i]-ss[i];
        }
        t.clear();
        char ch;
        int num;
        for(int i=0;i<26;i++){
            ch=(char)('a'+i);
            num=tt[i];
            t=t+string(num,ch);
        }
        int sp=0; int tp=0;
        while(sp<lens){
            while(tp<(int)t.size()&&t[tp]<=s[sp]) ++tp;
            while(sp<lens&&s[sp]<=t[tp]){
                t.insert(t.begin()+tp,s[sp]);
                ++sp;
                ++tp;
            }
        }
        cout<<t<<endl;
    }
    return 0;
}