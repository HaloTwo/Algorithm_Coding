#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x, y;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		cout << x + y << "\n";
	}

	return 0;
}