#include <stdio.h>

void addPoints(int *p1_y, int *p1_x, int *p2_y, int *p2_x)
{
    int y = 0, x = 0;
    y = *p1_y + *p2_y;
    x = *p1_x + *p2_x;
    printf("y = %d, x = %d\n", y, x);
}

int main(void)
{
    int p1_y = 1;
    int p1_x = 2;
    int p2_y = 3;
    int p2_x = 4;
    addPoints(&p1_y, &p1_x, &p2_y, &p2_x);
    return 0;
}
