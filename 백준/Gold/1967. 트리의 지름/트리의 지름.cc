#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> graph[10001];
bool visited[10001] = { false };

int far_node;          // 가장 멀리 있는 노드
long long far_dist = -1;    // 그 때의 거리(누적)

void dfs(int node, long long dist) 
{
	visited[node] = true;

	if (dist > far_dist) 
	{       
		far_dist = dist;
		far_node = node;
	}

	for (auto a : graph[node])
	{
		int next = a.first;
		int w = a.second;
		if (!visited[next])
		{
			dfs(next, dist + w);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N-1; i++)
	{
		int parent, child, weight;

		cin >> parent >> child >> weight;

		graph[parent].push_back({ child, weight });
		graph[child].push_back({ parent, weight });
	}

	dfs(1, 0);

	fill(begin(visited), end(visited), false);
	long long start_node = far_node;
	far_dist = -1;

	dfs((int)start_node, 0);

	cout << far_dist << "\n";

	return 0;
}
