#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;


int dist[100001];
bool visited[100001];
int cnt[100001];

void bfs(int N, int M)
{
	queue<int> q;
	q.push(N);

	visited[N] = true;
	dist[N] = 0;
	cnt[N] = 1;

	while (!q.empty())
	{
		int currentNum = q.front();
		q.pop();

		int num[3] = { currentNum - 1, currentNum + 1, currentNum * 2 };
		for (int i = 0; i < 3; i++)
		{
			int next = num[i];

			if (next < 0 || next > 100000) continue;

			//방문하지 않았다면 다시 반복하게 추가
			if (!visited[next])
			{
				dist[next] = dist[currentNum]+1;
				cnt[next] = cnt[currentNum];         
				visited[next] = true;
				q.push(next);
			}
			//목적지에 도달했다면 ?
			else if (dist[next] == dist[currentNum] + 1)
			{
				// 같은 최소 거리로 도달한 경우 → 경로 추가
				cnt[next] += cnt[currentNum];
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

	cout << dist[M] << "\n";
	cout << cnt[M] << "\n";

	return 0;
}
