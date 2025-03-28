#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

// **🔹 Memoization Approach (Top-Down DP)**
int f(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
    if (i < 0 || j < 0 || mat[i][j] == -1) return 0; // Out of bounds or obstacle
    if (i == 0 && j == 0) return 1; // Base case: reached start
    
    if (dp[i][j] != -1) return dp[i][j];

    int up = f(i - 1, j, mat, dp);
    int left = f(i, j - 1, mat, dp);

    return dp[i][j] = (up + left) % mod;
}

int uniquePathsMemo(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1, mat, dp);
}

// **🔹 Tabulation Approach (Bottom-Up DP)**
int uniquePathsTab(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == -1) dp[i][j] = 0; // Obstacle
            else if (i == 0 && j == 0) dp[i][j] = 1; // Start point
            else {
                int up = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;
                dp[i][j] = (up + left) % mod;
            }
        }
    }
    return dp[m - 1][n - 1];
}

// **🔹 Space Optimized Approach**
int uniquePathsSpaceOptimized(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<int> prev(n, 0);

    for (int i = 0; i < m; ++i) {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == -1) curr[j] = 0; // Obstacle
            else if (i == 0 && j == 0) curr[j] = 1; // Start point
            else {
                int up = (i > 0) ? prev[j] : 0;
                int left = (j > 0) ? curr[j - 1] : 0;
                curr[j] = (up + left) % mod;
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

    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Enter the grid (-1 for obstacle, 0 for open cell):" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }

    cout << "\nMemoization Approach: " << uniquePathsMemo(mat) << endl;
    cout << "Tabulation Approach: " << uniquePathsTab(mat) << endl;
    cout << "Space Optimized Approach: " << uniquePathsSpaceOptimized(mat) << endl;

    return 0;
}


