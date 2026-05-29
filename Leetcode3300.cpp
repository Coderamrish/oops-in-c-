/*
You are given an integer array nums.

You replace each element in nums with the sum of its digits.

Return the minimum element in nums after all replacements.

 

Example 1:

Input: nums = [10,12,13,14]

Output: 1

Explanation:

nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.

Example 2:

Input: nums = [1,2,3,4]

Output: 1

Explanation:

nums becomes [1, 2, 3, 4] after all replacements, with minimum element 1.

Example 3:

Input: nums = [999,19,199]

Output: 10

Explanation:

nums becomes [27, 10, 19] after all replacements, with minimum element 10.

 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 104
3300. Minimum Element After Replacement With Digit Sum- Easy potd - 414
Approach

For every number:

Find digit sum.
Keep track of the minimum digit sum.
tc : O(n) SC :O(1)
*/
#include<iostream>
#include<vector>
#include<climits>
#include<sstream>
using namespace std;
int digitSum(int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int minElement(vector<int>& nums) {
    int ans = INT_MAX;
    for(int num : nums) {
        ans = min(ans, digitSum(num));
    }
    return ans;
}
int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<int> nums;
    int num;
    char comma;
    while(ss >> num) {
        nums.push_back(num);
        ss >> comma;
    }
    cout << minElement(nums);
    return 0;
}