#include <stdio.h>

void print_dollars(int numDollers)
{
    for (int i = 0; i < numDollers; i++)
    {
        printf("$");
    }
}

void print_dollar_lines(int numLines, int numDollers)
{
    for (int i = 0; i < numLines; i++)
    {
        print_dollars(numDollers);
        printf("\n");
    }
    
}

int main(int argc, char const *argv[])
{
    int numLines = 3;   // 行数
    int numDollers = 7; // 1行の$数
    print_dollar_lines(numLines, numDollers);

    return 0;
}
