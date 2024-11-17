#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	int anwser = 0;

	cin >> a;

	for (int i = 0; i < 5; i++)
	{
		cin >> b;

		if (a == b)
		{
			anwser++;
		}
	}

	cout << anwser;
}