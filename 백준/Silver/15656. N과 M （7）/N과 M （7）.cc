#include <iostream>
#include <algorithm>
using namespace std;

int N, M; // 1~Nㄲ지의 자연수 중 중복없이 M개를 고른
int selected[10];
bool used[10];
int num[10];

void backtrack(int depth)
{
	//M개의 깊이까지 왔음
	if (depth == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << selected[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++)
	{
		int curNum = num[i];

		//이미 방문했음
		//if (used[i]) continue;

		selected[depth] = curNum;
		used[i] = true;

		//다음 깊이로
		backtrack(depth + 1);

		used[i] = false;
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	sort(num, num + N);
	backtrack(0);
}
