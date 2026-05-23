/*
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].
Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
 
Leetcode -1752 check if a array is sorted and rotated
POTD - 408 , 23rd may 2026
Brute force appraoch : - solve it usng the iterating over the array and check if the array is sorted and rotated if yes retur true else false , TC: O(n^2) SC : O(1)
Optima Appraoch - We can solve it using the iterating over array and check if array is rotated and sorted if yes return true else false, TC: O(n) SC :O(1)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isSorted(vector<int>& arr) {
int n = arr.size();
for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1]) {
        return false;
    }
}return true;
}
bool check(vector<int> & nums) {
    int n = nums.size();
for (int r = 0; r < n; r++) {
    if(isSorted(nums)) {
        return true;
    }
int last = nums[n - 1];
for (int i = n - 1; i > 0; i--) {
    nums[i] = nums[i - 1];
}
nums[0] = last;
}
return false;
}
int main() {
    vector<int> nums = {3, 4, 5, 1 , 2};
    cout << boolalpha;
    cout << check(nums) << endl;
    return 0;
}
// 2nd approach
#include <iostream>
#include <vector>
using namespace std;
bool check(vector<int> & nums) {
    int n = nums.size();
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[(i - 1) % n]) {
            cnt++;
        }
    }
    return cnt <= 1;
}
int main() {
    vector<int> nums1 = {3 , 4, 5, 1, 2};
    vector<int> nums2 = {2, 1, 3, 4};
    vector<int> nums3 = {1, 2, 3};
    cout << boolalpha;
    cout << check(nums1) << endl;
    cout << check(nums2) << endl;
    cout << check(nums3) << endl;
    return 0;
}