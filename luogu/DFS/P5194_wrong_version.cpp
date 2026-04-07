#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N;
ll C;
ll w[1005];
ll ans = 0;
ll suffix_sum[1005];

void dfs(int pos, ll sum) {
    // 更新答案
    if (sum > C) return;
    ans = max(ans, sum);
    if (sum == C) return;
    
    // 剪枝：如果当前位置不合法
    if (pos < 1) return;
    
    // 核心剪枝：即使选上后面所有砝码也无法超过当前最优解
    if (sum + suffix_sum[pos] <= ans) return;
    
    // 尝试选或不选当前砝码（从大到小）
    for (int i = pos; i >= 1; i--) {
        if (sum + w[i] <= C) {
            dfs(i - 1, sum + w[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> C;
    
    // 读入并过滤
    int validN = 0;
    for (int i = 1; i <= N; i++) {
        ll x;
        cin >> x;
        if (x <= C) {
            w[++validN] = x;
        } else {
            // 跳过剩余输入
            for (int j = i + 1; j <= N; j++) cin >> x;
            break;
        }
    }
    N = validN;
    
    // 计算后缀和
    suffix_sum[N + 1] = 0;
    for (int i = N; i >= 1; i--) {
        suffix_sum[i] = suffix_sum[i + 1] + w[i];
    }
    
    // 从最大的砝码开始搜索
    dfs(N, 0);
    
    cout << ans << endl;
    
    return 0;
}