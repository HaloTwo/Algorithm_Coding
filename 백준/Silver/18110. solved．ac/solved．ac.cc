#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    // N이 0일 때 처리 추가
    if(N == 0) {
        cout << "0";
        return 0;
    }
    
    vector<int> score(N);
    for(int i = 0; i < N; i++) {
        cin >> score[i];
    }
    
    sort(score.begin(), score.end());
    
    // 절사할 인원 계산
    int cutPeople = (int)(N * 0.15 + 0.5);  // round 대신 이렇게!
    
    // 평균 계산 시 double로
    double sum = 0;
    for(int i = cutPeople; i < N - cutPeople; i++) {
        sum += score[i];
    }
    
    // 최종 평균 계산
    int result = (int)(sum / (N - cutPeople * 2) + 0.5);
    cout << result;
    
    return 0;
}