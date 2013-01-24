/*
ID: laconis1
PROG: ride
LANG: C
TASK: test
*/
#include <stdio.h>

int main()
{
	
	int c_r,g_r;
	int product = 1;
	char in[100];
	char *p;

	FILE *fin  = fopen ("ride.in", "r");
	FILE *fout = fopen ("ride.out", "w");

	fscanf (fin, "%s", in);	/* the two input integers */

	for(p = &in; *p != '\0'; p++ )
	{
		product *= ((int)(*p) - 64);
	}

	c_r = product % 47;
	product = 1;
	fscanf (fin, "%s", in);

	for(p = &in; *p != '\0'; p++ )
	{
		product *= ((int)(*p) - 64);
	}

	g_r = product % 47;

	if (g_r == c_r)
		fprintf (fout, "%s", "GO\n");
	else fprintf (fout, "%s", "STAY\n");

	return 0;
}
