#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, d;
        cin >> n >> d;

        vector<vector<int>> board(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> board[i][j];

        int step = ((d / 45) % 8 + 8) % 8;
        int mid = n / 2;

        for (int s = 0; s < step; s++) {
            vector<vector<int>> temp = board;
            for (int i = 0; i < n; i++) {
                temp[i][mid] = board[i][i];
                temp[i][n - 1 - i] = board[i][mid];
                temp[mid][n - 1 - i] = board[i][n - 1 - i];
                temp[i][i] = board[mid][i];
            }
            board = temp;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}
