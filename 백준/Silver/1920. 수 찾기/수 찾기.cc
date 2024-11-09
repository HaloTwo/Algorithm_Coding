#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector<int> num;

int Search(vector<int>& arr, int target)
{
	int start = 0;
	int end = arr.size() - 1;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (arr[mid] == target)
		{
			return 1;
		}
		// 왼쪽 탐색
		if (arr[mid] > target)
		{
			end = mid - 1;
		}
		// 오른쪽 탐색
		else
		{
			start = mid + 1;
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> M;
		num.push_back(M);
	}

	sort(num.begin(), num.end());

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> M;
		cout << Search(num, M) << "\n";
	}

	return 0;
}
