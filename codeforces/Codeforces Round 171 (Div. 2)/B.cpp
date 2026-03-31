#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll t;
    cin >> n >> t;
    vector<ll> a(n+1,0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = 1;
    ll ans = 0;
    int maxx = 0;

    while (r <= n) {
        // 扩展右端点
        ans += a[r];

        // 若不合法，收缩左端点
        while (ans > t) {
            ans -= a[l];
            ++l;
        }

        // 此时 [l, r] 一定合法
        maxx = max(maxx, r - l + 1);

        ++r;
    }

    cout << maxx;
    return 0;
}