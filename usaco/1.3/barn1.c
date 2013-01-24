/*
ID: laconis1
PROG: barn1
LANG: C
TASK: test
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp (const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    FILE *fin  = fopen ("barn1.in", "r");
    FILE *fout = fopen ("barn1.out", "w");

    int m,s,c;
    int stall[200];
    int length[200];
    int i;

    fscanf (fin, "%d%d%d", &m,&s,&c);
    for (i = 0; i < c; i++)
    {
        fscanf (fin, "%d", &stall[i]);
    }

    qsort(stall,c,sizeof(int),cmp);

    s -= s-stall[c-1];
    s -= stall[0] - 1;

    for (i = 1; i < c; i++)
    {
        length[i-1] = stall[i] - stall[i-1]-1;
    }

    qsort(length,c-1,sizeof(int),cmp);

    i = 0;
    while (length[c-2-i] != 0 && i < m-1 && i < c-1)
    {
        s -= length[c-2-i];
        i++;
    }

    fprintf (fout, "%d\n",s);

    fclose (fin);
    fclose (fout);

    return 0;
}
