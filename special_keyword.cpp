/*
Given a special keyboard that contains only four keys:

Key 1: Prints a single character 'A' on the screen.
Key 2 (Ctrl + A): Selects all the characters currently present on the screen.
Key 3 (Ctrl + C): Copies the selected characters to a buffer.
Key 4 (Ctrl + V): Pastes the content of the buffer onto the screen, appending it to the existing text.
Initially, the screen is empty and the buffer is also empty.

Determine the maximum number of 'A' characters that can be displayed on the screen after performing exactly n key presses.

Examples :

Input: n = 3
Output: 3
Explanation: With only 3 key presses, the best option is to press Key 1 each time. So, the screen shows "AAA" and the total number of A’s is 3.
Input: n = 7
Output: 9
Explanation: An optimal sequence is: press Key 1 three times to get "AAA", then use Key 2 (select all) and Key 3 (copy), followed by Key 4 twice (paste). This results in "AAAAAAAAA", so the total number of A’s is 9.
Constraints:
1 ≤ n ≤ 70
GFG POTD - 399 
Special Keyword
3 approaches to solve this problem:
1 Brute force using recursion - TC:0(2^n) SC:O(n)
2 DP - TC:O(n^2) SC:O(n)
3 Optimal DP - TC:O(n) SC:O(1)
*/
#include <iostream>
using namespace std;
int optimalKeys(int n) {
    if (n <= 6)
        return n;
    int max = 0;
    for (int b = n - 3; b >= 1; b--) {
        int curr = (n - b - 1) * optimalKeys(b);
        if (curr > max)
            max = curr;
    }
    return max;
}
int main() {
    int n = 7;
    cout << optimalKeys(n) << endl;
}

// 2nd approach
#include <iostream>
using namespace std;
int optimalKeys(int n) {
    if (n <= 6)
        return n;
    int screen[n];
    for (int i = 1; i <= 6; i++)
        screen[i - 1] = i;
    for (int i = 7; i <= n; i++) {
        screen[i - 1] = 0;
        for (int b = i - 3; b >= 1; b--) {
            int curr = (i - b - 1) * screen[b - 1];
            if (curr > screen[i - 1])
                screen[i - 1] = curr;
        }
    }
    return screen[n - 1];
}
int main() {
    int n = 7;
    cout << optimalKeys(n) << endl;
    return 0;
}

// 3rd approach
#include <iostream>
using namespace std;
int optimalKeys(int n) {
    if (n <= 6)
        return n;
    int screen[n];
    for (int i = 1; i <= 6; i++)
        screen[i - 1] = i;
    for (int i = 7; i <= n; i++) {
        screen[i - 1] = max(2 * screen[i - 4], 
                            max(3 * screen[i - 5], 
                                4 * screen[i - 6]));
    }
    return screen[n - 1];
}
int main() {
    int n = 7;
    cout << optimalKeys(n) << endl;
    return 0;
}