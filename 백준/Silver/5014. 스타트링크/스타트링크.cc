#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include <tuple>  

using namespace std;


int main()
{
	ios::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);

	int F, S, G, U, D; // 건물의 총 층 수, S 현재 층, G는 목표층, U 위로, D 아래로
	int dist[1000001];

	fill(dist, dist + 1000001, -1);

	cin >> F >> S >> G >> U >> D;

	queue<int> q;

	dist[S] = 0;
	q.push(S);

	if (S == G)
	{
		cout << 0 << '\n';
		return 0;
	}

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		int nextFloorType[2] = { current + U, current - D };

		for (int i = 0; i < 2; i++)
		{
			int nextFloor = nextFloorType[i];

			if (nextFloor < 1 || nextFloor > F) continue; // 유효 범위 체크
			if (dist[nextFloor] != -1) continue;

			dist[nextFloor] = dist[current] + 1;
			q.push(nextFloor);

			//다음 층이 목표층이랑 똑같으면
			if (nextFloor == G)
			{
				cout << dist[nextFloor] << '\n';
				return 0;
			}

		}

	}

	cout << "use the stairs";

	return 0;
}