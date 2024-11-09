#include <iostream>
using namespace std;

void Search(int H, int W, int N)
{
    int floor = N % H;
    if (floor == 0) floor = H; 

    int roomNum = (N - 1) / H + 1;  
    cout << (floor * 100) + roomNum << '\n';  
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int C, H, W, N;
    cin >> C;

    for (int i = 0; i < C; i++)
    {
        cin >> H >> W >> N;
        Search(H, W, N);
    }
    return 0;
}