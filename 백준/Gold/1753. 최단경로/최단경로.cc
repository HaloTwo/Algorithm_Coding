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
	vector<pair<int, int>> graph[20001];
	int dist[20001];

	fill(dist, dist + 20001, 1e9);

	int V, E, K;

	cin >> V >> E >> K;

	for (int i = 0; i < E; i++)
	{
		int u, v, w;

		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}

	dist[K] = 0;
	pq.push({ 0, K });
	
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

			if (dist[nextNode] > dist[node] + nextCost) 
			{
				dist[nextNode] = dist[node] + nextCost;
				pq.push({ dist[nextNode], nextNode });
			}

		}
	}

	for (int i = 1; i <= V; i++) 
	{
		if (dist[i] == 1e9) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}