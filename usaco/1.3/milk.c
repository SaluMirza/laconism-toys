/*
ID: laconis1
PROG: milk
LANG: C
TASK: test
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct milk{
    int price;
    int amount;
};

int cmp(const void *a, const void *b);

int main()
{
    FILE *fin  = fopen ("milk.in", "r");
    FILE *fout = fopen ("milk.out", "w");

    struct milk farmers[5000];
    int am,n,cost = 0;
    int i;

    fscanf (fin, "%d%d",&am,&n);

    for (i = 0; i < n; i++)
    {
        fscanf (fin, "%d%d", &farmers[i].price, &farmers[i].amount);
    }

    qsort (farmers,n,sizeof(struct milk),cmp);

    i = 0;
    while (1)
    {
        if (farmers[i].amount < am)
        {
            cost += farmers[i].amount * farmers[i].price;
            am -= farmers[i].amount;
        }
        else
        {
            cost += farmers[i].price * am;
            fprintf (fout, "%d\n", cost);
            return 0;
        }
        i++;
    }

    fclose (fin);
    fclose (fout);

    return 0;
}

int cmp(const void *a, const void *b)
{
    if (((struct milk *)(a))->price > ((struct milk *)(b))->price)
    {
        return 1;
    }
    else return -1;
}
