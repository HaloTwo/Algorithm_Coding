#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int N, M;

	cin >> N >> M;

	vector<vector<char>> map(N, vector<char>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	int minCount = 64;

	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			int wStart = 0;
			int bStart = 0;

			for (int x = 0; x < 8; x++)
			{
				for (int y = 0; y < 8; y++)
				{
					char current = map[i + x][j + y];

					//짝수일 경우
					if ((x + y) % 2 == 0)
					{
						
						if (current != 'W')
						{
							wStart++;
						}
						else
						{
							bStart++;
						}


					}
					//홀수일 경우
					else
					{
						if (current != 'W')
						{
							bStart++;
						}
						else
						{
							wStart++;
						}
					}

				}
			}

			minCount = min(minCount, min(bStart, wStart));
		}
	}

	cout << minCount;


	return 0;
}
