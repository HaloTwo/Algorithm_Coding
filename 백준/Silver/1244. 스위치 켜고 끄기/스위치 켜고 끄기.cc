#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, p, x, y;
	cin >> n;

	vector<int>sw(n);

	for (int i = 0; i < n; i++)
	{
		cin >> sw[i];
	}

	cin >> p;
	while (p--)
	{
		cin >> x >> y;

		//남학생
		if (x == 1)
		{
			for (int i = y-1; i <= n; i += y)
			{
				if (sw[i] == 0)
				{
					sw[i] = 1;
				}
				else if (sw[i] == 1)
				{
					sw[i] = 0;
				}
			}
		}
		//여학생
		else if (x == 2) 
		{
			y--;  

			sw[y] = !sw[y];

			// 대칭 검사
			for (int i = 1; y - i >= 0 && y + i < n; i++) 
			{
				if (sw[y - i] == sw[y + i]) 
				{
					sw[y - i] = !sw[y - i];
					sw[y + i] = !sw[y + i];
				}
				else break;
			}
		}

	}


	for (int i = 0; i < n; i++) 
	{
		cout << sw[i];
		if (i < n - 1) cout << " ";
		if ((i + 1) % 20 == 0) cout << "\n";
	}
	if (n % 20 != 0) cout << "\n";  

	return 0;
}