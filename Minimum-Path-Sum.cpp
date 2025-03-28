#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// **🔹 Memoization Approach (Top-Down DP)**
int f(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if (row < 0 || col < 0) return INF; // Out of bounds
    if (row == 0 && col == 0) return grid[row][col]; // Base case: reached start
    
    if (dp[row][col] != -1) return dp[row][col];

    int up = grid[row][col] + f(row - 1, col, grid, dp);
    int left = grid[row][col] + f(row, col - 1, grid, dp);

    return dp[row][col] = min(up, left);
}

int minSumPathMemo(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1, grid, dp);
}

// **🔹 Tabulation Approach (Bottom-Up DP)**
int minSumPathTab(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) dp[i][j] = grid[i][j]; // Start point
            else {
                int up = (i > 0) ? dp[i - 1][j] : INF;
                int left = (j > 0) ? dp[i][j - 1] : INF;
                dp[i][j] = grid[i][j] + min(up, left);
            }
        }
    }
    return dp[m - 1][n - 1];
}

// **🔹 Space-Optimized Approach**
int minSumPathSpaceOptimized(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> prev(n, INF);

    for (int i = 0; i < m; ++i) {
        vector<int> curr(n, INF);
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) curr[j] = grid[i][j]; // Start point
            else {
                int up = (i > 0) ? prev[j] : INF;
                int left = (j > 0) ? curr[j - 1] : INF;
                curr[j] = grid[i][j] + min(up, left);
            }
        }
        prev = curr;
    }
    return prev[n - 1];
}

// **🔹 Main function to take user input**
int main() {
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    if (m <= 0 || n <= 0) {
        cout << "Invalid grid size." << endl;
        return 0;
    }

    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter the grid values row by row:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    cout << "\nMemoization Approach: " << minSumPathMemo(grid) << endl;
    cout << "Tabulation Approach: " << minSumPathTab(grid) << endl;
    cout << "Space Optimized Approach: " << minSumPathSpaceOptimized(grid) << endl;

    return 0;
}
