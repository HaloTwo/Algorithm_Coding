#include <stdio.h>

int main() {
    int n;
    int count = 0;

    scanf("%d", &n);
    
    count = n / 5 + n / 25 + n /125;
    

    printf("%d", count);

    return 0;
}