#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int N, K, Add = 0;

	stack<int> stk;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> K;

		if (K == 0)
		{
			stk.pop();
			continue;
		}

		stk.push(K);
	}

	while (stk.size() >= 1)
	{
		Add += stk.top();
		stk.pop();
	}

	cout << Add;

	return 0;
}