#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cin >> target;
    int count = 0;  

    // 방법 1: 투 포인터
    sort(nums.begin(), nums.end());

    int left = 0, right = n - 1;

    while (left < right) 
    {
        int sum = nums[left] + nums[right];
        if (sum == target) 
        {
            count++;
            left++;
            right--;
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }

    cout << count;
    return 0;
}