#include<iostream>
#include<cmath>
#include<vector>
#include<climits>
using namespace std;
bool isSumOfConsecutive(int n) {
    for(int i = 1; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += j;
            if (sum == n && j > i) {
                return true;
            }
            if(sum > 0) {
                break;
            }
        }
    }
    return false;
}
int main() {
    int n; 
    cin >> n;
    if(isSumOfConsecutive(n)) {
        cout << "true";

    } else {
        cout << "false";
    }
    return 0;
}