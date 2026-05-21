/*
Given an n × m binary matrix grid[][], find the total count of all cells containing 1 that are unable to move out of the grid through a path of adjacent 1s.

Adjacency means you can only move in four directions: Up, Down, Left, and Right. Diagonal moves are not allowed.
Assume that the space immediately outside the grid is an open path. Any 1 located directly on the outer boundary of the grid (first row, last row, first column, or last column) can immediately step out, and any 1 connected to it can follow and also step out of the grid.
Examples:

Input: grid[][] = [[0, 0, 0, 0],
		[1, 0, 1, 0],
		[0, 1, 1, 0],
		[0, 0, 0, 0]]
Output: 3
Explanation: The highlighted cells represent the land cells.
 
Input: grid[][] = [[1, 1, 0, 0, 0, 1]
		[0, 1, 1, 0, 1, 0],
		[0, 0, 0, 1, 1, 0],
		[0, 0, 0, 1, 1, 0],
		[0, 1, 0, 1, 0, 0],
		[1, 1, 0, 0, 0, 1]]
Output: 6
Explanation: The highlighted cells represent the land cells.
425537429
Constraints:
1 ≤ n, m ≤ 500
0 ≤ grid[i][j] ≤ 1

using BFS TC : O(n *m) SC: O(n * m)

*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int cntOnes(vector<vector<int>>&grid) {
    int n = grid.size();
    if (n == 0 ) return 0;
    int m = grid[0].size();
    queue<pair<int, int>> q;
    int rowDir[4] = {-1, 0, 1, 0};
    int colDir[4] = {0, 1, 0, -1};
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 1) {
            grid[i][0] = 0;
            q.push({i, 0});
        }
        if (grid[i][m - 1] == 1) {
            grid[i][m - 1] = 0;
            q.push({i, m - 1});
        }
    }
    for (int j = 0; j < m; j++) {
        if (grid[0][j] == 1) {
            grid[0][j] = 0;
            q.push({0, j});
        }
        if (grid[n - 1][j] == 1) {
            grid[n - 1][j] = 0;
            q.push({n - 1, j});
        }
    }
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int r = curr.first;
        int c = curr.second;
        for (int k = 0; k < 4; k++) {
            int nr = r + rowDir[k];
            int nc = c + colDir[k];
if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
    grid[nr][nc] = 0;
    q.push({nr, nc});
} 
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt += grid[i][j];
        }
    }
    return cnt;
}
int main()
{
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0, 1}, {0, 1, 1, 0, 1, 0}, {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 1, 1, 0}, {0, 1, 0, 1, 0, 0}, {1, 1, 0, 0, 0, 1},
    };
    int ans = cntOnes(grid);
    cout << ans << "\n";
    return 0;
}