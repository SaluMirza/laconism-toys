/*
ID: laconis1
PROG: calfflac
LANG: C
TASK: test
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fin  = fopen ("calfflac.in", "r");
    FILE *fout = fopen ("calfflac.out", "w");

    fclose (fin);
    fclose (fout);

    return 0;
}
