#include <stdio.h>

// 1. 함수 정의를 먼저
int gcb(int a, int b)
{
    int r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

// 2. main 함수
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int min = gcb(a, b);
    int max = a * b / min;
    printf("%d\n%d", min, max);
    return 0;
}