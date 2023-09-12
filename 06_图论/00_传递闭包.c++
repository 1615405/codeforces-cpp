/**
 * 传递闭包(floyd-Warshall算法)
 *     在交际网络中，给定若干个元素和若干对二元关系，且关系具有传递性。
 * “通过传递性推导出尽量多的元素之间的关系”的问题被称为传递闭包。
 *     建立邻接矩阵 graph, 其中 graph[i,j] = 1, 表示 i 与 j 有关系，graph[i,j] = 0 表示
 * i 与 j 没有关系。特别地，graph[i,i] 始终为 1。使用 Floyd 算法可以解决传递闭包问题。
*/


bool graph[310][310];
int n, m;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        graph[i][i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x][y] = graph[y][x] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                graph[i][j] |= graph[i][k] & graph[k][j];
                // graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j])
            }
        }
    }
}