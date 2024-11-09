#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N, K;

	cin >> N >> K;

	queue<int> num;

	for (int i = 1; i <= N; i++)
	{
		num.push(i);
	}

	//문제 해결
	cout << "<";
	while (num.size() > 1)
	{
		for (int i = 1; i < K; i++)
		{
			int tmp = num.front();
			num.pop();
			num.push(tmp);
		}
		cout << num.front() << ", ";
		num.pop();
	}
	cout << num.front() << ">";

	int count = 0;


	return 0;
}