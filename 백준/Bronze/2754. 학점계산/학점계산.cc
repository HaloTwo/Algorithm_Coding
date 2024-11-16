#include <bits/stdc++.h>
using namespace std;

int main() {
    string grade;
    cin >> grade;
    
    double score = 0.0;
    
    // 첫 번째 문자로 기본 점수 결정
    if(grade[0] == 'A') score = 4.0;
    else if(grade[0] == 'B') score = 3.0;
    else if(grade[0] == 'C') score = 2.0;
    else if(grade[0] == 'D') score = 1.0;
    else if(grade[0] == 'F') {
        cout << "0.0";
        return 0;
    }
    
    // 두 번째 문자로 +/- 처리
    if(grade[1] == '+') score += 0.3;
    else if(grade[1] == '-') score -= 0.3;
    
    // 소수점 한 자리까지 출력
    cout << fixed;
    cout.precision(1);
    cout << score;
    
    return 0;
}