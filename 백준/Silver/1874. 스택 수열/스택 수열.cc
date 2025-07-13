#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, x;

	queue<int> que;
	vector<string> result;

	stack<int> stk;

	cin >> n;

	//vec에 값 다 넣어둠
	for (int i = 0; i < n; i++) que.push(i + 1);

	for (int i = 0; i < n; i++)
	{
		cin >> x;

		while (!que.empty() && que.front() <= x)
		{
			stk.push(que.front());
			que.pop();

			result.push_back("+");
		}


		if (!stk.empty() && stk.top() == x)
		{
			stk.pop();
			result.push_back("-");
		}
		else if (!stk.empty() && stk.top() > x)
		{
			cout << "NO\n";
			return 0;
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}


	return 0;
}
