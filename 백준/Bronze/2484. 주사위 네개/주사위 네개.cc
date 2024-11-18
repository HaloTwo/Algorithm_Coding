#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n, x;
    int maxReward = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vector<int> num(7);

        for (int j = 0; j < 4; j++)
        {
            cin >> x;
            num[x]++;
        }

        // 가장 많이 나온 눈의 개수와 그 숫자 찾기
        int maxCount = 0;
        int maxNum = 0;
        for (int j = 1; j <= 6; j++)
        {
            if (maxCount <= num[j]) 
            {
                maxCount = num[j];
                maxNum = j;
            }
        }

        int reward = 0;
        // 같은 눈 4개
        if (maxCount == 4) 
        {
            reward = 50000 + maxNum * 5000;
        }
        // 같은 눈 3개
        else if (maxCount == 3) 
        {
            reward = 10000 + maxNum * 1000;
        }
        // 같은 눈 2개
        else if (maxCount == 2) 
        {
            bool isTwo = false;
            int sum = 0;
            for (int j = 1; j <= 6; j++) 
            {
                // 같은 눈 2개 + 두 쌍
                if (num[j] == 2) 
                {
                    if (isTwo) 
                    {  
                        reward = 2000 + j * 500 + sum * 500;
                        break;
                    }
                    isTwo = true;
                    sum = j;
                }
            }
            if (!isTwo || reward == 0) 
            {  
                reward = 1000 + sum * 100;
            }
        }
        else 
        {
            for (int j = 6; j >= 1; j--) 
            {
                if (num[j] == 1) 
                {
                    reward = j * 100;
                    break;
                }
            }
        }

        maxReward = max(maxReward, reward);
    }

    cout << maxReward;

    return 0;
}