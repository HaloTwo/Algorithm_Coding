#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int count = 1;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		count *= i;
	}

	cout << count;

	return 0;
}