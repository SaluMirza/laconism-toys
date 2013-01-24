/*
ID: laconis1
PROG: transform
LANG: C
TASK: test
*/
#include <stdio.h>
#include <stdlib.h>

#define SQUARE_MAX 10

char in_square[SQUARE_MAX][SQUARE_MAX];
char out_square[SQUARE_MAX][SQUARE_MAX];
char res_square[SQUARE_MAX][SQUARE_MAX];

void rota90(int n);
void rota180(int n);
void rota270(int n);
void reflection(int n);
void combin90(int n);
void combin180(int n);
void combin270(int n);
void nochange(int n);
int compare(int n);

void print(int n)
{
    int i,j;
    printf ("in_square:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf ("%c",in_square[i][j]);
        printf ("\n");
    }
    printf ("out_square:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf ("%c",out_square[i][j]);
        printf ("\n");
    }
    printf ("res_square:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf ("%c",res_square[i][j]);
        printf ("\n");
    }
    printf ("\n");
}

int main()
{
    FILE *fin  = fopen ("transform.in", "r");
    FILE *fout = fopen ("transform.out", "w");

    int n,i,j;

    /* input */
    fscanf (fin, "%d", &n);
    for (i = 0; i < n; i++)
    {
            fscanf (fin, "%s", (char *)&in_square[i]);
    }
    for (i = 0; i< n; i++)
    {
            fscanf (fin, "%s", (char *)&out_square[i]);
    }

    rota90(n);
    if (compare(n))
    {
        fprintf (fout, "1\n");
        return 0;
    }
    rota180(n);
    if (compare(n))
    {
        fprintf (fout, "2\n");
        return 0;
    }
    rota270(n);
    if (compare(n))
    {
        fprintf (fout, "3\n");
        return 0;
    }
    reflection(n);
    if (compare(n))
    {
        fprintf (fout, "4\n");
        return 0;
    }
    combin90(n);
    if (compare(n))
    {
        fprintf (fout, "5\n");
        return 0;
    }
    combin180(n);
    if (compare(n))
    {
        fprintf (fout, "5\n");
        return 0;
    }
    combin270(n);
    if (compare(n))
    {
        fprintf (fout, "5\n");
        return 0;
    }
    nochange(n);
    if (compare(n))
    {
        fprintf (fout, "6\n");
        return 0;
    }

    fprintf (fout, "7\n");

    fclose (fin);
    fclose (fout);

    return 0;
}

void rota90(int n)
{
    int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            res_square[j][n-i-1] = in_square[i][j];
        }
    }
}

void rota180(int n)
{
    int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            res_square[n-i-1][n-j-1] = in_square[i][j];
        }
    }
}

void rota270(int n)
{
    int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            res_square[n-j-1][i] = in_square[i][j];
        }
    }
}

void reflection(int n)
{
   int i,j;
   for (i = 0; i < n; i++)
   {
       for (j = 0; j < n; j++)
       {
           res_square[i][n-j-1] = in_square[i][j];
       }
   }
}

void combin90(int n)
{
   int i,j;
   for (i = 0; i < n; i++)
   {
       for (j = 0; j < n; j++)
       {
           res_square[n-j-1][n-i-1] = in_square[i][j];
       }
   }
}

void combin180(int n)
{
   int i,j;
   for (i = 0; i < n; i++)
   {
       for (j = 0; j < n; j++)
       {
           res_square[n-i-1][j] = in_square[i][j];
       }
   }
}

void combin270(int n)
{
   int i,j;
   for (i = 0; i < n; i++)
   {
       for (j = 0; j < n; j++)
       {
           res_square[j][i] = in_square[i][j];
       }
   }
}

void nochange(int n)
{
   int i,j;
   for (i = 0; i < n; i++)
   {
       for (j = 0; j < n; j++)
       {
           res_square[i][j] = in_square[i][j];
       }
   }
}

int compare(int n)
{
    int i = 0,j = 0;

    while (res_square[i][j] == out_square[i][j])
    {
        if (j == n-1)
        {
            if (i == n-1)
                break;
            i++;
            j = 0;
        }
        else
        {
            j++;
        }
    }

    if (i == n-1 && j==n-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
