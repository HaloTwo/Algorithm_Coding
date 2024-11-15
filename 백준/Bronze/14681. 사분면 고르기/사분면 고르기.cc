#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x, y;
	int result= 0;

	cin >> x >> y;

	if (x > 0 && y > 0)
	{
		result = 1;
	}
	else if (x < 0 && y < 0)
	{
		result = 3;
	}
	else if (x < 0 && y > 0)
	{
		result = 2;
	}
	else
	{
		result = 4;
	}

	cout << result;
	
	return 0;
}