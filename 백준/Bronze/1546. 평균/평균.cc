#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	float result = 0;
	vector<float> point;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		point.push_back(m);
	}

	sort(point.begin(), point.end());

	int M = point[n - 1];

	for (int i = 0; i < point.size(); i++)
	{
		result += (point[i] / M) * 100;
	}

	printf("%f", result / n);

	return 0;
}