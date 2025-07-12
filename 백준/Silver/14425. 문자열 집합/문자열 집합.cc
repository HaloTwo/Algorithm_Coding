#include<iostream>
#include<vector>
#include<set>
#include<string>;
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, count = 0;

	string s;
	set<string>str; 
	 
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> s;

		str.insert(s);
	}

	for (int i = 0; i < M; i++) 
	{
		cin >> s;

		if (str.find(s) != str.end()) count++;
	}

	cout << count << '\n';
}