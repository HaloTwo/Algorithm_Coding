#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<pair<int, int>> Man(N);
	vector<int> rank(N, 1);

	for (int i = 0; i < N; i++)
	{
		cin >> Man[i].first >> Man[i].second;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j) continue;


			if (Man[i].first < Man[j].first &&Man[i].second < Man[j].second) 
			{
				rank[i]++;
			}
		}
	}

	for (int i = 0; i < N; i++) 
	{
		cout << rank[i] << " ";
	}

	return 0;
}