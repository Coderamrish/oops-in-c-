/*
Given two integers, start and end, along with an array of integers arr[]. In one operation, you can multiply the current value by any element from arr[], and then take the result modulo 1000 to obtain a new value.

Find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

Examples :

Input: arr[] = [2, 5, 7], start = 3, end = 30
Output: 2
Explanation:
Step 1: 3*2 = 6 % 1000 = 6 
Step 2: 6*5 = 30 % 1000 = 30
Input: arr[] = [3, 4, 65], start = 7, end = 175
Output: 4
Explanation:
Step 1: 7 * 3 = 21 % 1000 = 21  
Step 2: 21 * 3 = 63 % 1000 = 63  
Step 3: 63 * 65 = 4095 % 1000 = 95  
Step 4: 95 * 65 = 6175 % 1000 = 175 
Input: arr[] = [2, 4], start = 3, end = 5
Output: -1
Explanation: Starting from 3 and multiplying by 2 or 4 always produces even numbers after the first step. Since 5 is odd, it can never be reached.
Constraints:
1  ≤ arr.size()  ≤ 103
1  ≤ arr[i]  ≤ 103
0  ≤ start, end  ≤ 103
GFG - POTD MEDIUM - 19th may, 2026
TC:O(n * m)
SC:O(n
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int minSteps(vector<int> &arr, int start, int end)
{
    int mod = 1000;
    vector<int> dist(mod, -1);
    queue<int> q;
    start = start % mod;
    end = end % mod;
    q.push(start);
    dist[start] = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (curr == end)
        {
            return dist[curr];
        }
        for (int i = 0; i < arr.size(); i++)
        {
            int next = (curr * arr[i]) % mod;
            if (dist[next] == -1)
            {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}
int main()
{
    int start = 7;
    int end = 66175;
    vector<int> arr = {3, 4, 65};
    cout << minSteps(arr, start, end) << endl;
    return 0;
}