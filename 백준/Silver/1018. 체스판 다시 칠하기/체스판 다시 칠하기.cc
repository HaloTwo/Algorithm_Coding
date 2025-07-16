#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	vector<vector<char>> vec;

	cin >> N >> M;

	vec.resize(N, vector<char>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> vec[i][j];
		}
	}

	int answer = 64; // 최대 8x8 다 바꾸는 경우

	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			int w_count = 0; // W로 시작한다고 가정
			int b_count = 0; // B로 시작한다고 가정

			for (int x = 0; x < 8; x++)
			{
				for (int y = 0; y < 8; y++)
				{
					char current = vec[i + x][j + y];

					// 짝수 칸
					if ((x + y) % 2 == 0)
					{
						if (current != 'W') w_count++;
						if (current != 'B') b_count++;
					}
					// 홀수 칸
					else
					{
						if (current != 'B') w_count++;
						if (current != 'W') b_count++;
					}
				}
			}

			int curr_min = min(w_count, b_count);
			answer = min(answer, curr_min);
		}
	}

	cout << answer;

	return 0;
}
