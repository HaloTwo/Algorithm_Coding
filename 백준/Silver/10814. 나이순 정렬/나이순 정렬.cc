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
    
    // 입력 순서도 저장 {번호, {순서, 이름}}
    vector<pair<int, pair<int,string>>> members;
    
    for(int i = 0; i < N; i++)
    {
        int M;
        string name;
        cin >> M >> name;
        members.push_back({M, {i, name}});  // 순서 i도 저장
    }
    
    // 번호가 같으면 입력 순서로 정렬
    sort(members.begin(), members.end(), 
        [](const auto& a, const auto& b) {
            if(a.first == b.first)  // 번호가 같으면
                return a.second.first < b.second.first;  // 순서로 비교
            return a.first < b.first;  // 번호로 비교
    });
    
    for(auto& member : members)
    {
        cout << member.first << " " << member.second.second << "\n";
    }
    
    return 0;
}