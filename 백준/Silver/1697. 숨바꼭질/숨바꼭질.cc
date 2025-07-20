#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[100001] = { false };
int dist[100001];

void bfs(int n, int k)
{
	queue<int> q;
	q.push(n);
	visited[n] = true;
	dist[n] = 0;

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		if (current == k)
		{
			cout << dist[current] << "\n";
			return; // 찾았으니 끝
		}

		int next[3] = { current - 1, current + 1, current * 2 };

		for (int i = 0; i < 3; i++)
		{
			int nx = next[i];
			if (nx >= 0 && nx <= 100000 && !visited[nx])
			{
				visited[nx] = true;
				dist[nx] = dist[current] + 1; 
				q.push(nx);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;

	cin >> N >> K;

	bfs(N, K);


	return 0;
}
