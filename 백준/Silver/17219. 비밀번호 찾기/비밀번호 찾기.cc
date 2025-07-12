#include<iostream>
#include<map>
#include<string>;
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	string site, pwd;
	map<string, string> map;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> site >> pwd;
		map[site] = pwd;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> site;

		if (map.find(site) != map.end())
		{
			cout << map[site] << "\n";
		}
	}


}