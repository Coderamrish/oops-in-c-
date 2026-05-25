/*
Leetcode 1871 - jump game 7
You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:

i + minJump <= j <= min(i + maxJump, s.length - 1), and
s[j] == '0'.
Return true if you can reach index s.length - 1 in s, or false otherwise.

 

Example 1:

Input: s = "011010", minJump = 2, maxJump = 3
Output: true
Explanation:
In the first step, move from index 0 to index 3. 
In the second step, move from index 3 to index 5.
Example 2:

Input: s = "01101110", minJump = 2, maxJump = 3
Output: false
 

Constraints:

2 <= s.length <= 105
s[i] is either '0' or '1'.
s[0] == '0'
1 <= minJump <= maxJump < s.length

Brute force method is to use the recursion to check if can i solve it using the brute force method where if(index[0] == 0) return 0 if this condition met then move with the following steps where traverse it to the index i to j if this conditoni + minJump <= j <= min(i + maxJump, s.length - 1), and
s[j] == '0'. is met then true if reach the index then s.length - 1 return false 
TC: O(2 n ) SC : O(n)

optimal using the dp method - tc : O(n) SC :O(n)

*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool solve(int index, string& s, int minJump, int maxJump) {
    int n = s.length();
    if(index == n - 1) return true;
    for (int j = index + minJump; j <= min(index + maxJump, n - 1); j++) {
        if(s[j] == '0') {
            if(solve(j, s, minJump, maxJump)) return true;
        }
    }
    return false;
}
bool canReach(string s, int minJump, int maxJump) {
if(s[0] != '0') return false;
    return solve(0, s, minJump, maxJump);
}
int main() {
    string s ;
    cin >> s;
    int minJump, maxJump;
    cin >> minJump >> maxJump;
    if(canReach(s, minJump, maxJump)) {
    cout << "true";
}
else {
    cout << "false";
}
    return 0;
}

// 2nd approach
#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool canReach(string s, int minJump, int maxJump) {
    int n = s.length();
    int cnt = 0;
    vector<bool> dp(s.length());
    dp[0] = true;
    for (int i = minJump; i < n; i++) {
        cnt += dp[i - minJump];
        if (i - maxJump > 0) {
            cnt -= dp[i - maxJump - 1];
        }
        dp[i] = cnt > 0 && s[i] == '0';
    }
return dp.back();
}
int main() {
string s;
 int minJump, maxJump;
 cin >> s;
 cin >> minJump >> maxJump;
 if(canReach(s, minJump, maxJump)) {
    cout << "true";
 } else {
    cout << "false";
 }
 return 0;
}