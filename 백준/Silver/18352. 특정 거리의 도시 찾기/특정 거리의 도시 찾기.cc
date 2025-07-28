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

	vector<int> graph[300001];
	queue<int> q;
	int dist[300001];

	int N, M, K, X; // 정점 갯수, 간선 갯수, 거리정보 , 출발 도시 번호

	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
	}

	fill(dist, dist + 300001, -1);  // 거리 초기화
	q.push(X);
	dist[X] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto& next : graph[cur])
		{
			if (dist[next] == -1) 
			{
				dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}
	}

	bool found = false;
	for (int i = 1; i <= N; i++) 
	{
		if (dist[i] == K) 
        {
			cout << i << "\n";
			found = true;
		}
	}

	if (!found) cout << -1 << "\n";
}