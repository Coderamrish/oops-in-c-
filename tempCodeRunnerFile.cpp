#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int minElement(vector<int>& nums) {
    int ans = INT_MAX;
    for (int num: nums) {
        ans = min(ans, digitSum(num));
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << minElement(nums) << endl;
}