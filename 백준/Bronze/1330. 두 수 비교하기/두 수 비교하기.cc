#include <stdio.h>
#include <string>

using namespace std;

int main()
{
	int n, m;
	string result;

	scanf("%d%d", &n, &m);

	if (n > m)
	{
		result = ">";
	}
	else if (n < m)
	{
		result = "<";
	}
	else if (n == m)
	{
		result = "==";
	}

	printf("%s", result.c_str());

	return 0;
}

