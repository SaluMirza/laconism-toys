/*
ID: laconis1
PROG: namenum
LANG: C
TASK: test
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int match(int length, int num, char * str)
{
    int i,mul = 1,cmp = 0;
    int map[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};

    for (i = 0; i < length; i++)
    {
        cmp += map[*(str+length-i-1)-'A'] * mul;
        mul *= 10;
    }

    if (num == cmp)
    {
        return 1;
    }
    return 0;
}

int main()
{
    FILE *fin  = fopen ("namenum.in", "r");
    FILE *fout = fopen ("namenum.out", "w");
    FILE *dict = fopen ("dict.txt", "r");

    char in_num[20];
    char word_tmp[20];
    // I used grep and found that 1300 is needed.
    char poss_words_table[1300][20];
    char result[200][20];
    int in_num_len;
    int poss_words_count = 0;
    int i,mul = 1,in_num_int = 0,result_count = 0;

    fscanf (fin, "%s", in_num);
    in_num_len = strlen(in_num);

    while (fscanf (dict, "%s", word_tmp) != EOF)
    {
        if (in_num_len == strlen(word_tmp))
        {
            strcpy ((char *)&poss_words_table[poss_words_count],word_tmp);
            poss_words_count++;
        }
    }

    for (i = 0; i < in_num_len; i++)
    {
        in_num_int += (in_num[in_num_len-i-1] - '0') * mul;
        mul *= 10;
    }

    for (i = 0; i < poss_words_count; i++)
    {
        if (match (in_num_len,in_num_int,(char *)&poss_words_table[i]))
        {
            strcpy ((char *)&result[result_count], (char *)&poss_words_table[i]);
            result_count++;
        }
    }

    if (result_count == 0)
    {
        fprintf (fout, "NONE\n");
        return 0;
    }

    for (i = 0; i < result_count; i++)
    {
        fprintf (fout, "%s\n", (char *)&result[i]);
    }

    return 0;
}
