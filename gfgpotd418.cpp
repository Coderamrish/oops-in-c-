/*
Given an array arr[] of n integers and a 2D array queries[][] representing q queries, where each queries[i] consists of three integers: l, r, and x. For each query determine how many times the element x appears in the arr[] from index l to r (both inclusive).

Return a list of integers where the i-th value represents the answer to the i-th query.

Examples: 

Input: arr[] = [1, 2, 1, 3, 1, 2, 3], queries[][] = [[0, 4, 1], [2, 5, 2], [1, 6, 3], [0, 6, 5]]
Output: [3, 1, 2, 0]
Explanation:
query [0, 4, 1] -> Subarray = [1, 2, 1, 3, 1], 1 appears 3 times
query [2, 5, 2] -> Subarray = [1, 3, 1, 2], 2 appears 1 time
query [1, 6, 3] -> Subarray = [2, 1, 3, 1, 2, 3] 3 appears 2 times
query [0, 6, 5] -> Subarray = [1, 2, 1, 3, 1, 2, 3],  5 appears 0 times
Input: arr[] = [11, 21, 51, 101, 11, 51], queries[][] = [[0, 4, 11], [2, 5, 51]]
Output: [2, 2]
Explanation:
query [0, 4, 11] -> Subarray = [11, 21, 51, 101, 11], 11 appears 2 times
query [2, 5, 51] -> Subarray = [51, 101, 11, 51], 51 appears 2 times
Constraints:
1 ≤ arr.size(), queries.size() ≤ 105
1 ≤ arr[i], queries[i][2] ≤ 105
0 ≤ queries[i][0] ≤ queries[i][1] < arr.size()
Approach 1 - using the Range Frequency scan TC: O(n * q) SC:O(1)
Approach 2 - using the Binary Search TC: O(n log n + q log n) SC:O(n)
*/
/*
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;
vector<int> freqInRange(vector<int> &arr, vector<vector<int>> &queries) {
    vector<int>result;
    for(auto& q: queries) {
        int l = q[0], r = q[1], x = q[2];
        int cnt = 0;
        for (int i = l; i <= r; ++i) {
            if(arr[i] == x) {
                cnt++;
            }
        }
        result.push_back(cnt);
    }
    return result;
}
int main() {
    vector<int> arr = {1, 2, 1, 3, 1, 2, 3};
    vector<vector<int>> queries = {
        {0, 4, 1},
        {2, 5, 2},
        {1, 6, 3},
        {0, 6, 5}
    };
    vector<int> ans = freqInRange(arr, queries);
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
*/
// Approach 2 - optimal using Binary Search index map
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
    map<int, vector<int>> indexMap;
    for(int i = 0; i < arr.size(); ++i) {
        indexMap[arr[i]].push_back(i);
    }
    vector<int> result;
    for(auto& q : queries) {
        int l = q[0], r = q[1], x = q[2];
        if(indexMap.find(x) == indexMap.end()) {
            result.push_back(0);
            continue;
        }
        vector<int>& ind = indexMap[x];
        auto left = lower_bound(ind.begin(), ind.end(), l);
        auto right = upper_bound(ind.begin(), ind.end(), r);
        result.push_back(right - left);
    }
    return result;
}
int main() {
    vector<int> arr = {1, 2, 1, 3, 1, 2, 3};
    vector<vector<int>> queries = {
        {0, 4, 1},
        {2, 5, 2},
        {1, 6, 3},
        {0, 6, 5}
    };
    vector<int> ans = freqInRange(arr, queries);
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
