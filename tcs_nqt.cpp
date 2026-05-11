/*
You are given an array of integers, and your task is to point out the numbers that
occur more than one time. Also, if the inputted value is not an integer, then
directly print "Invalid argument" and break.
The array can have negative values. (You have to take all inputs and write the
main function as well)
Input:
9
9 1 2 3 2 5 5 5 4
Expected output: 2 5 (output in sorted order
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    int n;
    if(!(cin >> n)) {
        cout << "Invalid argument" << endl;
        return 0;
    }
    vector<int> nums(n);
    map<int, int> freq;
    for (int i = 0; i  < n; i++) {
        if(!(cin >> nums[i])) {
            cout << "Invalid argument" << endl;
            return 0;
        }
        freq[nums[i]]++;
    }
    for(auto& it : freq) {
        if(it.second > 1) {
            cout << it.first << " ";
        }
    }
    cout << endl;
    return 0;
}