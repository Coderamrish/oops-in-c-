/*
You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.
Return the number of special letters in word.
Example 1:
Input: word = "aaAbcBC"
Output: 3
Explanation:
The special characters in word are 'a', 'b', and 'c'.
Example 2:
Input: word = "abc"
Output: 0
Explanation:
No character in word appears in uppercase.
Example 3:
Input: word = "abBCab"
Output: 1
Explanation:
The only special character in word is 'b'.
Constraints:
1 <= word.length <= 50
word consists of only lowercase and uppercase English letters.

LEETCODE - 3120 , 26th may 2026, potd - 411, Easy
approach using the string cnt : TC : O(n) SC:O(1)
*/
#include <iostream>
#include<vector>
#include <string>
using namespace std;
int cntSpecialchar(string word) {
    vector<bool> lower(26, false), upper(26, false);
    for (char ch : word) {
        if (ch >= 'a' && ch <= 'z') {
            lower[ch - 'a'] = true;
        } else {
            upper[ch - 'A'] = true;
        }
    }
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (lower[i] && upper[i]) {
            count++;
        }
    }
    return count;
}
int main() {
    string word;
    cin >> word;
    cout << cntSpecialchar(word) << endl;
    return 0;
}