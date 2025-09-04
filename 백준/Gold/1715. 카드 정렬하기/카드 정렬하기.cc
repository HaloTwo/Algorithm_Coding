#include <iostream>
#include <queue>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);

	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;


	for (int i = 0; i < N; i++) 
	{
		int num;
		cin >> num;
		pq.push(num);
	}

	int total = 0;

	while (pq.size() > 1) 
	{
		int a = pq.top(); 
		pq.pop();

		int b = pq.top(); 
		pq.pop();

		int cost = a + b;
		total += cost;

		pq.push(cost);
	}

	cout << total;
}
