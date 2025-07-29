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

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	vector<pair<int, int>>graph[101];


	int n, m, r; // 지역의 개수, 수색범위, 길의 개수
	cin >> n >> m >> r;

	int items[101]; // 각 지역에 있는 아이템 수
	for (int i = 1; i <= n; i++) 
	{
		cin >> items[i];
	}

	for (int i = 0; i < r; i++)
	{
		int a, b, l;

		cin >> a >> b >> l;
		graph[a].push_back({ b, l });
		graph[b].push_back({ a, l });
	}

	int answer = 0;

	for (int i = 1; i <= n; i++)
	{
		int dist[101];

		fill(dist, dist+101, 1e9);

		dist[i] = 0;
		pq.push({0, i});

		while (!pq.empty())
		{
			int cost = pq.top().first;
			int node = pq.top().second;
			pq.pop();

			if (dist[node] < cost) continue;

			for (auto& next : graph[node])
			{
				int nextNode = next.first;
				int weight = next.second;

				if (dist[nextNode] > weight + cost)
				{
					dist[nextNode] = weight + cost;
					pq.push({dist[nextNode], nextNode});
				}
			}
		}

		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (dist[j] <= m) 
			{
				sum += items[j];
			}
		}

		answer = max(answer, sum);
	}

	cout << answer;
}