touch $1.txt
echo "#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <time.h>

void part1(void)
{
    FILE *in = fopen(\"$1.txt\", \"r\");

    fclose(in);
}

void part2(void)
{
    FILE *in = fopen(\"$1.txt\", \"r\");

    fclose(in);
}

int main(void)
{   
    clock_t begin = clock();
    part1();
    part2();
    printf(\"%f\n\", (float)(clock() - begin) / CLOCKS_PER_SEC);
}
" >> "$1.c"

