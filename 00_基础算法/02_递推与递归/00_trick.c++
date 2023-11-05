/* 1-递归实现指数型枚举 */
function<void(int, int)> dfs = [&](int u, int state) -> void {
    if (u == n) {
        for (int i = 0; i < n; i++) {
            if (state >> i & 1) {
                cout << i + 1 << " ";
            }
        }
        printf("\n");
        return;
    }
    dfs(u + 1, state | 1 << u);
    dfs(u + 1, state);
};


/* 2-递归实现排列型枚举 */
function<void(int, int)> dfs = [&](int u, int state) -> void {
    if (u > n) {
        for (int i = 0; i < n; i++) {
            printf("%d ", chosen[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!(state >> i & 1)) {
            chosen.push_back(i);
            dfs(u + 1, state | 1 << i);
            chosen.pop_back();
        }
    }
};


/* 3-递归实现组合型枚举 */
function<void(int, int)> dfs = [&](int u, int start) -> void {
    if (u > m) {
        for (int i = 1; i <= m; i++) {
            printf("%d ", chosen[i]);
        }
        printf("\n");
        return;
    }
    
    for (int i = start; i <= n; i++) {
        chosen[u] = i;
        dfs(u + 1, i + 1);
        chosen[u] = 0;
    }
};


/* 4-递归实现组合型枚举 */
function<void(int, int, int)> dfs = [&](int u, int cnt, int state) -> void {
    if (cnt + n - u < m) {   // 剪枝
        return;
    }
    if (cnt == m) {
        for (int i = 0; i < n; i++) {
            if (state >> i & 1) {
                printf("%d ", i + 1);
            }
        }
        printf("\n");
        return;
    }
    if (u == n) {
        return;
    }
    dfs(u + 1, cnt + 1, state | 1 << u);
    dfs(u + 1, cnt, state);
};