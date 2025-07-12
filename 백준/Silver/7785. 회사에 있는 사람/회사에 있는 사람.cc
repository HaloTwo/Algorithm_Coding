#include<iostream>
#include<set>
#include<string>;
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	string name, txt;
	set<string, greater<string>> people;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> name >> txt;

		if (txt == "enter")
		{
			people.insert(name);
		}
		else if (txt == "leave" && people.find(name) != people.end())
		{
			people.erase(name);
		}
	}

	for (const string& p : people) 
	{
		cout << p << '\n';
	}



}