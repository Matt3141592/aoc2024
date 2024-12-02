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

    if (*str == '\n')
        return 0;

    while (*str != ' ' && *str != '\n')
    {
        x *= 10;
        x += *str - '0';
        *str++ = ' ';
    }
    return x;
}

int increasing(int *nums, int len)
{
    for (int i = 0; i < len - 1; i++)
        if (nums[i + 1] - nums[i] > 3 || nums[i + 1] - nums[i] <= 0)
            return 0;
    return 1;
}

int decreasing(int *nums, int len)
{
    for (int i = 0; i < len - 1; i++)
        if (nums[i] - nums[i + 1] > 3 || nums[i] - nums[i + 1] <= 0)
            return 0;
    return 1;
}

int *my_remove(int *nums, int len, int x)
{
    int *new = malloc(sizeof(int) * (len - 1));
    int counter = 0;

    for (int i = 0; i < len; i++)
    {
        if (i == x)
            continue;
        new[counter++] = nums[i];
    }
    return new;
}

int *toArray(char *buffer, int *count)
{
    int x = 0;
    while (buffer[x])
        if (buffer[x++] == ' ')
            (*count)++;

    int *nums = malloc(*count * sizeof(int));

    for (int j = 0; j < *count; j++)
        nums[j] = getnum(buffer);
    return nums;
}

void part1(void)
{
    FILE *in = fopen("day2.txt", "r");

    char buffer[50];
    int ans = 0;

    for (int i = 0; i < 1000; i++)
    {
        fgets(buffer, 50, in);
        
        int count = 1;
        int *nums = toArray(buffer, &count);

        ans += increasing(nums, count);
        ans += decreasing(nums, count);
    }

    printf("%i\n", ans);
    fclose(in);
}

void part2(void)
{
    FILE *in = fopen("day2.txt", "r");

    char buffer[50];
    int ans = 0;

    for (int i = 0; i < 1000; i++)
    {
        fgets(buffer, 50, in);

        int count = 1;
        int *nums = toArray(buffer, &count);

        for (int j = 0; j < count; j++)
        {
            int *removed = my_remove(nums, count, j);

            if (increasing(removed, count - 1) || decreasing(removed, count - 1))
            {
                ans++;
                free(removed);
                break;
            }
            free(removed);
        }

        free(nums);
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

