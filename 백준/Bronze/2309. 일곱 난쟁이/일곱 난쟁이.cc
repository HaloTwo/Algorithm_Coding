#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> allPerson(9);
	int add = 0;

	for (int i = 0; i < 9; i++)
	{
		cin >> allPerson[i];
		add += allPerson[i];
	}

	sort(allPerson.begin(), allPerson.end());

	int target = add - 100;
	int fake1 = -1, fake2 = -1;

	for (int i = 0; i < 8; i++) 
	{
		for (int j = i + 1; j < 9; j++) 
		{  
			if (allPerson[i] + allPerson[j] == target) 
			{
				fake1 = i;
				fake2 = j;
				break;
			}
		}
		if (fake1 != -1) break;
	}


	for (int i = 0; i < 9; i++)
	{
		if (i == fake1 || i == fake2) continue;
		
		cout << allPerson[i] << "\n";
	}

	return 0;
}