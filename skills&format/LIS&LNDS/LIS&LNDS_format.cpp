#include <iostream>
#include <algorithm>
#include <vector>

const int MAXN = 100005;

int n;
int a[MAXN];        // 原数组
int d[MAXN];        // 状态数组：d[x] 表示长度为 x 的子序列的末尾元素最小值
int di[MAXN];       // 记录 d[x] 对应的原数组下标
int pre[MAXN];      // 记录前驱节点，用于还原路径
int res[MAXN];      // 存放最终的结果

int get_LIS() {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        // 1. 二分查找：找到第一个大于 a[i] 的位置
        // 注意：如果是“最长上升子序列(严格递增)”，这里需要改成 lower_bound
        int tmp = std::upper_bound(d, d + ans, a[i]) - d;
        
        // 2. 记录前驱节点（处理边界情况）
        pre[i] = tmp ? di[tmp - 1] : -1;
        
        // 3. 更新状态
        d[tmp] = a[i];
        di[tmp] = i;
        
        // 4. 如果长度增加，更新 ans
        if (tmp == ans) {
            ++ans;
        }
    }
    return ans;
}

// 辅助函数：还原出具体的子序列
void get_sequence(int ans) {
    int len = ans;
    int current_idx = di[ans - 1]; // 最后一个元素在原数组中的下标
    
    for (int k = len; k >= 1; --k) {
        res[k] = a[current_idx];
        current_idx = pre[current_idx];
    }
}