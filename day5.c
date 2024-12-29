#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <time.h>

typedef struct node
{
    int x;
    struct node *next;
}node;

node *table[100];

void parse(char *str)
{
    int x = (str[0] - '0') * 10 + (str[1] - '0');
    int y = (str[3] - '0') * 10 + (str[4] - '0');
    
    node *n = malloc(sizeof(node));
    n -> x = y;
    n -> next = table[x];
    table[x] = n;
}

void freeList(node *list)
{
    node *prev = list;
    while (list)
    {
        list = list -> next;
        free(prev);
        prev = list;
    }
}

void freeTable(void)
{
    for (int i = 0; i < 100; i++)
    {
        freeList(table[i]);
        table[i] = NULL;
    }
}

int length(char *str)
{
    int len = 1;
    while (*str)
        len += *str++ == ',';
    return len;
}

void update(char *str, int *pages, int len)
{
    for (int i = 0; i < len; i++)
    {
        pages[i] = 0;
        pages[i] += (*str++ - '0') * 10;
        pages[i] += (*str++ - '0');
        str++;
    }
}

//check that y is in table[x]
int in(int x, int y)
{
    node *list = table[x];
    while (list)
    {
        if (list -> x == y)
            return 1;
        list = list -> next;
    }
    return 0;
}

int valid(int *pages, int len)
{
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (!in(pages[i], pages[j]))
                return 0;
    return 1;
}

int fix(int *pages, int len)
{
    int mid = len >> 1;
    int middle = 0;

    for (int i = 0; i < len; i++)
    {
        int count = 0;
        for (int j = 0; j < len; j++)
            count += in(pages[i], pages[j]);
        if (count == mid)
            return pages[i];
    }
    return 0;
}

void part1(void)
{
    FILE *in = fopen("inputs/24/day5.txt", "r");
    char buffer[100];
    int ans = 0;

    for (int i = 0; i < 1176; i++)
    {
        fgets(buffer, 100, in);
        parse(buffer);
    }
    fgets(buffer, 2, in);

    while (fgets(buffer, 100, in))
    {
        int len = length(buffer);
        int pages[len];
        update(buffer, pages, len);
        if (valid(pages, len))
            ans += pages[len >> 1];
    }

    printf("%i\n", ans);
    freeTable();
    fclose(in);
}

void part2(void)
{
    FILE *in = fopen("inputs/24/day5.txt", "r");
    char buffer[100];
    int ans = 0;

    for (int i = 0; i < 1176; i++)
    {
        fgets(buffer, 100, in);
        parse(buffer);
    }
    fgets(buffer, 2, in);

    while (fgets(buffer, 100, in))
    {
        int len = length(buffer);
        int pages[len];
        update(buffer, pages, len);
        if (!valid(pages, len))
            ans += fix(pages, len);
    }

    printf("%i\n", ans);
    freeTable();
    fclose(in);
}

int main(void)
{   
    clock_t begin = clock();
    part1();
    part2();
    printf("%f\n", (float)(clock() - begin) / CLOCKS_PER_SEC);
}
