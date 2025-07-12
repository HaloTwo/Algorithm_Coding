#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, x;

	vector<int> vec;
	vector<int> sorted;

	map<int, int> map;

	cin >> N;
	vec.resize(N);

	for (int i = 0; i < N; i++) cin >> vec[i];
	
	sorted = vec;
	sort(sorted.begin(), sorted.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

	//여기까지하면 
	//vec는 2 4 -10 4 -9
	//sorted는 -10 -1 2 4

	for (int i = 0; i < sorted.size(); i++)
	{
		map[sorted[i]] = i;
	}

	for (int i = 0; i < N; i++)
	{
		cout << map[vec[i]] << " ";
	}
}