/*
Given a number n, check whether every bit in the binary representation of the given number is set or not.

Return true if yes, otherwise false.

Examples :

Input: n = 7
Output: true
Explanation: Binary for 7 is 111 all the bits are set so the output is true.
Input: n = 8
Output: false
Explanation: Binary for 8 is 1000 all the bits are not set so the output is false.
Input: n = 0
Output: false
Explanation: All the bits are 0 so the output is false.
Constraints:
0 ≤ n ≤ 105

GFG potd - 405 basic
TC :O(1) sc : O(1)
*/
#include <iostream>
using namespace std;
bool isBitSet(int n)
{
    if (n <= 0)
        return false;
    int x = n + 1;
    return (x & (x - 1)) == 0;
}
int main()
{
    int n = 7;
    cout << boolalpha << isBitSet(n);
    return 0;
}