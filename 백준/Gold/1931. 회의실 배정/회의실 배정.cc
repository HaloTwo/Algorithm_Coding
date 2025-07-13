#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, startTime, endTime;
	int count = 0;
	int lastEnd = 0;

	vector<pair<int, int>> time;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> startTime >> endTime;

		time.push_back({endTime, startTime});
	}

	sort(time.begin(), time.end());

	for (int i = 0; i < time.size(); i++)
	{
		if (time[i].second >= lastEnd) 
		{ 
			count++;
			lastEnd = time[i].first; 
		}
	}

	cout << count;

	return 0;
}
