#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int A, B, C, AB;

    string strA, strB;

    cin >> A;
    cin >> B;
    cin >> C;

    strA = to_string(A);
    strB = to_string(B);
    AB = stoi(strA + strB);

    cout << A + B - C << "\n" << AB - C;
  
    return 0;
}