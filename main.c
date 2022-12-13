#include <stdio.h>
#include <stdlib.h>

int loadInputFile();
int nextLine(char *dst);

#define CICLE_PASS_CHECK()    \
    {                         \
        cicle++;              \
        if (cicle == target)  \
        {                     \
            /*printf("%d: %d\n", cicle, x);*/\
            target += 40;     \
            sum += cicle * x; \
        }                     \
    }

int main()
{
    char line[16];
    int x = 1;
    int cicle = 0;
    int target = 20;
    int sum = 0;

    if (loadInputFile() < 0)
    {
        fprintf(stderr, "Can't open: input.txt\n");
        return 1;
    }

    int n;
    while (nextLine(line) > 0)
    {
        CICLE_PASS_CHECK();
        if (sscanf(line, "%*s %d", &n) == 1)
        {
            CICLE_PASS_CHECK();
            x+=n;
        }
    }
    printf("%d\n", sum);
}

#define BUFSIZE 1024

char fileBuf[BUFSIZE];
char *pbuf = fileBuf;
char *pbufend = fileBuf;

int loadInputFile()
{
    FILE *pf = fopen("input.txt", "r");
    if (!pf)
        return -1;
    pbuf = fileBuf;
    pbufend = fileBuf + fread(fileBuf, 1, BUFSIZE, pf);
    fclose(pf);

    return 0;
}

inline int nextLine(char *dst)
{
    char c;
    char *orig = dst;

    // read line:
    while (pbuf < pbufend && (c = *(pbuf++)) != '\n')
    {
        *(dst++) = c;
    }
    *dst = '\0';
    // return line length
    return dst - orig;
}