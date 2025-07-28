#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<pair<int, int>> graph[1001];
	int dist[1001];
	fill(dist, dist + 1001, 1e9);

	int N, M;

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int u, v, cost;
		cin >> u >> v >> cost;

		graph[u].push_back({ v, cost });
	}

	int start, dest;
	cin >> start >> dest;

	dist[start] = 0;
	pq.push({ 0, start }); 

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (dist[node] < cost) continue;

		for (auto& next : graph[node]) 
		{
			int nextNode = next.first;
			int nextCost = next.second;

			if (dist[nextNode] > cost + nextCost) 
			{
				dist[nextNode] = cost + nextCost;
				pq.push({ dist[nextNode], nextNode });
			}
		}
	}

	cout << dist[dest];
}