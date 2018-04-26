#include <stdio.h>

void func_print(int value)
{
    if(value/1000 > 0) {
        func_print(value/1000);
        printf(",%03d", value%1000);
    } else {
        printf("%d", value);
    }
}

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);
    a += b;
    b = a>0?a:-a;
    if(a < 0) printf("-");
    func_print(b);
    printf("\n");
}
