#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

    cout << "int a;\n";

    for (int i = 1; i <= n; i++) 
    {
        cout << "int ";
        for (int j = 0; j < i; j++) 
        {
            cout << "*";
        }
        cout << "ptr";

        if (i != 1) cout << i;
        cout << " = ";

        if (i == 1) cout << "&a;\n";
        else 
        {
            cout << "&ptr";
            if (i == 2) cout << ";\n";
            else cout << i - 1 << ";\n";
        }
    }

	return 0;
}