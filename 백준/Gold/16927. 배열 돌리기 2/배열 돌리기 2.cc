#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, R;
    cin >> N >> M >> R;

    vector<vector<int>> vec(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> vec[i][j];
        }
    }

    int layer = min(N, M) / 2;
    vector<vector<int>> layerVec(layer);

    // 1. 레이어별로 테두리 뽑기
    for (int i = 0; i < layer; i++)
    {
        // 윗줄
        for (int x = i; x < M - i; x++)
            layerVec[i].push_back(vec[i][x]);

        // 오른쪽
        for (int y = i + 1; y < N - i; y++)
            layerVec[i].push_back(vec[y][M - i - 1]);

        // 아랫줄
        for (int x = M - i - 2; x >= i; x--)
            layerVec[i].push_back(vec[N - i - 1][x]);

        // 왼쪽
        for (int y = N - i - 2; y > i; y--)
            layerVec[i].push_back(vec[y][i]);
    }

    // 2. 회전시키기
    for (int i = 0; i < layer; i++)
    {
        int len = layerVec[i].size();
        int rot = R % len;

        for (int r = 0; r < rot; r++)
        {
            int temp = layerVec[i].front();
            layerVec[i].erase(layerVec[i].begin());
            layerVec[i].push_back(temp);
        }
    }

    // 3. 원래 배열에 다시 넣기
    for (int i = 0; i < layer; i++)
    {
        int idx = 0;

        // 윗줄
        for (int x = i; x < M - i; x++)
            vec[i][x] = layerVec[i][idx++];

        // 오른쪽
        for (int y = i + 1; y < N - i; y++)
            vec[y][M - i - 1] = layerVec[i][idx++];

        // 아랫줄
        for (int x = M - i - 2; x >= i; x--)
            vec[N - i - 1][x] = layerVec[i][idx++];

        // 왼쪽
        for (int y = N - i - 2; y > i; y--)
            vec[y][i] = layerVec[i][idx++];
    }

    // 4. 출력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
