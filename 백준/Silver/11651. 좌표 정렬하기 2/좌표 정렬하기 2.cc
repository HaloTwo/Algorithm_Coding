#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector<pair<int, int>> map;

bool cmp(pair<int, int>a, pair<int, int> b)
{
	if (a.second == b.second) return a.first < b.first;

	return a.second < b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	int X, Y;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> X >> Y;

		map.push_back({ X,Y });
	}


	sort(map.begin(), map.end(), cmp);

	for (int i = 0; i < N; i++)
	{
		cout << map[i].first << " " << map[i].second << "\n";
	}

	return 0;
}