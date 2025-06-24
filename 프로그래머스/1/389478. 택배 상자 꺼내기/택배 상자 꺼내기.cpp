#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) 
{
    int count = 1; // 자기 자신 포함

    int idx = num - 1;                  // num의 실제 인덱스
    int floor = idx / w;                // 몇 번째 층인지 (0-indexed)
    int col;

    if (floor % 2 == 0) {
        col = idx % w;                  // 왼→오 방향
    } else {
        col = w - 1 - (idx % w);        // 오→왼 방향
    }
    
    for (int f = floor + 1; f * w < n + w; ++f) 
    {
        int upperIdx;
        
        if (f % 2 == 0) 
        {
            upperIdx = f * w + col;
        } else 
        {
            upperIdx = f * w + (w - 1 - col);
        }

        if (upperIdx < n) count++;
        

    }
   
    return count;
}
