#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//재귀를 이용
void dfs(bool visited[], vector<int> graph[], int v)
{
	visited[v] = true;
	cout << v << " ";

	for (int next : graph[v])
	{
		if (!visited[next])
		{
			dfs(visited, graph, next);
		}
	}
}

//큐를 이용
void bfs(bool visited[], vector<int> graph[], int v)
{
	queue<int> q;

	q.push(v);
	visited[v] = true;

	while (!q.empty())
	{
		int qFront = q.front();
		q.pop();

		cout << qFront << " ";

		for (int next : graph[qFront])
		{
			if (!visited[next])
			{
				visited[next] = true;
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


	int N, M, V;


	cin >> N >> M >> V;

	vector<int> graph[1001];
	bool visited[1001] = { false };

	for (int i = 0; i < M; i++)
	{
		int a, b;

		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(visited, graph, V);

	cout << "\n";
	fill(visited, visited + 1001, false); 

	bfs(visited, graph, V);

	return 0;
}
