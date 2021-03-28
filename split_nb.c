#include <stdlib.h>
#include <stdio.h>

int     *int_split(int nb, int group_of_three)
{
        int *split;
        int i = 0;
        int multiple = 1;

        split = (int *)malloc(sizeof(split) * 10);
        while (group_of_three > 0)
        {
                split[i] = nb % 1000 * multiple;
                nb /= 1000;
                multiple *= 1000;
                i++;
                group_of_three--;
        }
        return (split);
}

int     whole_int(int nb)
{
        int units[] = {1000, 1000000, 1000000000};
        int i = -1;

        while (nb > 0)
        {
                nb /= 1000;
                i++;
		}
        return (units[i - 1]);
}

int     *final_split(int nb)
{
        int *split;
		int cp_nb;

		cp_nb = nb;
        split = (int *)malloc(sizeof(split) * 10);
        while (nb > 999)
                nb /= 1000;
        split[0] = nb / 100;
		if (nb > 99)
			split[1] = 100;
		if (nb % 100 < 20)
		{
			split[2] = nb % 100;
			return (split);
		}
        split[2] = (nb % 100 / 10 * 10);
        split[3] = (nb % (nb / 10 * 10));
		if (cp_nb > 999)
			split[4] = whole_int(cp_nb);
        return (split);
}

int		check_groups_of_three(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (i < 4)
		return (1);
	if (i > 3 && i < 7)
		return (2);
	if (i > 6 && i < 10)
		return (3);
	return (0);
}

int		check_nb_of_digits(int nb)
{
	while (nb > 999)
		nb /= 1000;
	if (nb % 100 < 20 || nb % 100 % 10 == 0)
		return (3);
	return (4);
}

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int nb;
	int i;
	int j;
	int k;
	int groups_of_three;
	int total_nb;
	int final_tab[20];
	int inter_tab[10];
	int cp_group_3;

	total_nb = 0;
	i = 0;
	inter_tab[0] = 10;
	groups_of_three = check_groups_of_three(argv[1]);
	cp_group_3 = groups_of_three - 1;
	nb = atoi(argv[1]);
	while (0 <= cp_group_3)
	{
		inter_tab[i] = int_split(nb, groups_of_three)[cp_group_3];
		i++;
		cp_group_3--;
	}
	i = 0;
	while (i < groups_of_three)
	{
		total_nb += check_nb_of_digits(inter_tab[i]); 
		i++;
	}
	i = 0;
	j = 0;
	k = 0;
	while (total_nb + 1 >= i)
	{
		final_tab[i] = final_split(inter_tab[j])[k];
		if (k == check_nb_of_digits(inter_tab[j]))
		{
			j++;
			k = -1;
		}
		i++;
		k++;
	}
	for (i = 0; i < 14; i++)
		printf("%d, ", final_tab[i]);
}

/*int     main(void)
{
        int i;
        int j;
		int k;
        int *test = int_split(587334412);
        int final[123]; 
		int *bour1 = final_split(test[2]);
		int *bour2 = final_split(test[1]);
		int *bour3 = final_split(test[0]);
		//int *bour4 = final_split(test[0]);
		i = 0;
		j = 0;
		k = 0;
		*while (i < 3)
		{
			while (j < 10)
			{
				final[j] = final_split(test[i])[k];
				j++;
				k++;
			}
			j -= 1;
			k = 0;
			i++;
		}
		
        printf("%d, ", bour1[0]);
        printf("%d, ", bour1[1]);
        printf("%d, ", bour1[2]);
		printf("%d, ", bour1[3]);
		printf("%d, ", bour1[4]);
        printf("%d, ", bour2[0]);
		printf("%d, ", bour2[1]);
		printf("%d, ", bour2[2]);
		printf("%d, ", bour2[3]);
		printf("%d, ", bour2[4]);
		//printf("%lu, ", bour2[4]);
		printf("%d, ", bour3[0]);
		printf("%d, ", bour3[1]);
		printf("%d, ", bour3[2]);
		printf("%d, ", bour3[3]);
		printf("%d, ", bour3[4]);

		//printf("%lu, ", bour4[0]);
		//printf("%lu, ", bour4[1]);
		//printf("%lu, ", bour4[2]);
		//printf("%lu, ", bour4[3]);
		printf("\n");
		printf("%d, ", test[0]);
		printf("%d, ", test[1]);
		printf("%d, ", test[2]);
}
*/

