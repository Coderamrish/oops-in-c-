/*
Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 
Example 2:

Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true 
Explanation: 
One possible way to reach at index 3 with value 0 is: 
index 0 -> index 4 -> index 1 -> index 3
Example 3:

Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.
 

Constraints:

1 <= arr.length <= 5 * 104
0 <= arr[i] < arr.length
0 <= start < arr.length

TC : O(n)
SC : O(n)
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace  std;
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            if (arr[curr] == 0) {
                return true;
            }
            
            int next1 = curr + arr[curr];
            int next2 = curr - arr[curr];
            
            if (next1 < n && !visited[next1]) {
                visited[next1] = true;
                q.push(next1);
            }
            
            if (next2 >= 0 && !visited[next2]) {
                visited[next2] = true;
                q.push(next2);
            }
        }
        
        return false;
    }
};
int main() {
    Solution sol;
    vector<int> arr1 = {4,2,3,0,3,1,2};
    int start1 = 5;
    cout << boolalpha << sol.canReach(arr1, start1) << endl;

    vector<int> arr2 = {4,2,3,0,3,1,2};
    int start2 = 0;
    cout << boolalpha << sol.canReach(arr2, start2) << endl; 

    vector<int> arr3 = {3,0,2,1,2};
    int start3 = 2;
    cout << boolalpha << sol.canReach(arr3, start3) << endl; 

    return 0;
}