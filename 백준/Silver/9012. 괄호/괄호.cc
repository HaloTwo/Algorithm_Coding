#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	string str;

	cin >> N;

	while (N--)
	{
		cin >> str;
		if (str == ".") break;

		stack<char> st;
		bool isbool = true;

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(')
			{
				st.push(str[i]);
			}
			else if (str[i] == ')')
			{
				if (st.empty() || st.top() != '(')
				{
					isbool = false;
					break;
				}
				st.pop();
			}
		}

		cout << (isbool && st.empty() ? "YES" : "NO") << "\n";
	}
	return 0;
}