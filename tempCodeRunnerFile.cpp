#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int partitionArray(vector<int> arr) {
    int n = arr.size();
    int cnt = 0;
    int toggle = 0;
    for (int x : arr)
 {
    if (x == 0) {
        cnt++;
    } else {
        toggle = min(toggle + 1, cnt);
    }
}
    return toggle;
 }
 int main() 
 {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << partitionArray(arr) << endl;
    return 0;
 }