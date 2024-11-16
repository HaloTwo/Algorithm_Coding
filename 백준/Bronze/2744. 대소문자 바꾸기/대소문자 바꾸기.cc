#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;

	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		if (islower(s[i]))
		{
			s[i] = toupper(s[i]);
		}
		else if (isupper(s[i]))
		{
			s[i] = tolower(s[i]);
		}
	}

	cout << s;

}