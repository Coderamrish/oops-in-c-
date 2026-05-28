/*
You are given two arrays of strings wordsContainer and wordsQuery.

For each wordsQuery[i], you need to find a string from wordsContainer that has the longest common suffix with wordsQuery[i]. If there are two or more strings in wordsContainer that share the longest common suffix, find the string that is the smallest in length. If there are two or more such strings that have the same smallest length, find the one that occurred earlier in wordsContainer.

Return an array of integers ans, where ans[i] is the index of the string in wordsContainer that has the longest common suffix with wordsQuery[i].

 

Example 1:

Input: wordsContainer = ["abcd","bcd","xbcd"], wordsQuery = ["cd","bcd","xyz"]

Output: [1,1,1]

Explanation:

Let's look at each wordsQuery[i] separately:

For wordsQuery[0] = "cd", strings from wordsContainer that share the longest common suffix "cd" are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
For wordsQuery[1] = "bcd", strings from wordsContainer that share the longest common suffix "bcd" are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
For wordsQuery[2] = "xyz", there is no string from wordsContainer that shares a common suffix. Hence the longest common suffix is "", that is shared with strings at index 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
Example 2:

Input: wordsContainer = ["abcdefgh","poiuygh","ghghgh"], wordsQuery = ["gh","acbfgh","acbfegh"]

Output: [2,0,2]

Explanation:

Let's look at each wordsQuery[i] separately:

For wordsQuery[0] = "gh", strings from wordsContainer that share the longest common suffix "gh" are at indices 0, 1, and 2. Among these, the answer is the string at index 2 because it has the shortest length of 6.
For wordsQuery[1] = "acbfgh", only the string at index 0 shares the longest common suffix "fgh". Hence it is the answer, even though the string at index 2 is shorter.
For wordsQuery[2] = "acbfegh", strings from wordsContainer that share the longest common suffix "gh" are at indices 0, 1, and 2. Among these, the answer is the string at index 2 because it has the shortest length of 6.
 

Constraints:

1 <= wordsContainer.length, wordsQuery.length <= 104
1 <= wordsContainer[i].length <= 5 * 103
1 <= wordsQuery[i].length <= 5 * 103
wordsContainer[i] consists only of lowercase English letters.
wordsQuery[i] consists only of lowercase English letters.
Sum of wordsContainer[i].length is at most 5 * 105.
Sum of wordsQuery[i].length is at most 5 * 105.

Leetcode 3093 Hard - potd 413
*/
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;
struct TrieNode {
    int children[26];
    int bestIndex;
    TrieNode() {
        fill(begin(children), end(children), -1);
        bestIndex = -1;
    }
};
class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size();
        int minLen = INT_MAX;
        int globalBestIdx = -1;
        for (int i = 0; i < n; ++i) {
            if (wordsContainer[i].length() < minLen) {
                minLen = wordsContainer[i].length();
                globalBestIdx = i;
            }
        }
        vector<TrieNode> trie;
        trie.reserve(500005); 
        trie.emplace_back();
        trie[0].bestIndex = globalBestIdx;
        for (int i = 0; i < n; ++i) {
            int curr = 0; 
            int len = wordsContainer[i].length();
            for (int j = len - 1; j >= 0; --j) {
                int charIdx = wordsContainer[i][j] - 'a';
                if (trie[curr].children[charIdx] == -1) {
                    trie[curr].children[charIdx] = trie.size();
                    trie.emplace_back();
                    trie.back().bestIndex = i;
                } else {
                    int childIdx = trie[curr].children[charIdx];
                    int existingBestIdx = trie[childIdx].bestIndex;
                    if (len < wordsContainer[existingBestIdx].length()) {
                        trie[childIdx].bestIndex = i;
                    }
                }
                curr = trie[curr].children[charIdx];
            }
        }
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        for (const string& q : wordsQuery) {
            int curr = 0;
            for (int j = q.length() - 1; j >= 0; --j) {
                int charIdx = q[j] - 'a';
                if (trie[curr].children[charIdx] == -1) {
                    break; 
                }
                curr = trie[curr].children[charIdx];
            }
            ans.push_back(trie[curr].bestIndex);
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<string> wordsContainer1 = {"abcd","bcd","xbcd"};
    vector<string> wordsQuery1 = {"cd","bcd","xyz"};
    vector<int> result1 = sol.stringIndices(wordsContainer1, wordsQuery1);
    // Expected output: [1, 1, 1]

    vector<string> wordsContainer2 = {"abcdefgh","poiuygh","ghghgh"};
    vector<string> wordsQuery2 = {"gh","acbfgh","acbfegh"};
    vector<int> result2 = sol.stringIndices(wordsContainer2, wordsQuery2);
    // Expected output: [2, 0, 2]

    return 0;
}