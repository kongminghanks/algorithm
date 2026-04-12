#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 205;

int pre[N];     // 前驱余数
int digit[N];   // 当前位是0还是1
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n && n != 0) {
        memset(vis, false, sizeof(vis));

        queue<int> q;

        int start = 1 % n;
        q.push(start);
        vis[start] = true;

        pre[start] = -1;   // 起点没有前驱
        digit[start] = 1;  // 起点是 '1'

        int end = -1;

        while (!q.empty()) {
            int r = q.front();
            q.pop();

            if (r == 0) {
                end = r;
                break;
            }

            // 加 0
            int r0 = (r * 10) % n;
            if (!vis[r0]) {
                vis[r0] = true;
                pre[r0] = r;
                digit[r0] = 0;
                q.push(r0);
            }

            // 加 1
            int r1 = (r * 10 + 1) % n;
            if (!vis[r1]) {
                vis[r1] = true;
                pre[r1] = r;
                digit[r1] = 1;
                q.push(r1);
            }
        }

        // 还原答案
        string ans = "";
        int cur = end;

        while (cur != -1) {
            ans += (digit[cur] + '0');
            cur = pre[cur];
        }

        reverse(ans.begin(), ans.end());

        cout << ans << '\n';
    }

    return 0;
}