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

	int n; //사람의 수
	int x, y; // 1, 2
	int m; // 관계의 수

	cin >> n >> x >> y >> m;

	vector<int> graph[101];
	bool visited[101] = {};

	for (int i = 0; i < m; i++)  
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);  
	}


	queue<pair<int, int>> q;

	visited[x] = true;
	q.push({ x, 0 });  // 시작 노드 x, 촌수 0부터 시작

	while (!q.empty())
	{
		int curX = q.front().first;
		int count = q.front().second;
		q.pop();

		if (curX == y)
		{
			cout << count;
			return 0;
		}

		for (auto& next : graph[curX])
		{
			if (!visited[next])
			{
				visited[next] = true;
				q.push({ next, count + 1 });
			}
		}
	}

	cout << -1;

}