/*
ID: laconis1
PROG: palsquare
LANG: C
TASK: test
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char pal[20];

int convert (int num, int base)
{
    int mod,length = 0,i = 0;
    char pal_tmp[20];

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
        strcpy ((char *)pal, (char *)pal_tmp);
        return 1;
    }
    return 0;
}

int main()
{
    FILE *fin  = fopen ("palsquare.in", "r");
    FILE *fout = fopen ("palsquare.out", "w");

    int base,i,j,n,mod;
    int num[300];
    int length = 0;
    char num_char[20];

    fscanf (fin, "%d", &base);

    for (i = 0; i < 300; i++)
    {
        num[i] = (i+1) * (i+1);
    }

    for (i = 0; i < 300; i++)
    {
        if (convert(num[i], base))
        {
            n = i+1;
            while (n != 0)
            {
                mod = n % base;
                n -= mod;
                n /= base;
                if (mod < 10)
                {
                    num_char[length] = '0' + mod;
                }
                else
                {
                    num_char[length] = 'A' + mod - 10;
                }
                length++;
            }
            for (j = 0; j < length; j++)
            {
                fprintf (fout, "%c", num_char[length-j-1]);
            }
            fprintf (fout, " %s\n",(char *)pal);
            length = 0;
        }
    }

    return 0;
}
