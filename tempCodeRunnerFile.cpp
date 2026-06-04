#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <climits>
using namespace std;
int maxSubstring(string s) {
    int n = s.size();
    int maxDiff = INT_MIN;
for(int i = 0; i < n; i++) {
    int cnt0 = 0, cnt1 = 0;
    for(int j = i; j < n; j++) {
        if(s[j] == '0') cnt0++;
        else cnt1++;
        int diff = cnt0 - cnt1;
        maxDiff = max(maxDiff,diff);

    }
}
return (maxDiff <=0) ? -1 : maxDiff;
}
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << maxSubstring(s) << endl;
    return 0;
}