#include <iostream>

using namespace std;
int main() 
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cout.tie(0);

	int count[10001] = { 0 };
	int length; int temp; 

	cin >> length;
	for (int a = 0; a < length; a++) 
	{
		cin >> temp;
		count[temp]++;
	}

	for (int a = 0; a <= 10000; a++) 
	{
		for (int b = 0; b < count[a]; b++) 
		{
			cout << a << '\n';
		}
	}
}