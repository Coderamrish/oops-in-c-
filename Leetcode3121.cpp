/*
You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.
Return the number of special letters in word.
Example 1:
Input: word = "aaAbcBC"
Output: 3
Explanation:
The special characters are 'a', 'b', and 'c'.
Example 2:
Input: word = "abc"
Output: 0
Explanation:
There are no special characters in word.
Example 3:
Input: word = "AbBCab"
Output: 0
Explanation:
There are no special characters in word.
Constraints:
1 <= word.length <= 2 * 105
word consists of only lowercase and uppercase English letters.
Leetcode - 3121. Count Speacial Characters of a string 2
potd - 412, 27th may ,2026
medium

appraoch - using the position of upper case and lowecase char to determine if the char is special or not TC : O(n) SC:O(1)

*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int isSpecial(string word) {
    int cnt = 0;
    vector<bool> lower(26);
    vector<bool> upper(26);
    for (const char c : word) 
    if(islower(c)) lower[c - 'a'] = !upper[c - 'a'];
    else 
    upper[c - 'A'] = true;
    for(int i = 0; i < 26; i++)
    if(lower[i] && upper[i]) ++cnt;
    return cnt;
}
int main() {
    string s;
    cin >> s;
    cout << isSpecial(s) ;
    return 0;
}