#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int uniquePathsWithObstacles(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<int> prev(n, 0);
    
    for(int i = 0; i < m; ++i){
        vector<int> temp(n, 0);
        for(int j = 0; j < n; ++j){
            if(mat[i][j] == -1){
                temp[j] = 0;
            }
            else if(i == 0 && j == 0){
                temp[j] = 1;
            }
            else{
                int up = 0, left = 0;
                if(i > 0){
                    up = prev[j];
                }
                if(j > 0){
                    left = temp[j-1];
                }
                temp[j] = (up + left) % mod;
            }
        }
        prev = temp;
    }
    return prev[n-1];
}

int main() {
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    if(m <= 0 || n <= 0){
        cout << "Invalid grid size." << endl;
        return 0;
    }

    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Enter the grid (-1 for obstacle, 0 for open cell):" << endl;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> mat[i][j];
        }
    }

    cout << "Total unique paths: " << uniquePathsWithObstacles(mat) << endl;
    return 0;
}

