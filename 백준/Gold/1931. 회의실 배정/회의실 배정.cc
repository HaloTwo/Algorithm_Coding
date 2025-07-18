#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, startTime, endTime;

	cin >> N;

	vector<pair<int, int>> times(N);

	for (int i = 0; i < N; i++)
	{
		cin >> startTime >> endTime;

		times[i] = { endTime, startTime };
	}

	sort(times.begin(), times.end());

	int count = 0;
	int minTime = -1;

	for (int i = 0; i < N; i++)
	{
		if (times[i].second >= minTime)
		{
			count++;
			minTime = times[i].first;
		}
	}

	cout << count;

	return 0;
}
