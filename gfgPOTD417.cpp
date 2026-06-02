/*
Given an array of integers and a number k, the task is the find maximum pair sum with the following conditions on the pairs.

Pair difference should be less than k.
Pairs should be disjoint. For example if (x, y) is a result pair, then neither x nor y should appear in any other result pair.
Sum of p pairs means sum of 2p elements in the result.
If no valid pairs can be formed, return 0.

Examples:

Input: arr[] = [3, 5, 10, 15, 17, 12, 9], K = 4
Output: 62
Explanation :
The valid disjoint pairs with difference less than K are:
(3, 5), (10, 12), (15, 17)
The maximum sum obtained from these pairs is:
3 + 5 + 10 + 12 + 15 + 17 = 62
An alternative pairing could be:
(3, 5), (9, 12), (15, 17)
However, this combination results in a smaller total sum, so it is not optimal.
Input: arr[] = [5, 15, 10, 300], k = 12
Output: 25
Explanation: 
The valid disjoint pairs with difference less than k are:
(5, 10)
The maximum sum obtained from these pairs is:
5 + 10 = 15
An alternative pairing could be:
(10, 15)
However, this combination results in a larger total sum:
10 + 15 = 25. So this pairing is optimal.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ k ≤ 105
1 ≤ arr[i] ≤ 104

Approach 1 using Recursion tc : O(2^n) SC:O(n)
Approach 2 using DP TC:O(n) SC:(n)
Approach 3 using Greedy TC:O(n log n) SC:O(1)

 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int sumDiff(vector<int>& arr, int k) {
    int maxSum = 0;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = n - 1; i > 0; --i) {
        if(arr[i] - arr[i - 1] < k) {
            maxSum += arr[i];
            maxSum += arr[i - 1];
            --i;
        }
    }
    return maxSum;
}
int main()
{
    vector<int> arr = { 3, 5, 10, 15, 17, 12, 9 };
    int k = 4;

    cout << sumDiff(arr, k);
    return 0;
}