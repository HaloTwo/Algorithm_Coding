#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[100001] = { false };
int dist[100001];
int parent[100001];

void bfs(int N, int M)
{
	queue<int> q;

	visited[N] = true;
	dist[N] = 0;

	q.push(N);

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		if (current == M)
		{
			cout << dist[current] << "\n";

			vector<int> result;

			for (int i = M; i != N; i = parent[i])
			{
				result.push_back(i);
			}
			result.push_back(N);

			reverse(result.begin(), result.end());

			for (int i = 0; i < result.size(); i++)
			{
				cout << result[i] << " ";
			} 
			return;
		}

		int num[3] = { current - 1, current + 1 , current * 2 };

		for (int i = 0; i < 3; i++)
		{
			int next = num[i];
			if (next >= 0 && next <= 100000 && !visited[next])
			{
				dist[next] = dist[current] + 1;
				visited[next] = true;
				parent[next] = current;
				q.push(next);
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);

	int N, M;

	cin >> N >> M;

	bfs(N, M);

	return 0;
}
