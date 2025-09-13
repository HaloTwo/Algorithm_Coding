#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int n) 
{
    if (n < 2) return false;
    
    for (int i = 2; i * i <= n; i++) 
    {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(string numbers) 
{
    set<int> candidates;
    
    sort(numbers.begin(), numbers.end());

    bool cont = true;
    
    while (cont) 
    {
        string temp = "";
        for (int i = 0; i < numbers.size(); i++) 
        {
            temp += numbers[i];
            int num = stoi(temp);
            candidates.insert(num);
        }
        cont = next_permutation(numbers.begin(), numbers.end());
    }

    int answer = 0;
    for (int num : candidates) 
    {
        if (isPrime(num)) answer++;
    }

    return answer;
}
