#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	map<int, int> numMap;

	for (int i = 0; i < 11; i++)
	{
		cin >> N;
		numMap[N % 42]++;
	}

	cout << numMap.size();

	return 0;
}