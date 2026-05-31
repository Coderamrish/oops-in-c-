/*
Given an array arr[], find and return the maximum product possible with the subset of elements present in the array.

Note:

The maximum product can be of a single element also.
Since the product can be large, return it modulo 109 + 7.
Examples:

Input: arr[] = [-1, 0, -2, 4, 3]
Output: 24
Explanation: Maximum product will be ( -1 * -2 * 4 * 3 ) = 24
Input: arr[] = [-1, 0]
Output: 0
Explanation: Maximum product will be ( -1 * 0) = 0
Input: arr[] = [5]
Output: 5
Explanation: Maximum product will be 5.
Constraints:
1 ≤ arr.size() ≤ 2 * 104
-10 ≤ arr[i] ≤ 10

Approach 1 - check all possible cases - TC : (2^n) SC:O(1)
Approach 2 - using greedy TC:O(N) SC:O(1)
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int findMaxProduct(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return arr[0];
    long long ans = 1;
    int mod = 1e9 + 7;
    int zeroCount = 0, negCount = 0;
    int maxNeg = INT_MIN, idxMaxNeg = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            zeroCount++;
        } 
        else if (arr[i] < 0) {
            negCount++;
            if (idxMaxNeg == -1 || arr[i] > maxNeg) {
                maxNeg = arr[i];
                idxMaxNeg = i;
            }
        }
    }
    if (zeroCount == n) return 0;
    if (negCount == 1 && zeroCount == n - 1) return 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) continue;
        if (negCount % 2 == 1 && i == idxMaxNeg) continue;
        ans = ((ans * arr[i]) % mod + mod) % mod;
    }
    return ans;
}
int main() {
    vector<int> arr = { -1, -1, -2, 4, 3 };
    cout << findMaxProduct(arr);
    return 0;
}