#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <time.h>

void insert(int list[], int start, int end)
{
    for (int i = start + 1; i <= end; i++)
    {
        int x = list[i];
        int j = i;
        while (j > start)
        {
            if (x < list[j - 1])
            {
                list[j] = list[j - 1];
                j--;
            }
            else
                break;
        }
        list[j] = x;
    }
}

void merge(int list[], int start, int end)
{
    if (end == start)
        return;
    
    int y = end - start;
    if (y < 32)
    {
        insert(list, start, end);
        return;
    }
    int x = y >> 1;
    
    merge(list, start, x + start);
    merge(list, x + 1 + start, end);
    
    int left = 0;
    int right = x + 1;
    int temp[y + 1];
    for (int i = 0; i <= y; i++)
        temp[i] = list[start + i];
    
    for (int i = 0; i <= y; i++)
    {
        if (right <= y && left <= x)
        {
            if (temp[left] >= temp[right])
                list[start + i] = temp[right++];
            else
                list[start + i] = temp[left++];
        }
        else
        {
            if(right <= y)
                list[start + i] = temp[right++];
            else
                list[start + i] = temp[left++];
        }
    }
}

void part1(void)
{
    FILE *in = fopen("day1.txt", "r");

    int x[1000];
    int y[1000];

    char first[8];
    char second[8];

    for (int i = 0; i < 1000; i++)
    {
        fscanf(in, "%s %s", first, second);
        x[i] = atoi(first);
        y[i] = atoi(second);
    }

    merge(x, 0, 999);
    merge(y, 0, 999);

    int ans = 0;
    
    for (int i = 0; i < 1000; i++)
        ans += abs(x[i] - y[i]);
    
    printf("%i\n", ans);

    fclose(in);
}

void part2(void)
{
    FILE *in = fopen("day1.txt", "r");

    int x[1000];
    int y[1000];

    char first[8];
    char second[8];

    for (int i = 0; i < 1000; i++)
    {
        fscanf(in, "%s %s", first, second);
        x[i] = atoi(first);
        y[i] = atoi(second);
    }

    merge(x, 0, 999);
    merge(y, 0, 999);

    int ans = 0;
    int j = 0;

    for (int i = 0; i < 1000; i++)
    {
        int a = x[i];
        int count = 0;
        for (; j < 1000; j++)
        {
            if (y[j] == a)
                count++;
            if (y[j] > a)
                break;
        }
        ans += a * count;
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

