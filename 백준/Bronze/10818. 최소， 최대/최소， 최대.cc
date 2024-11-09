#include<stdio.h>
int main()
{
    long long int n;  
    long long int m;  
    long long int maxNum = -1000000000000;  
    long long int minNum = 1000000000000;   

    scanf("%lld", &n);  
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &m);  
        if (maxNum < m) maxNum = m;
        if (minNum > m) minNum = m;
    }

    printf("%lld %lld", minNum, maxNum); 
    return 0;
}