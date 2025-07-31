#include<iostream>


using namespace std;


int parent[1000001];

// 대표 노드를 찾는다 (경로 압축 포함)
int find(int x) 
{
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);  // 경로 압축
}

// 두 집합을 합친다
void union_set(int a, int b) 
{
	a = find(a);
	b = find(b);

	if (a != b) parent[b] = a;
}

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	// 부모 배열 초기화
	for (int i = 0; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) 
	{
		int cmd, a, b;
		cin >> cmd >> a >> b;

		if (cmd == 0) 
		{
			union_set(a, b);
		}
		else 
		{
			if (find(a) == find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}
