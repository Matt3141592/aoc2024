#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <time.h>

int mul(char *str)
{
    int x = 0;
    int y = 0;

    if (*str++ == '(')
    {
        while (*str >= '0' && *str <= '9')
        {
            x *= 10;
            x += *str++ - '0';
        }
        if (*str++ == ',')
            while (*str >= '0' && *str <= '9')
            {
                y *= 10;
                y += *str++ - '0';
            }
        if (*str != ')')
            x = 0;
    }


    return x * y;
}

int finder(char *str)
{
    int ans = 0;
    while (*str)
        if (*str++ == 'm')
            if (*str++ == 'u')
                if (*str++ == 'l')
                    ans += mul(str);
    return ans;
}

void enabled(char *str, int *enable)
{
    if (*str++ == 'd')
        if (*str++ == 'o')
        {
            if (*str == 'n')
            {   
                str++;
                if (*str++ == '\'')
                    if (*str++ == 't')
                        if (*str++ == '(')
                            if (*str == ')')
                            {
                                *enable = 0;
                                return;
                            }
            }
            else if(*str++ == '(')
                if (*str == ')')
                    *enable = 1;
        }

    return;
}

int enable = 1;
int enabled_finder(char *str)
{
    int ans = 0;
    
    while (*str)
    {
        enabled(str, &enable);
        if (*str++ == 'm')
            if (*str++ == 'u')
                if (*str++ == 'l')
                    ans += enable * mul(str);
    }
    return ans;
}

void part1(void)
{
    FILE *in = fopen("inputs/day3.txt", "r");

    char buffer[3500];
    int ans = 0;
    for (int i = 0; i < 6; i++)
    {
        fgets(buffer, 3500, in);
        ans += finder(buffer);
    }
    
    printf("%i\n", ans);
    fclose(in);
}

void part2(void)
{
    FILE *in = fopen("inputs/day3.txt", "r");

    char buffer[3500];
    int ans = 0;
    for (int i = 0; i < 6; i++)
    {
        fgets(buffer, 3500, in);
        ans += enabled_finder(buffer);
    }
    
    printf("%i\n", ans);

    fclose(in);
}

int main(void)
{   
    clock_t begin = clock();
    part1();
    part2();
    printf("%f\n", (float)(clock() - begin) / CLOCKS_PER_SEC);
}

