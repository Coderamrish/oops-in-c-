/*
Given an integer array arr[] and an integer target, determine whether there exists a pair of elements in the array whose product is equal to target.

Return true if such a pair exists; otherwise, return false.

Examples:

Input: arr[] = [10, 20, 9, 40], target = 400
Output: true
Explanation: As 10 * 40 = 400, the answer is true.
Input: arr[] = [-10, 20, 9, -40], target = 30
Output: false
Explanation: No pair exists with product 30.
Input: arr[] = [-10, 0, 9, -40], target = 0
Output: true
Explanation: As -10 * 0 = 0, the answer is true.
Constraints:
2 ≤ arr.size ≤ 105
-108 ≤ arr[i] ≤ 108
-1018 ≤ target ≤ 1018

Brute force - By Generating all Possible Pairs - O(n^2) Time and O(1) Space
Better - Using Sorting and Two Pointer Technique - O(n log n) Time and O(1) Space
Optimal - Using Hashing - O(n) Time and O(n) Space
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isProduct(vector<int>& arr, long long target) {
    int n = arr.size();
    for(int i = 0; i < n - 1; i++) {
for (int j = i + 1; j <n; j++) {
    if (1LL * arr[i] * arr[j] == target) {
        return true;
    }
}
    }
    return false;
}
int main() {
    vector<int> arr = {10, 20, 9, 40};
    long long target = 400;
    if (isProduct(arr, target))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}

// 2nd approach

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isProduct(vector<int> &arr, long long target)
{
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;
    while (left < right)
    {
        long long currProd = 1LL * arr[left] * arr[right];
        if (currProd == target)
            return true;
        if (currProd > target)
            right--;
        else
            left++;
    }
    return false;
}
int main()
{
    vector<int> arr = {10, 20, 9, 40};
    long long target = 400;
    if (isProduct(arr, target))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}

// 3rd approach

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
    bool isProduct(vector<int>& arr, long long target) {
        unordered_set<long long> st;
        for (long long num : arr) {
            if (num == 0) {
                if (target == 0) return true;
                continue;
            }
            if (target % num == 0) {
                long long secondNum = target / num;
                if (st.find(secondNum) != st.end()) {
                    return true;
                }
            }
            st.insert(num);
        }
        return false;
    }
    int main()
{
    vector<int> arr = {10, 20, 9, 40};
    long long target = 400;
    if (isProduct(arr, target))
        cout << "true";
    else
        cout << "false";
    return 0;
}
