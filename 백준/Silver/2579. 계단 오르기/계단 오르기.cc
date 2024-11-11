#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> stairs(n + 1);
    for (int i = 1; i <= n; i++) 
    {
        cin >> stairs[i];
    }

    int dp[301][3] = { 0, };

    // 초기값 설정
    dp[1][1] = stairs[1];
    dp[2][1] = stairs[2];
    dp[2][2] = stairs[1] + stairs[2];

    for (int i = 3; i <= n; i++) 
    {
        dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + stairs[i];
        dp[i][2] = dp[i - 1][1] + stairs[i];
    }

    cout << max(dp[n][1], dp[n][2]);
    return 0;
}