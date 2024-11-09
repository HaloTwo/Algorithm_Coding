#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M = 1;
	string numText;
	map<int, int> numMap = {};


	for (int i = 0; i < 3; i++)
	{
		cin >> N;

		M *= N;
	}

	numText = to_string(M);

	for (int i = 0; i < numText.size(); i++)
	{
		N = numText[i] - '0';
		numMap[N]++;
	}

	for (int i = 0; i <= 9; i++)
	{
		cout << numMap[i] << "\n";
	}

	return 0;
}