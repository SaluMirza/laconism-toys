/*
ID: laconis1
PROG: friday
LANG: C
TASK: test
*/

#include <stdio.h>

int main()
{
    int n,i,result;
    int year,month,day;
    int times[7];

    FILE *fin  = fopen ("friday.in", "r");
    FILE *fout = fopen ("friday.out", "w");

    for (i = 0; i < 7; i++)
        times[i] = 0; 
    fscanf (fin, "%d", &n);
    day = 0;
    for (i = 0; i < n; i++)
    {
        year = 1900 + i;
        for (month = 0; month < 12; month++)
        {
            day +=13;
            switch(month)
            {
                case 0: break;
                case 1: day += 18;break;
                case 2: {
                            if (year % 4 == 0 && year % 100 != 0)
                            {
                                day += 16;
                            }
                            else if (year % 400 == 0)
                            {
                                day += 16;
                            }
                            else day += 15;
                        }

                        break;
                case 3: day += 18;break;
                case 4: day += 17;break;
                case 5: day += 18;break;
                case 6: day += 17;break;
                case 7: day += 18;break;
                case 8: day += 18;break;
                case 9: day += 17;break;
                case 10: day += 18;break;
                case 11: day += 17;break;
            }
            result = day % 7;
            switch(result)
            {
                case 0: times[6] += 1;break;
                case 1: times[0] += 1;break;
                case 2: times[1] += 1;break;
                case 3: times[2] += 1;break;
                case 4: times[3] += 1;break;
                case 5: times[4] += 1;break;
                case 6: times[5] += 1;break;
            }
        }
        day += 18;
    }
    fprintf (fout, "%d %d %d %d %d %d %d\n", times[5], times[6], times[0], times[1], times[2], times[3], times[4]);

    return 0;
}

