/*
ID: laconis1
PROG: gift1
LANG: C
TASK: test
*/
#include <stdio.h>
#include <string.h>

struct person{
	char name[15];
	int money;
};

int main()
{
	struct person p[11];

    FILE *fin  = fopen ("gift1.in", "r");
    FILE *fout = fopen ("gift1.out", "w");

	int n,i,j,friendi,give,count;
	int num;
	char namebuf[15];
	fscanf (fin, "%d", &n);

	for(i = 0; i < n; i++)
	{
		fscanf (fin, "%s", p[i].name);
		p[i].money = 0;
	}

	for(i = 0; i < n; i++)
	{
		count = 0;

		fscanf (fin, "%s", namebuf);
		while(strcmp(namebuf,p[count].name))
			count++;
		fscanf (fin, "%d%d", &give, &num);
		if (give != 0)
		{
			give -= give % num;
			p[count].money -= give;
			give /= num;
		
			for (j = 0; j < num; j++)
			{
				count = 0;

				fscanf(fin, "%s", namebuf);
				while(strcmp(namebuf,p[count].name))
					count++;
				p[count].money += give;
			}
		}
	}

	for (i = 0; i <n; i++)
	{
		fprintf(fout, "%s %d\n", p[i].name, p[i].money);
	}

    fclose (fin);
    fclose (fout);

	return 0;
}
