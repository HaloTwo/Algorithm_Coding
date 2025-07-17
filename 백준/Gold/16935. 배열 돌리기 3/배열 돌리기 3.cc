#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void change(vector<vector<int>>& vec, int typeNum, int& N, int& M)
{
	switch (typeNum)
	{
	case 1:
	{
		vector<vector<int>> copy = vec;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				vec[i][j] = copy[N - 1 - i][j];
			}
		}
		break;
	}
	case 2:
	{
		vector<vector<int>> copy = vec;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				vec[i][j] = copy[i][M - 1 - j];
			}
		}
		break;
	}
	case 3:
	{
		vector<vector<int>> copy = vec;
		vector<vector<int>> newVec(M, vector<int>(N));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				newVec[j][N - 1 - i] = copy[i][j];
			}
		}
		vec = newVec;
		swap(N, M);
		break;
	}

	case 4:
	{
		vector<vector<int>> copy = vec;
		vector<vector<int>> newVec(M, vector<int>(N));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				newVec[M - 1 - j][i] = copy[i][j];
			}
		}
		vec = newVec;
		swap(N, M);
		break;
	}

	case 5:
	{
		int n = N / 2;
		int m = M / 2;

		vector<vector<int>> newVec1(n, vector<int>(m));
		vector<vector<int>> newVec2(n, vector<int>(m));
		vector<vector<int>> newVec3(n, vector<int>(m));
		vector<vector<int>> newVec4(n, vector<int>(m));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				newVec1[i][j] = vec[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = m; j < M; j++)
			{
				newVec2[i][j - m] = vec[i][j];
			}
		}

		for (int i = n; i < N; i++)
		{
			for (int j = m; j < M; j++)
			{
				newVec3[i - n][j - m] = vec[i][j];
			}
		}

		for (int i = n; i < N; i++)
		{
			for (int j = 0; j < m; j++)
			{
				newVec4[i - n][j] = vec[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				vec[i][j + m] = newVec1[i][j]; // 1 → 2
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				vec[i + n][j + m] = newVec2[i][j]; // 2 → 3
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				vec[i + n][j] = newVec3[i][j]; // 3 → 4
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				vec[i][j] = newVec4[i][j]; // 4 → 1
		}

		break;
	}
	case 6:
	{
		int n = N / 2;
		int m = M / 2;

		vector<vector<int>> newVec1(n, vector<int>(m));
		vector<vector<int>> newVec2(n, vector<int>(m));
		vector<vector<int>> newVec3(n, vector<int>(m));
		vector<vector<int>> newVec4(n, vector<int>(m));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				newVec1[i][j] = vec[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = m; j < M; j++)
			{
				newVec2[i][j - m] = vec[i][j];
			}
		}

		for (int i = n; i < N; i++)
		{
			for (int j = m; j < M; j++)
			{
				newVec3[i - n][j - m] = vec[i][j];
			}
		}

		for (int i = n; i < N; i++)
		{
			for (int j = 0; j < m; j++)
			{
				newVec4[i - n][j] = vec[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				vec[i + n][j] = newVec1[i][j]; // 1 → 4
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				vec[i + n][j + m] = newVec4[i][j]; // 4 → 3
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				vec[i][j + m] = newVec3[i][j]; // 3 → 2
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				vec[i][j] = newVec2[i][j]; // 2 → 1
		}
		break;
	}

	default:
		break;
	}
}

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(nullptr);
	cout.tie(nullptr);

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

	while (R--)
	{
		int typeNum;

		cin >> typeNum;

		change(vec, typeNum, N, M);
	}


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
