#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int H;
	int type = -1; 
	int prev = 0;

	for (int i = 1; i <= 8; i++)
	{
		cin >> H;

		if (i == 1) {
			prev = H;
			if (H == 1) type = 0;       
			else if (H == 8) type = 1;   
			else type = -1;
			continue;
		}

		if (type == 0 && H != i) type = -1;
		if (type == 1 && H != 9 - i) type = -1;

		prev = H;
	}

	switch (type)
	{
	case 0:
		cout << "ascending";
		break;
	case 1:
		cout << "descending";
		break;
	default:
		cout << "mixed";
		break;
	}

	return 0;
}