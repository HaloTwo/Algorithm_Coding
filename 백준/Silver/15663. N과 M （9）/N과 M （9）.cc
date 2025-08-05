#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M; // 1~Nㄲ지의 자연수 중 중복없이 M개를 고른
int selected[10];
bool used[10];
vector<int> v;

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

	for (int i = 0; i < v.size(); i++)
	{
		int curNum = v[i];

		//이미 방문했음
		if (used[i]) continue;

		// ★ 중복 스킵 핵심
		if (i > 0 && v[i] == v[i - 1] && !used[i - 1]) continue;

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
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());  

	backtrack(0);
}
