//Author Zachary Stephens
#include <stdio.h>
#include <math.h>
#include "float.h"

int main()
{
    float f;

    while (f != 0)
    {
        scanf("%f", &f);
        if (f == 0)
            break;
        float f1 = get_s(f) * exp2f( get_E(f) ) * (get_M(f) == 0 ? 1 : get_M(f));
        printf("%d %d %0.50f\n%0.50f\n", get_s(f), get_E(f), get_M(f), f1);
    }

    return 0;
}