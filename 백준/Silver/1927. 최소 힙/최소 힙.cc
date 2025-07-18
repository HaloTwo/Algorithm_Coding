#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, x;

	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;

		if (x == 0 && pq.size() == 0)
		{
			cout << 0 << "\n";
		}
		else if (x == 0)
		{
			int top = pq.top();
			cout << top << "\n";
			pq.pop();
		}
		else pq.push(x);
	}


	return 0;
}

//x가 0이 나오면 배열에서 가장 작은 값을 출력하고 그 값을 제거
//만약 배열이 비어있는데, x가 0이 나오면 0출력

