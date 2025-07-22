#include <iostream>
#include <vector>
#include <deque>

using namespace std;


int dist[100001]; // 최소 시간,
const int INF = 1e9;

void bfs(int N, int M)
{

	for (int i = 0; i <= 100001; i++)
	{
		dist[i] = INF;
	}

	deque<int> dq;

	dq.push_back(N);
	dist[N] = 0;

	while (!dq.empty())
	{
		int current = dq.front();
		dq.pop_front();

		if (current == M)
		{
			cout << dist[current];
			return;
		}

		int case0 = current * 2;

		if (case0 <= 100000 && dist[case0] > dist[current])
		{
			dist[case0] = dist[current];
			dq.push_front(case0);
		}

		int case1[2] = { current + 1, current - 1 };

		for (int i = 0; i < 2; i++)
		{
			if (case1[i] <= 100000 && dist[case1[i]] > dist[current] + 1)
			{
				dist[case1[i]] = dist[current] + 1;
				dq.push_back(case1[i]);
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);

	int N, M;

	cin >> N >> M;

	bfs(N, M);

	return 0;
}
