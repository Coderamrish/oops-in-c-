/*
Not a subset sum - GFG POTD - 400 Medium, date - 16th may, 2026
Given a array arr[] of positive integers, find the smallest positive integer such that it cannot be represented as the sum of elements of any subset of the given array set.

Examples:

Input: arr[] = [3, 1, 2]
Output: 7
Explanation: 7 is the smallest positive number for which no subset is there with sum 7.
Input: arr[] = [3, 10, 9, 6, 20, 28]
Output: 1
Explanation: 1 is the smallest positive number for which no subset is there with sum 1.
Constraints
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 103

1st approach using DP , TC : O(n * sum) , SC :O(sum)
2nd approach using sorting and greedy , TC: O(n log n) , SC : O(1)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int findSmallest(vector<int>& arr) {
    int n = arr.size();
    int sum = 0;
    for (auto val : arr) sum += val;
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = sum - arr[i]; j >= 0; j--) {
            if (dp[j]) dp[j + arr[i]] = true;
        }
    }
    for (int i = 1; i <= sum; i++) {
        if (!dp[i]) return i;
    }
    return sum + 1;
}
int main() {
    vector<int> arr= {3,1,2};
    cout << findSmallest(arr) << endl;
return 0;
}

// 2nd appraoch using sorting
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findSmallest(vector<int> & arr) {
    int n = arr.size();
    int res = 1;
    sort (arr.begin(), arr.end());
    for (int i = 0; i < n && arr[i] <= res; i++) {
        res += arr[i];
    }
    return res;
}
int main() {
    vector<int> arr= {3,1,2};
    cout << findSmallest(arr) << endl;
    return 0;
}