#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;

	int num = 666;
	int count = 0;

	while (true)
	{
		string str = to_string(num);
		if (str.find("666") != string::npos)
		{
			count++;
			if (count == N)  break;
		}
		num++;
	}

	cout << num;

	return 0;
}