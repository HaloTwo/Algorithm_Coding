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

	int T;

	cin >> T;

	while (T--)
	{

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
		vector<pair<int, int>> graph[10001];
		int dist[10001];

		fill(dist, dist + 10001, 1e9);

		int n, d, c; // 컴퓨터의 개수, 의존성 개수, 해킹당한 컴퓨터
		cin >> n >> d >> c;

		for (int i = 0; i < d; i++)
		{
			int a, b, s;
			cin >> a >> b >> s;
			graph[b].push_back({ a,s });
		}

		dist[c] = 0;
		pq.push({ 0,c });

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

				if (dist[nextNode] > cost + weight)
				{
					dist[nextNode] = cost + weight;
					pq.push({ dist[nextNode], nextNode });
				}
			}
		}


		int count = 0;
		int time = 0;

		for (int i = 1; i <= n; i++)
		{
			if (dist[i] != 1e9)
			{
				count++;
				time = max(time, dist[i]);
			}
		}

		cout << count << " " << time << "\n";

	}
}