#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <time.h>

int addRow(char *row, char *str, int *x)
{
    int i = 0;
    int found = 0;
    while (*str)
    {
        if (*str == '.')
            row[i++] = 1;
        if (*str == '#')
            row[i++] = '#';
        if (*str == '^')
        {
            *x = i;
            row[i++] = 0;
            found = 1;
        }
        str++;
    }
    return found;
}

void parse(char grid[130][132], FILE *in, int *x, int *y)
{
    char buffer[132];
    int i = 0;
    while (fgets(buffer, 132, in))
        if(addRow(grid[i++], buffer, x))
            *y = i;
}

int wall(int x, int y, char grid[130][132])
{
    if (grid[y][x] == '#')
        return 1;
    return 0;
}

void part1(void)
{
    FILE *in = fopen("inputs/24/day6.txt", "r");
    char grid[130][132];
    for (int i = 0; i < 130; i++)
        for (int j = 0; j < 132; j++)
            grid[i][j] = 0;

    int x = 0, y = 0;
    int up = 1, down = 0, left = 0, right = 0;
    int ans = 1;

    parse(grid, in, &x, &y);
    while (x >= 0 && x < 130 && y >= 0 && y < 130)
    {    
        while (wall(x + right - left, y - up + down, grid))
        {
            if (up)
            {
                up = 0;
                right = 1;
            }
            else if (right)
            {
                right = 0;
                down = 1;
            }
            else if (down)
            {
                down = 0;
                left = 1;
            }
            else if (left)
            {
                left = 0;
                up = 1;
            }
        }
        x += right - left;
        y += down - up;
        ans += grid[y][x];
        grid[y][x] = 0;
    }

    printf("%i\n", ans);
    fclose(in);
}

void part2(void)
{
    FILE *in = fopen("inputs/24/day6.txt", "r");
    char grid[130][132];
    for (int i = 0; i < 130; i++)
        for (int j = 0; j < 132; j++)
            grid[i][j] = 0;

    int x = 0, y = 0;
    int up = 1, down = 0, left = 0, right = 0;
    int ans = 1;

    parse(grid, in, &x, &y);

    int startX = x;
    int startY = y;
    
    while (x >= 0 && x < 130 && y >= 0 && y < 130)
    {    
        while (wall(x + right - left, y - up + down, grid))
        {
            if (up)
            {
                up = 0;
                right = 1;
            }
            else if (right)
            {
                right = 0;
                down = 1;
            }
            else if (down)
            {
                down = 0;
                left = 1;
            }
            else if (left)
            {
                left = 0;
                up = 1;
            }
        }
        x += right - left;
        y += down - up;
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

