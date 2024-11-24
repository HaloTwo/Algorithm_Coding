#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string n;
	cin >> n;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 1 && i == 1)
			{
				cout <<':'<< n <<':';
			}
			else
			{
				cout << ":fan:";
			}
		}
		cout << "\n";
	}

	return 0;
}