#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, x;
	vector<int> vec;

	cin >> N;
	vec.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		vec[i] = x;
	}

	sort(vec.begin(), vec.end());

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> x;

		cout << binary_search(vec.begin(), vec.end(), x) << "\n";
	}
}