/*
Given a binary string s consisting of 0s and 1s. Find the maximum difference of the number of 0s and the number of 1s (number of 0s – number of 1s) in a substring of the string.

Note: In the case of all 1s, the answer will be -1.

Examples:

Input : s = "11000010001" 
Output : 6 
Explanatio: From index 2 to index 9, there are 7 0s and 1 1s, so number of 0s - number of 1s is 6. 
Input: s = "111111"
Output: -1
Explanation: s contains 1s only 
Constraints:
1 ≤ s.size() ≤ 105
Approach 1 - using Brute force Traversing each array and checking the cnt of 0s and 1s and calculate 0 - 1 maxDiff if max 1 then return -1 TC:O(n^2) SC:O(1)
Approach 2 - using kadane's algorithm TC:O(n) SC:O(1)
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <climits>
using namespace std;
int maxSubstring(string s) {
    int n = s.size();
    int maxDiff = INT_MIN;
for(int i = 0; i < n; i++) {
    int cnt0 = 0, cnt1 = 0;
    for(int j = i; j < n; j++) {
        if(s[j] == '0') cnt0++;
        else cnt1++;
        int diff = cnt0 - cnt1;
        maxDiff = max(maxDiff,diff);

    }
}
return (maxDiff <=0) ? -1 : maxDiff;
}
int main() {
    string s;
    cin >> s;
    cout << maxSubstring(s) << endl;
    return 0;
}
// 2nd approach using kadane's algorithm
int maxSubstring(string s) {
    int n = s.length();
    int currSum = 0, maxSum = 0;
    for (int i = 0; i < n; i++) {
        currSum += (s[i] == '0') ? 1 : -1;
        if(currSum < 0) currSum = 0;
        maxSum = max(maxSum, currSum);
    }
    return maxSum == 0 ? -1 : maxSum;
}