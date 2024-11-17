#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	int smallvalue = 10001;
	int add = 0;

	for (int i = 0; i < 7; i++)
	{
		cin >> n;

		if (n % 2 == 1)
		{
			add += n;

			if (smallvalue > n)
			{
				smallvalue = n;
			}
		}

	}

	if (add != 0)
	{
		cout << add << "\n";
		cout << smallvalue;
	}
	else 
	{
		cout << -1;
	}

	return 0;
}