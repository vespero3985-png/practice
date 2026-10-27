#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long dfs(vector<vector<int>>& grid, int r, int c, int m, int n) {
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0)
        return 0;
    long long val = grid[r][c];
    grid[r][c] = 0;
    // four direction
    val += dfs(grid, r - 1, c, m, n); // up
    val += dfs(grid, r + 1, c, m, n); // down
    val += dfs(grid, r, c - 1, m, n); // left
    val += dfs(grid, r, c + 1, m, n); // right

    return val;
}

int countIslands(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;

    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            if (grid[r][c] > 0) {
                long long total = dfs(grid, r, c, m, n);
                if (total % k == 0) ans++;
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, k;
    
    while (cin >> m >> n >> k) {
        vector<vector<int>> grid(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }

        int result = countIslands(grid, k);
        cout << "ANS = " << result << "\n";
    }

    return 0;
}