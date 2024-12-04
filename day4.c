#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <time.h>

int xmas(char *str)
{
    if (*str++ == 'X')
        if (*str++ == 'M')
            if (*str++ == 'A')
                if (*str++ == 'S')
                    return 1;
    return 0;
}

int samx(char *str)
{
    if (*str++ == 'S')
        if (*str++ == 'A')
            if (*str++ == 'M')
                if (*str == 'X')
                    return 1;
    return 0;
}

int mas(char *str)
{
    if (*str++ == 'M')
        if (*str++ == 'A')
            if (*str == 'S')
                return 1;
    return 0;
}

int sam(char *str)
{
    if (*str++ == 'S')
        if (*str++ == 'A')
            if (*str == 'M')
                return 1;
    return 0;
}

void part1(void)
{
    FILE *in = fopen("inputs/day4.txt", "r");

    char grid[140][142];
    char buffer[142];
    int ans = 0;

    for (int i = 0; i < 140; i++)
    {
        fgets(buffer, 142, in);
        strcpy(grid[i], buffer);
        // printf("%s", grid[i]);
    }

    char str[4];
    for (int i = 0; i < 140; i++)
        for (int j = 0; j < 137; j++)
        {
            str[0] = grid[i][j];
            str[1] = grid[i][j + 1];
            str[2] = grid[i][j + 2];
            str[3] = grid[i][j + 3];
            ans += xmas(str) + samx(str);
        }
    for (int i = 0; i < 137; i++)
        for (int j = 0; j < 140; j++)
        {
            str[0] = grid[i][j];
            str[1] = grid[i + 1][j];
            str[2] = grid[i + 2][j];
            str[3] = grid[i + 3][j];
            ans += xmas(str) + samx(str);
        }
    for (int i = 0; i < 137; i++)
        for (int j = 0; j < 137; j++)
        {
            str[0] = grid[i][j];
            str[1] = grid[i + 1][j + 1];
            str[2] = grid[i + 2][j + 2];
            str[3] = grid[i + 3][j + 3];
            ans += xmas(str) + samx(str);
        }
    for (int i = 0; i < 137; i++)
        for (int j = 3; j < 140; j++)
        {
            str[0] = grid[i][j];
            str[1] = grid[i + 1][j - 1];
            str[2] = grid[i + 2][j - 2];
            str[3] = grid[i + 3][j - 3];
            ans += xmas(str) + samx(str);
        }
    

    printf("%i\n", ans);
    fclose(in);
}

void part2(void)
{
    FILE *in = fopen("inputs/day4.txt", "r");

    char grid[140][142];
    char buffer[142];
    int ans = 0;

    for (int i = 0; i < 140; i++)
    {
        fgets(buffer, 142, in);
        strcpy(grid[i], buffer);
        // printf("%s", grid[i]);
    }

    char str1[3];
    char str2[3];

    for (int i = 1; i < 139; i++)
        for (int j = 1; j < 139; j++)
        {
            str1[0] = grid[i - 1][j - 1];
            str1[1] = grid[i][j];
            str1[2] = grid[i + 1][j + 1];

            str2[0] = grid[i + 1][j - 1];
            str2[1] = grid[i][j];
            str2[2] = grid[i - 1][j + 1];

            ans += (mas(str1) + sam(str1) + mas(str2) + sam(str2)) >> 1;
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
