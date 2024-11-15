#include<bits/stdc++.h>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cout.tie(0);

	int n;
	string str;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;

		cout << str.front() << str.back() << "\n";
	}

}