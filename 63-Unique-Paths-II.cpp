#include <bits/stdc++.h>
using namespace std;

int rec(int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
	if(row >= 0 && col >= 0 && obstacleGrid[row][col] == 1){
		return 0;
	}
	if(row == 0 && col == 0){
		return 1;
	}
	if(row < 0 || col < 0){
		return 0;
	}

	if(dp[row][col] != -1){
		return dp[row][col];
	}

	int up = rec(row-1, col, obstacleGrid, dp);
	int left = rec(row, col-1, obstacleGrid, dp);
	return dp[row][col] = up + left;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	vector<int> prev(n, 0);
	for(int i = 0; i < m; ++i){
		vector<int> temp(n, 0);
		for(int j = 0; j < n; ++j){
			if(obstacleGrid[i][j] == 1){
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
				temp[j] = up + left;
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

	vector<vector<int>> obstacleGrid(m, vector<int>(n));
	cout << "Enter the grid (0 for open cell, 1 for obstacle):" << endl;
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			cin >> obstacleGrid[i][j];
		}
	}

	cout << "Total unique paths: " << uniquePathsWithObstacles(obstacleGrid) << endl;
	return 0;
}