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

Point multiplyPoints(Point p1, Point p2)
{
    Point p;
    p.y = p1.y * p2.y;
    p.x = p1.x * p2.x;
    return p;
}

int main(void)
{
    Point p1 = initPoint(1, 2);
    Point p2 = initPoint(3, 4);
    Point p = multiplyPoints(p1, p2);
    printf("y = %d, x = %d\n", p.y, p.x);
    
    return 0;
}
