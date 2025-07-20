#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, R;
    cin >> N >> M >> R;

    vector<vector<int>> map(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    int layer = min(N, M) / 2;

    for (int i = 0; i < layer; i++)
    {
        vector<int> line;

        // 상단 가로줄
        for (int j = i; j < M - i - 1; j++)
            line.push_back(map[i][j]);

        // 오른쪽 세로줄
        for (int j = i; j < N - i - 1; j++)
            line.push_back(map[j][M - i - 1]);

        // 하단 가로줄
        for (int j = M - i - 1; j > i; j--) // ✅ M-i-2까지
            line.push_back(map[N - i - 1][j]);

        // 왼쪽 세로줄
        for (int j = N - i - 1; j > i; j--) // ✅ N-i-2까지
            line.push_back(map[j][i]);

        int rotateSize = R % line.size();
        rotate(line.begin(), line.begin() + rotateSize, line.end());

        int idx = 0;

        // 상단 가로줄
        for (int j = i; j < M - i - 1; j++)
            map[i][j] = line[idx++];

        // 오른쪽 세로줄
        for (int j = i; j < N - i - 1; j++)
            map[j][M - i - 1] = line[idx++];

        // 하단 가로줄
        for (int j = M - i - 1; j > i; j--)
            map[N - i - 1][j] = line[idx++];

        // 왼쪽 세로줄
        for (int j = N - i - 1; j > i; j--)
            map[j][i] = line[idx++];
    }

    // 출력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
