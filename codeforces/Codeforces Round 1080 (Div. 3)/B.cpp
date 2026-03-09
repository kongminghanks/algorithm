#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            int oi = i, oai = a[i];
            while (oi % 2 == 0) oi /= 2;
            while (oai % 2 == 0) oai /= 2;
            if (oi != oai) { ok = false; break; }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}
/*#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin>>tt;
    while(tt--){
        int n; cin>>n;
        vector<int> a(n+1,0);
        int matter=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==i) continue;
            int maxx=max(a[i],i);
            int minn=min(a[i],i);
            if(maxx%minn!=0){
                matter=0;
                break;
            }
            int temp=maxx/minn;
            if(temp&(temp-1)){
                matter=0;
                break;
            }
        }
        if(matter) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}*/