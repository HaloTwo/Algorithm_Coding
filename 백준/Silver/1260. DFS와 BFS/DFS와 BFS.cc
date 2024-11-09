#include <iostream>
#include <vector>
#include <algorithm> 
#include <queue>
using namespace std;

const int MAX = 1001;    // N이 1000 이하
vector<int> graph[MAX];  // 인접 리스트
bool visited[MAX] = {};       // 방문 체크 배열

//시작 정점
void dfs(int node)
{
	visited[node] = true;
	cout << node << " ";

	for (auto next : graph[node])
	{
		if (!visited[next])
		{
			dfs(next);
		}
	}
}

void bfs(int start)
{
	queue<int> q;

	visited[start] = true;
	q.push(start);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		cout << node << " ";

		for (int next : graph[node])
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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, V;
	cin >> N >> M >> V;    // 정점 개수, 간선 개수, 시작 정점

	// 간선 정보 입력
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);    // 양방향 그래프
	}

	//정렬
	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(V);
	fill(visited, visited + MAX, false);
	cout << "\n";
	bfs(V);

	return 0;
}

