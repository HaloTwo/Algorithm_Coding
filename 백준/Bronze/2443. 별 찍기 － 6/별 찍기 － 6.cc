#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < i; j++) 
		{
			cout << " ";
		}

		for (int k = 1; k <= (n * 2 - (i * 2 + 1)); k++) 
		{
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}