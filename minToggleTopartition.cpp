/*
Given an array arr[] containing only 0 and 1. Find the minimum toggles (switch from 0 to 1 or vice-versa) required such the array become partitioned, i.e., it has first 0s then 1s.

Examples:

Input: arr = [1, 0, 1, 1, 0]
Output: 2
Explaination: The changed array will be [0, 0, 1, 1, 1]. So the number of toggles here required is 2.
Input: arr = [0, 1, 0, 0, 1, 1, 1]
Output: 1
Explaination: The changed array will be [0, 0, 0, 0, 1, 1, 1]. Required toggles are 1.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 1

GFG - POTD - 410 , 26th may, 2026
1st approach using Prefix sum cnt : TC: O(n), SC:O(n)
2nd Approach using two pointer : TC : O(n) , SC:O(n)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int partitionArray(vector<int>& arr) {
    int ones = 0;
    int flips = 0;
    for (int x : arr) {
        if (x == 1) {
            ones++;
        } else {
            flips = min(flips + 1, ones);
        }
    }
    return flips;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << partitionArray(arr) << endl;
    return 0;
}