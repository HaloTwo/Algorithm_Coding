#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include <tuple>  

using namespace std;


int main()
{
	ios::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);

	const int MAX = 101;

	int M, N, H; // 가로, 세로, 높이

	int box[MAX][MAX][MAX];      //[높이][세로][가로]
	int dist[MAX][MAX][MAX];      //익는데 걸린 날짜 저장

	int dx[6] = { 1, -1, 0, 0, 0, 0 };
	int dy[6] = { 0, 0, 1, -1, 0, 0 };
	int dz[6] = { 0, 0, 0, 0, 1, -1 };

	cin >> M >> N >> H;

	queue<tuple<int, int, int>> q;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> box[i][j][k];

				if (box[i][j][k] == 1)
				{
					q.push({ i, j, k });  
				}
			}
		}
	}

	while (!q.empty())
	{
		int z = get<0>(q.front());
		int y = get<1>(q.front());
		int x = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];

			//조건에 부합하면
			if (nz >= 0 && ny >= 0 && nx >= 0 && nz <H && ny < N && nx < M && box[nz][ny][nx] == 0)
			{
				box[nz][ny][nx] = box[z][y][x] + 1;
				q.push({ nz, ny, nx });
			}
		}
	}

	int time = 0;
	for (int h = 0; h < H; h++)
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				//덜 익은 토마토가 있으면
				if (box[h][y][x] == 0)
				{
					cout << -1 << '\n';
					return 0;
				}
				time = max(time, box[h][y][x]);
			}
		}
	}

	cout << time - 1 << '\n';  // 처음이 1부터 시작했으므로 1 빼줌
	return 0;

	

}