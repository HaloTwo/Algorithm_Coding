#include <iostream>
#include <set>
#include <vector>
#include <algorithm>  

using namespace std;

int n, m, result;
string str;
set<string> nostringName = {};
vector<string> resultNames = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;


	for (int i = 0; i < n; i++)
	{
		cin >> str;
		nostringName.insert(str);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> str;

		if (nostringName.find(str) != nostringName.end())
		{
			result++;
			resultNames.push_back(str);
		}
	}

	sort(resultNames.begin(), resultNames.end());

	cout << result << "\n";

	for (auto name : resultNames)
	{
		cout << name << "\n";
	}


	return 0;
}