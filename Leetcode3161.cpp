/*
There exists an infinite number line, with its origin at 0 and extending towards the positive x-axis.

You are given a 2D array queries, which contains two types of queries:

For a query of type 1, queries[i] = [1, x]. Build an obstacle at distance x from the origin. It is guaranteed that there is no obstacle at distance x when the query is asked.
For a query of type 2, queries[i] = [2, x, sz]. Check if it is possible to place a block of size sz anywhere in the range [0, x] on the line, such that the block entirely lies in the range [0, x]. A block cannot be placed if it intersects with any obstacle, but it may touch it. Note that you do not actually place the block. Queries are separate.
Return a boolean array results, where results[i] is true if you can place the block specified in the ith query of type 2, and false otherwise.

 

Example 1:

Input: queries = [[1,2],[2,3,3],[2,3,1],[2,2,2]]

Output: [false,true,true]

Explanation:



For query 0, place an obstacle at x = 2. A block of size at most 2 can be placed before x = 3.

Example 2:

Input: queries = [[1,7],[2,7,6],[1,2],[2,7,5],[2,7,6]]

Output: [true,true,false]

Explanation:



Place an obstacle at x = 7 for query 0. A block of size at most 7 can be placed before x = 7.
Place an obstacle at x = 2 for query 2. Now, a block of size at most 5 can be placed before x = 7, and a block of size at most 2 before x = 2.
 

Constraints:

1 <= queries.length <= 15 * 104
2 <= queries[i].length <= 3
1 <= queries[i][0] <= 2
1 <= x, sz <= min(5 * 104, 3 * queries.length)
The input is generated such that for queries of type 1, no obstacle exists at distance x when the query is asked.
The input is generated such that there is at least one query of type 2.

Leetcode 3161- Hard potd 30 may 2026
Time: 
O
(
10
5
+
n
log
⁡
10
5
)
O(10 
5
 +nlog10 
5
 )
Space: 
O
(
10
5
+
q
)
O(10 
5
 +q)
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class FenwickTree {
private:
    vector<int> bit;
    int lowbit(int x) {
        return x & (-x);
    }
public:
    FenwickTree(int n) {
        bit.resize(n + 1, 0);
    }
    void maximize(int idx, int val) {
        while (idx < bit.size()) {
            bit[idx] = max(bit[idx], val);
            idx += lowbit(idx);
        }
    }
    int getMax(int idx) {
        int ans = 0;
        while (idx > 0) {
            ans = max(ans, bit[idx]);
            idx -= lowbit(idx);
        }
        return ans;
    }
};

vector<bool> getResults(vector<vector<int>>& queries) {
    int n = min(50000, (int)queries.size() * 3);
    vector<bool> result;
    FenwickTree tree(n + 1);
    set<int> obstacles;
    obstacles.insert(0);
    obstacles.insert(n);
    for (auto &q : queries) {
        if (q[0] == 1) {
            obstacles.insert(q[1]);
        }
    }
    for (auto it = obstacles.begin(); next(it) != obstacles.end(); ++it) {
        int left = *it;
        int right = *next(it);
        tree.maximize(right, right - left);
    }
    for (int i = (int)queries.size() - 1; i >= 0; i--) {
        int type = queries[i][0];
        int x = queries[i][1];
        if (type == 1) {
            auto it = obstacles.find(x);
            if (next(it) != obstacles.end()) {
                int right = *next(it);
                int left = *prev(it);
                tree.maximize(right, right - left);
            }
            obstacles.erase(it);
        }
        else {
            int sizeNeeded = queries[i][2];
            auto it = obstacles.upper_bound(x);
            int prevObstacle = *prev(it);
            bool possible =
                (tree.getMax(prevObstacle) >= sizeNeeded) ||
                (x - prevObstacle >= sizeNeeded);
            result.push_back(possible);
        }
    }
    reverse(result.begin(), result.end());
    return result;
}
int main() {
    int q;
    cin >> q;
    vector<vector<int>> queries;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            queries.push_back({type, x});
        }
        else {
            int x, sz;
            cin >> x >> sz;
            queries.push_back({type, x, sz});
        }
    }
    vector<bool> ans = getResults(queries);
    for (bool x : ans) {
        if (x)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}