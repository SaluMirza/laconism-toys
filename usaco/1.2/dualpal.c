/*
ID: laconis1
PROG: dualpal
LANG: C
TASK: test
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert (int num, int base)
{
    int mod,length = 0,i = 0;
    char pal_tmp[40];

    while (num != 0)
    {
        mod = num % base;
        num -= mod;
        num /= base;

        if (mod < 10)
        {
            pal_tmp[i] = '0' + mod;
        }
        else
        {
            pal_tmp[i] = 'A' + mod -10;
        }
        i++;
    }
    pal_tmp[i] = 0;
    i--;
    length = i;
    i = 0;

    while (i <= length)
    {
        if (pal_tmp[i] != pal_tmp[length])
        {
            break;
        }
        i++;
        length--;
    }

    if (pal_tmp[i] == pal_tmp[length])
    {
        return 1;
    }
    return 0;
}

int main()
{
    FILE *fin  = fopen ("dualpal.in", "r");
    FILE *fout = fopen ("dualpal.out", "w");

    int n,s,tmp,i,base;
    int pal_count = 0,times = 0;

    fscanf (fin, "%d%d", &n, &s);

    i = 0;
    tmp = s + 1;
    while (pal_count < n)
    {
        times = 0;
        for (base = 2; base < 11; base++)
        {
            if (convert(s+i+1,base))
            {
                times++;
            }
        }
        if (times >= 2)
        {
            fprintf (fout, "%d\n", s+i+1);
            pal_count++;
        }
        i++;
    }

    fclose (fin);
    fclose (fout);

    return 0;
}
