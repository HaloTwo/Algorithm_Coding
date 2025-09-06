#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> graph[100001];
bool visited[100001] = { false };
int parent_[100001];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	stack<int> st;
	st.push(1);
	visited[1] = true;
	parent_[1] = 0;               

	while (!st.empty()) 
	{
		int current = st.top();
		st.pop();

		for (int next : graph[current])
		{
			if (visited[next]) continue;
			visited[next] = true;
			parent_[next] = current;     
			st.push(next);
		}
	}

	for (int i = 2; i <= N; i++)
	{
		cout << parent_[i] << '\n';
	}

	return 0;
}
