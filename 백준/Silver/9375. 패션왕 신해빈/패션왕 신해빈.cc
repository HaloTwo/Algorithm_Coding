#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(nullptr);
	cout.tie(nullptr);


	int n, clothes;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> clothes;

		map<string, int> clothesMap;
		string clothesType;
		string clothesName;

		for (int j = 0; j < clothes; j++)
		{
			cin >> clothesName >> clothesType;

			clothesMap[clothesType]++;
		}

		int count = 1;

		for (const auto& clothtype : clothesMap)
		{
			count *= clothtype.second + 1;
		}

		count--;

		cout << count << "\n";
	}

	return 0;
}
