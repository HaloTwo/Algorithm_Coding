#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    // dp[i] = {0의 호출 횟수, 1의 호출 횟수}
    vector<pair<int, int>> dp(41);
    dp[0] = { 1,0 };  // N=0일 때: 0은 1번, 1은 0번
    dp[1] = { 0,1 };  // N=1일 때: 0은 0번, 1은 1번

    // 점화식으로 각 N에 대한 0,1 호출 횟수 계산
    for (int i = 2; i <= 40; i++) 
    {
        dp[i].first = dp[i - 1].first + dp[i - 2].first;   // 0 호출 횟수
        dp[i].second = dp[i - 1].second + dp[i - 2].second; // 1 호출 횟수
    }

    while (T--) 
    {
        int N;
        cin >> N;
        cout << dp[N].first << ' ' << dp[N].second << '\n';
    }

    return 0;
}