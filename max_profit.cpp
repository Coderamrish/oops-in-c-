/*
Given two machines, Machine A and Machine B, and a set of n tasks. The profit earned for performing each task is given in two arrays a[] and b[] such that if Machine A performs the i-th task, the profit is a[i], and if Machine B performs it, the profit is b[i].

Machine A can process at most x tasks, and Machine B can process at most y tasks. It is guaranteed that x + y ≥ n, so all tasks can be assigned. Return the maximum possible profit after assigning each task to either Machine A or Machine B.

Examples:

Input: x = 3, y = 3, a[] = [1, 2, 3, 4, 5], b[] = [5, 4, 3, 2, 1]
Output: 21
Explanation: Machine A performs tasks with indices [2, 3, 4], and Machine B performs the rest [0, 1], giving profits (3 + 4 + 5) + (5 + 4) = 21.
Input: x = 4, y = 4, a[] = [1, 4, 3, 2, 7, 5, 9, 6], b[] = [1, 2, 3, 6, 5, 4, 9, 8]
Output: 43
Explanation: Machine A performs tasks with indices [1, 4, 5, 7], and Machine B performs the rest [0, 2, 3, 6], giving profits (4 + 7 + 5 + 6) + (1 + 3 + 6 + 9) = 41.
Input: x = 3, y = 4, a[] = [8, 7, 15, 19, 16, 16, 18], b[] = [1, 7, 15, 11, 12, 31, 9]
Output: 110
Explanation: Machine A performs tasks with indices [0, 3, 6], and Machine B performs the rest [1, 2, 4, 5], giving profits (8 + 19 + 18) + (7 + 15 + 12 + 31) = 110.
Constraints:
1 ≤ a.size() == b.size() ≤ 105
1 ≤ x, y ≤ 105
1 ≤ a[i], b[i] ≤ 104

TCS, AMAZON.
MAX PROFIT FROM TWO MACHINES.
GFG POTD - 394, medium level 

approach - Greedy
TC- O(n logn) SC- O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(int x, int y, vector<int>&a, vector<int>&b) {
int n = a.size();
vector<vector<int>> diff(n, vector<int>(2));
for (int i = 0; i < n; i++) {
    diff[i] = {abs(a[i] - b[i]), i};
}
sort(diff.begin(), diff.end(), greater<vector<int>>());
int ans = 0;
int i = 0;
while (i < n && x > 0 && y > 0) {
    int index = diff[i][1];
    if (a[index] > b[index]) {
        ans += a[index];
        x--;
    } else {
        ans += b[index];
        y--;
    }
    i++;
}
while ( i < n && x > 0) {
    int index = diff[i][1];
    ans += a[index];
    x--;
    i++;
}
while (i < n && y > 0)
 {
    int index = diff[i][1];
    ans += b[index];
    y--;
    i++;
 }
 return ans;
}
int main() {
    vector<int>a = {1,2,3,4,5};
    vector<int>b = {5,4,3,2,1};
    int x = 3, y = 3;
    cout << maxProfit(x,y,a,b);
    return 0;
}