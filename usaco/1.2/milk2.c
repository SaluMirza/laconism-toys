/*
ID: laconis1
PROG: milk2
LANG: C
TASK: test
*/
#include <stdio.h>
#include <stdlib.h>

struct time
{
    int start;
    int end;
};

struct time milking[10000];

int comp(const void *a, const void *b)
{
    return ((struct time *)(a))->start - ((struct time *)(b))->start;
}

int main()
{
    FILE *fin  = fopen ("milk2.in", "r");
    FILE *fout = fopen ("milk2.out", "w");

    int n,i,last_max = 0, idle_max = 0;
    struct time last;

    /* input */
    fscanf (fin, "%d", &n);
    for (i = 0; i < n; i++)
    {
        fscanf (fin, "%d%d", &(milking[i].start), &(milking[i].end));
    }

    /* computer */
    qsort (milking, n, sizeof(struct time), comp);
    i = 0;
    if (n == 1)
    {
        fprintf (fout, "%d ", milking[0].end-milking[0].start);
        fprintf (fout, "0\n");
        return 0;
    }
    last_max = milking[0].end - milking[0].start;
    while (i+1 < n)
    {
        last.start = milking[i].start;
        last.end   = milking[i].end;
        while((i+1 < n) && 
              (last.end >= milking[i+1].start) && 
              (milking[i+1].start >= last.start) )
        {
            //printf ("milk.start=%d milk.end=%d\n",milking[i].start,milking[i].end);
            if(milking[i+1].end > last.end)
            {
                last.end = milking[i+1].end;
            }
            i++;
            if ((last.end - last.start) > last_max)
            {
                last_max = last.end - last.start;
            }
        }
        //printf("jump\n");
        if (i+1 < n)
        {
            if (milking[i+1].start - last.end > idle_max)
            {
                idle_max = milking[i+1].start - last.end;
                //printf("update:%d\n",idle_max);
            }
            i++;
        }
    }

    fprintf (fout, "%d %d\n", last_max, idle_max);

    fclose (fin);
    fclose (fout);
    
	return 0;
}
