#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	int count = 0;

	cin >> n;
	vector<int> num(n);

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	cin >> x;

	for (int i = 0; i < n; i++)
	{
		if (num[i] == x)
		{
			count++;
		}
	}

	cout << count;

	return 0;
}