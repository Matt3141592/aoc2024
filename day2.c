#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <time.h>

int getnum(char *str)
{
    int x = 0;
    while (*str == ' ')
        str++;

    if (*str == '\0')
        return 0;

    while (*str != ' ' || *str != '\0')
    {
        x *= 10;
        x += *str - '0';
        *str++ = ' ';
    }
    return x;
}

int increasing(char *buffer, int x)
{
    int y = getnum(buffer);
    while (y)
    {
        if (y - x > 3 && y - x < 0)
            return 0;
        y = getnum(buffer);
    }
    return 1;
}

int decreasing(char *buffer, int x)
{
    int y = getnum(buffer);
    while (y)
    {
        if (x - y > 3 && x - y < 0)
            return 0;
        y = getnum(buffer);
    }
    return 1;
}

void part1(void)
{
    FILE *in = fopen("day2.txt", "r");

    char buffer[50];
    int ans = 0;

    for (int i = 0; i < 1000; i++)
    {
        fgets(buffer, 50, in);

        int a = getnum(buffer);
        while (a)
        {
            printf("%i", a);
            a = getnum(buffer);
        }
        int x = getnum(buffer);
        int y = getnum(buffer);

        if (x > y)
            if (x - y < 3 && x - y > 0)
                ans += decreasing(buffer, y);
        
        if (x < y)
            if (y - x < 3 && y - x > 0)
                ans += increasing(buffer, y);
    }

    printf("%i\n", ans);
    fclose(in);
}

void part2(void)
{
    FILE *in = fopen("day2.txt", "r");

    fclose(in);
}

int main(void)
{   
    clock_t begin = clock();
    part1();
    part2();
    printf("%f\n", (float)(clock() - begin) / CLOCKS_PER_SEC);
}

