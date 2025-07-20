#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 
bool visited[26][26] = { false };
int map[26][26];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int i, int j, int N, int& count) 
{
	visited[i][j] = true;
	count++;

	for (int x = 0; x < 4; x++)
	{
		int nx = dx[x] + i;
		int ny = dy[x] + j;

		if (nx >= 0 && ny >= 0 && nx < N && ny < N)
		{
			if (map[nx][ny] == 1 && !visited[nx][ny])
			{
				dfs(nx, ny, N, count);
			}
		}
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, n;

	cin >> N ;


	for (int i = 0; i < N; i++)
	{
		string line;
		cin >> line; // 한 줄 통째로 입력받기

		for (int j = 0; j < N; j++)
		{
			map[i][j] = line[j] - '0'; // 문자 -> 숫자 변환
		}
	}

	vector<int> vec;


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && !visited[i][j])
			{
				int count = 0;

				dfs(i, j, N, count);
				vec.push_back(count);
			}
		}
	}

	sort(vec.begin(), vec.end());

	cout << vec.size() << "\n";
	for (int n : vec) cout << n << "\n";

	return 0;
}
