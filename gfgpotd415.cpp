/*
Given a number n, find whether n can be expressed as sum of two or more consecutive positive numbers.

Examples :

Input: n = 10
Output: true
Explanation: 10 can be expressesd as 1 + 2 + 3 + 4.
Input: n = 8
Output: false
Explanation: 8 can't be expressesd sum of two or more consecutive numbers.
Input: n = 24
Output: true
Explanation: 24 can be expressesd as 7 + 8 + 9.
Constraints:
1 ≤ n ≤ 109
GFG POTD - 415 - Easy 31 may 2026
Approach 1 - using Brute force Approach Checking all possible consecutive sum TC : O(n^2) SC : O(1)
Approach 2 - using Mathematical function TC : O(1) SC:O(1)
*/
#include<iostream>
#include<cmath>
#include<vector>
#include<climits>
using namespace std;
bool isSumOfConsecutive(int n) {
    for(int i = 1; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += j;
            if (sum == n && j > i) {
                return true;
            }
            if(sum > n) {
                break;
            }
        }
    }
    return false;
}
int main() {
    int n; 
    cin >> n;
    if(isSumOfConsecutive(n)) {
        cout << "true";

    } else {
        cout << "false";
    }
    return 0;
}

// Appraoch - 2
#include <iostream>
using namespace std;
bool isSumOfConsective(int n) {
    if(n == 1) {
        return false;
    }
    if((n & (n - 1)) == 0) {
        return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    if(isSumOfConsecutive(n)) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}