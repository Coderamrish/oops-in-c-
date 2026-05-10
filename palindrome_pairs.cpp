/*
Given an array arr[] consisting of n strings. Determine whether there exists a pair of indices (i, j) such that i ≠ j and the concatenation arr[i] + arr[j] forms a palindrome.

Return true if such a pair exists; otherwise, return false.

Note: A string is considered a palindrome if it reads the same forward and backward.

Examples:

Input: arr[] = ["geekf", "geeks", "or", "keeg", "abc", "bc"]
Output: true
Explanation: There is a pair "geekf" and "keeg". Their concatenation "geekfkeeg" is a palindrome.
Input: arr[] = ["abc", "xyxcba", "geekst", "or", "bc"]
Output: true
Explanation: There is a pair "abc" and "xyxcba". Their concatenation "abcxyxcba" is a palindrome.
Input: arr[] = ["aa"]
Output: false
Explanation: There is only one string present, so the output is false.
Constraints:
1 ≤ n ≤ 2*104
1 ≤ |arr[i]| ≤ 10

GFG POTD - 395, Hard Level
TC: O(n * k^2) SC: O(n *k)
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<string>

using namespace std;
bool isPalindrome(string &s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) 
        if (s[i] != s[n - i - 1]) 
        return false;
        return true;
    }
    bool PalindromePair(vector<string>& arr) {
        int n = arr.size();
        unordered_map<string, int> str;
        for (int i = 0; i < arr.size(); i++) {
            string word = arr[i];
            reverse(word.begin(), word.end());
            str[word] = i;
        }
        for(int i = 0; i < arr.size(); i++) {
            string left = "";
            for(int j = 0 ; j < arr.size(); j++) {
                left += arr[i][j];
                string right = arr[i].substr(j + 1);
                if(!left.empty() && isPalindrome(left) && str.count(right) && str[right] != i)
                return true;
                if(isPalindrome(right) && str.count(left) && str[left] != i)
                return true;
            }
        }
        return false;
    }
    int main() {
        vector<string> arr = {"geekf", "geeks", "or", "keeg", "abc", "bc"};
    if (PalindromePair(arr))
        cout << "True";
    else
        cout << "False";
    return 0;
    }