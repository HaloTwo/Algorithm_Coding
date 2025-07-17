#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int v)
{
	visited[v] = true;

	for (int next : graph[v])
	{
		if (!visited[next])
		{
			dfs(next);
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);

	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b); // a에서 b로 가는 간선
		graph[b].push_back(a); // b에서 a로 가는 간선 (양방향)
	}

	int cnt = 0;

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			dfs(i);
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}
