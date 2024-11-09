#include <iostream>
#include <string>
using namespace std;

void OX_Check(string& OX)
{
	int count = 0;
	int add = 0;

	for (int i = 0; i < OX.size(); i++)
	{
		if (OX[i] == 'O')
		{
			count++;
		}
		else if (OX[i] == 'X')
		{
			count = 0;
		}

		add += count;
	}

	cout << add << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	string OX;

	cin >> N;


	for (int i = 0; i < N; i++)
	{
		cin >> OX;
		OX_Check(OX);
	}

	return 0;
}