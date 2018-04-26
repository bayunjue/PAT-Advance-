#include <stdio.h>
#include <stdbool.h>

#define NON_ZERO(a) a>=0.1 || a<=-0.1
#define ZERO(a) a>=-0.1 && a<=0.1

int main()
{
    int nomial_num, total_nomial_num = 0;
    float nomial[1001] = {0};

    /* first line */
    scanf("%d", &nomial_num);
    for(int i = 0; i < nomial_num; ++i) {
        int coefficient;
        scanf("%d", &coefficient);
        scanf("%f", nomial+coefficient);
        if(NON_ZERO(nomial[coefficient])) total_nomial_num++;
    }

    /* second line */
    scanf("%d", &nomial_num);
    for(int i = 0; i < nomial_num; ++i) {
        int coefficient;
        float second_value;
        scanf("%d", &coefficient);
        scanf("%f", &second_value);
        if(ZERO(nomial[coefficient])) {
            nomial[coefficient] += second_value;
            if(NON_ZERO(nomial[coefficient]))
                total_nomial_num++;
            else
                nomial[coefficient] = 0;
        } else {
            nomial[coefficient] += second_value;
            if(ZERO(nomial[coefficient])) {
                total_nomial_num--;
                nomial[coefficient] = 0;
            }
        }
    }

    printf("%d", total_nomial_num);
    for(int i = 1000; i >= 0; --i) {
        if(nomial[i] != 0)
            printf(" %d %.1lf", i, nomial[i]);
    }
    printf("\n");
}
