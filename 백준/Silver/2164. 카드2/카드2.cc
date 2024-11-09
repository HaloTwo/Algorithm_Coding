#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
	int count = 0;
	queue<int> cards;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cards.push(i);
	}

	while (cards.size() > 1)
	{
		count++;

		//맨 위 카드 맨 밑으로 옮기기
		if (count % 2 == 0)
		{
			int returnCard = cards.front();
			cards.pop();
			cards.push(returnCard);
		}
		//버리기
		else
		{
			cards.pop();
		}
	}

	cout << cards.front();
}