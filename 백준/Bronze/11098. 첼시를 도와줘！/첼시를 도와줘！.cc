#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n;


	while (n--)
	{
		cin >> m;
		map<int, string> map;

		for (int i = 0; i < m; i++)
		{
			int num;
			string key;

			cin >> num >> key;

			map[num] = key;
		}

		auto it = map.end();
		cout << (--it)->second << "\n";
	}

	return 0;
}