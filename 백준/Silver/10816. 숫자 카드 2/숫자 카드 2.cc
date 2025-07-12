#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    unordered_map<int, int> countMap;
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> M;
        auto it = countMap.find(M);
        if(it != countMap.end())
        {
            it->second++;  // 있으면 증가
        }
        else
        {
            countMap[M] = 1;  // 없으면 1로 설정
        }
    }
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> M;
        auto it = countMap.find(M);
        cout << (it != countMap.end() ? it->second : 0) << "\n";
    }
    
    return 0;
}