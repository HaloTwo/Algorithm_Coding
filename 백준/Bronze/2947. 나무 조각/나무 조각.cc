#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> vec(5);
    for (int i = 0; i < 5; i++) 
    {
        cin >> vec[i];
    }

    for (int i = 0; i < 4; i++) 
    {
        bool swapped = false;  

        for (int j = 0; j < 4 - i; j++) 
        {
            if (vec[j] > vec[j + 1]) 
            {  
                swap(vec[j], vec[j + 1]);
                swapped = true;

                for (int k = 0; k < 5; k++) 
                {
                    cout << vec[k] << " ";
                }
                cout << '\n';
            }
        }

        if (!swapped) break;  
    }

    return 0;
}