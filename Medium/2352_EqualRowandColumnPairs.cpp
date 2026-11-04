#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int equalPairs(vector<vector<int>>& grid) {
    int n = grid[0].size();
    map<vector<int>, int> rowmap;
    for (int i = 0; i < n; i++) {
        rowmap[grid[i]]++;
    }

    int ans = 0;
    vector<int> column(n, 0);
    for (int i = 0; i < n; i++) {
        // get each column
        for (int j = 0; j < n; j++) {
            column[j] = grid[j][i];
        }
        // find 
        ans += rowmap[column];
    }
    return ans;
}

int main()
{
    int n;
    // 讀取矩陣的維度 n
    while (cin >> n) {
        vector<vector<int>> grid(n, vector<int>(n));

        // 讀取 n x n 的網格資料
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }

        // 呼叫函式並印出結果
        int ans = equalPairs(grid);
        cout << ans << endl;
    }

    return 0;
}
