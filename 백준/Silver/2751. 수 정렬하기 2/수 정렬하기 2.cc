#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    vector<int> num(N);  // N 크기의 vector
    
    for(int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    
    sort(num.begin(), num.end());
    
    for(int i = 0; i < N; i++)
    {
        cout << num[i] << "\n";
    }
    
    return 0;
}