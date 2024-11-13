#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	if (N == 0) 
	{
		cout << "0";
		return 0;
	}

	vector<int> score(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> score[i];
	}

	sort(score.begin(), score.end());

	int cutPeople = round(N * 0.15);

	double sum = 0;
	for (int i = cutPeople; i < score.size() - cutPeople; i++)
	{
		sum += score[i];
	}

	cout << round(sum / (score.size() - cutPeople * 2));

	return 0;
}