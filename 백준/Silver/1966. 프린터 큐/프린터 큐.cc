#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(nullptr);
	cout.tie(nullptr);


	int testCase, n, targetNum;

	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		cin >> n >> targetNum;


		queue<pair<int, int>> q;           // <중요도, 인덱스>
		priority_queue<int> pq;            // 최대 중요도 관리


		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;

			q.push({ num, j });
			pq.push(num);
		}

		int count = 0;

		while (!q.empty())
		{
			int a = q.front().first;
			int b = q.front().second;
			q.pop();

			//중요도가 동일한 문서를 찾으면 
			if (a == pq.top())
			{
				pq.pop();
				count++;

				//관심 문서면 출력
				if (b == targetNum)
				{
					cout << count << '\n';
					break;
				}
			}
			//못찾으면 다시 맨 뒤로 보내기
			else
				q.push({ a,b });
		}
	}
	return 0;
}
