/*
There are n rooms in a straight line in Geekland State University's hostel. You are given a binary string s of length n, where s[i] = '1' means there is a WiFi router in the i-th room, and s[i] = '0' means there is no WiFi in that room.

Each WiFi router has a range of x, meaning it can cover up to x rooms to its left and x rooms to its right.

Given x and s, determine whether all rooms are covered by at least one WiFi router. Return true if all rooms are covered; otherwise, return false.

Examples: 

Input: x = 0, s = "010"
Output: false
Explanation: Since the range is 0, so Wifi is only accessible in second room while 1st & 3rd room have no wifi. Therefore answer is false for this test case.
Input: x = 1, s = "10010"
Output: true
Explanation: 
Index 0: WiFi is available.
Index 1: Since the range of the 0th index is 1, WiFi is available here.
Index 2: Since the range of the 3rd index is 1, WiFi is also available here.
Index 3: WiFi is available.
Index 4: The range of the 3rd index covers this position.
So, all the rooms have WiFi. Therefore, the answer is true for this test case. 
Constraints:
1 ≤ n ≤ 105
0 ≤ x ≤ 105

GFG- potd 411 , 27th may 2026 easy 
Approach 1 - Brute force using checking each and every room and checking if wifi is covered or not TC : O(N^2) SC:  O(1)
Approach 2 - using prefix and suffix array TC : O(n) SC : O(N)
Appraoch 3 - using greeddy two pointer tc : O(n) SC :O(1)
*/
#include <iostream>
#include <string>
using namespace std;
bool wifiRange(string s, int x)
{
    int n = s.length();
    for (int i = 0; i < n; i++) {
        bool covered = false;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1' && abs(i - j) <= x) {
                covered = true;
                break;
            }
        }
        if (!covered) return false;
    }
    return true;
}
int main()
{
    cout << (wifiRange("10010", 1) ? "true" : "false") << endl;
    return 0;
}
// 2nd approach
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool wifiRange(string s, int x)
{
    int n = s.length();
    vector<int> left(n, -1e9), right(n, 1e9);
    int last = -1e9;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            last = i;
        }
        left[i] = last;
    }
    last = 1e9;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            last = i;
        }
        right[i] = last;
    }
    for (int i = 0; i < n; i++) {
        if (abs(i - left[i]) > x && 
            abs(i - right[i]) > x) {
            return false;
        }
    }
    return true;
}
int main()
{
    cout << (wifiRange("10010", 1) ? "true" : "false") << endl;
    return 0;
}

// 3rd approach
#include <iostream>
#include <string>
using namespace std;
bool wifiRange(string s, int x) {
    int n = s.length();
    int maxReach = -1; 
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (maxReach < i - x - 1) {
                return false;
            }
            maxReach = max(maxReach, i + x);
        }
    }
    return maxReach >= n - 1;
}
int main() {
    cout << (wifiRange("10010", 1) ? "true" : "false") << endl;
    return 0;
}