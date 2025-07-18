#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	int N;
	cin >> N;

	while (N--)
	{
		int n, m; // 문서의 갯수 n , 몇번째로 인쇄되었는지 정수 m
		int x;

		cin >> n >> m;

		queue<pair<int, int>> q;
		priority_queue<int> pq;

		for (int i = 0; i < n; i++)
		{
			cin >> x;

			q.push({ x,i });
			pq.push(x);
		}

		int pqIndex = 0;

		while (!q.empty())
		{
			int value = q.front().first;
			int index = q.front().second;
			q.pop();

			//가장 우선순위가 높은 값과 현재 값과 똑같음
			if (value == pq.top())
			{
				pqIndex++;
				pq.pop();

				if (m == index)
				{
					cout << pqIndex << "\n";
					break;
				}
			}
			else
			{
				q.push({ value , index });
			}
		}
	}

	return 0;
}
