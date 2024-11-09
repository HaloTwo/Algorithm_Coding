#include <iostream>
#include <algorithm>  
#include <vector>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N = 0, M = 0;
    cin >> N >> M;

    vector<long> sum(N + 1);
    sum[0] = 0;

    int input = 0;

    for (int i = 1; i <= N; i++) 
    {
        std::cin >> input;
        sum[i] = input + sum[i - 1];
    }

    int start = 0, end = 0;
    for (int i = 0; i < M; i++) 
    {
        std::cin >> start >> end;
        std::cout << sum[end] - sum[start - 1] << "\n";
    }

    return 0;
}