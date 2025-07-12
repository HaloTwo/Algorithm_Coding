#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, x;
	string str;
	queue<int> que;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str;

		if (str == "push")
		{
			cin >> x;

			que.push(x);
		}
		else if (str == "pop")
		{
			if (que.empty())
				cout << -1 << "\n";
			else {
				cout << que.front() << "\n";
				que.pop();
			}
		}
		else if (str == "size")
		{
			cout << que.size() << "\n";
		}
		else if (str == "empty")
		{
			cout << (que.empty() ? 1 : 0) << "\n";
		}
		else if (str == "front")
		{
			cout << (que.empty() ? -1 : que.front()) << "\n";
		}
		else if (str == "back")
		{
			cout << (que.empty() ? -1 : que.back()) << "\n";
		}

	}

	return 0;
}


