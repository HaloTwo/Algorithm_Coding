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


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int connect;
			cin >> connect;
	
			if (connect == 1)
			{
				union_set(i,j);
			}

		}
	}

	int plan[1001];
	for (int i = 0; i < m; i++) cin >> plan[i];
	
	int root = find(plan[0]);
	bool possible = true;

	for (int i = 1; i < m; i++) 
	{
		if (find(plan[i]) != root) 
		{
			possible = false;
			break;
		}
	}

	cout << (possible ? "YES" : "NO") << '\n';

	return 0;
}
