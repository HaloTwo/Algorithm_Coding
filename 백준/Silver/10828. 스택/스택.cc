#include <iostream>
#include <stack>
#include <algorithm>  

using namespace std;

int n, m;
string controll;

stack<int> stk = {};

//아오 무식하게 풀었네
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> controll;

		if (controll == "push")
		{
			cin >> m;
			stk.push(m);
		}
		else if (controll == "pop")
		{
			if (stk.empty()) 
			{
				cout << -1 << "\n";
			}
			else 
			{
				cout << stk.top() << "\n";
				stk.pop();
			}
		}
		else if (controll == "size")
		{
			cout << stk.size() << "\n";
		}
		else if (controll == "empty")
		{
			cout << (stk.empty() ? 1 : 0) << "\n";
		}
		else if (controll == "top")
		{
			cout << (stk.empty() ? -1 : stk.top()) << "\n";
		}

	}

	return 0;
}