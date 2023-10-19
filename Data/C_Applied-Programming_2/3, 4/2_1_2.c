#include <math.h>
#include <stdio.h>

typedef struct
{
    int y;
    int x;
} Point;

Point initPoint(int y, int x)
{
    Point p;
    p.y = y;
    p.x = x;
    return p;
}

double l2norm(Point p_x, Point p_y)
{
    return sqrt(pow(p_x.y - p_y.y, 2) + pow(p_x.x - p_y.x, 2));
}

int main(void)
{
    Point p1 = initPoint(5, 10);
    Point p2 = initPoint(1, 5);
    double d1 = l2norm(p1, p2);
    printf("distance: %f\n", d1);

    Point p3 = initPoint(0, 0);
    Point p4 = initPoint(0, 0);
    double d2 = l2norm(p3, p4);
    printf("distance: %f\n", d2);

    Point p5 = initPoint(-1, 1);
    Point p6 = initPoint(1, -1);
    double d3 = l2norm(p5, p6);
    printf("distance: %f\n", d3);

    return 0;
}
