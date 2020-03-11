/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_t.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 11:19:16 by ibotnaru          #+#    #+#             */
/*   Updated: 2020/02/16 00:03:52 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_ls.h"
/*
void    string_swap(char **str1, char **str2)
{
	// printf("1 = %s\n2 = %s\n\n", *str1, *str2);
    char *tmp;

    tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;
	// printf("1 = %s\n2 = %s\n\n", *str1, *str2);
}
*/
/* This function sorts the files by last modification date. 
    Flag -t handling */
/*
void    print_arr(char **str, int size)
{
    for (int i = 0; i < size; i++)
        printf("[%d] = %s\n", i, str[i]);
}

char   **mtime_sort(char strings_arr[][MAX_LEN], int size_arr)
{
    struct tm time_1;
    struct tm time_2;
    struct stat fileStat;
	char	**new_arr;
    int i = 0;
    int j = 0;

	new_arr = (char **)malloc(sizeof(char *) * size_arr);
	while (i < size_arr)
	{
		new_arr[i] = strings_arr[i];
		i++;
	}
	i = 0;
    print_arr(new_arr, size_arr); //debug
    while (i < size_arr - 1)
    {
        stat(new_arr[i],&fileStat);
        time_1 = *(gmtime(&fileStat.st_ctime));
        j = i + 1;
        while (j < size_arr)
        {
            stat(new_arr[j],&fileStat);
            time_2 = *(gmtime(&fileStat.st_ctime));
            chech_year(time_1, time_2, new_arr[i], new_arr[j], new_arr);
            j++;
        }
        // printf("-----------------------------------------\n");
        // print_arr(strings_arr, size_arr);
        i++;
    }
	// print_arr(new_arr, size_arr); //debug
	// printf("size = %d", size_arr);
	return (new_arr);
}


void    chech_year(struct tm time_1, struct tm time_2, char *str1, char *str2, char **arr)
{
    // printf("\nbefore swap   str1 = %s, str2 = %s\n", str1, str2); //debug
    if (time_1.tm_year == time_2.tm_year)
        chech_month(time_1, time_2, str1, str2, arr);
    else if (time_1.tm_year < time_2.tm_year)
    {    string_swap(&str1, &str2);
    //  printf("\nafter swap   str1 = %s, str2 = %s\n", str1, str2); //debug
	// print_arr(arr, 16); //debug
    }
}

void    chech_month(struct tm time_1, struct tm time_2, char *str1, char *str2, char **arr)
{
    // printf("\nbefore swap   str1 = %s, str2 = %s\n", str1, str2); //debug
    if (time_1.tm_mon == time_2.tm_mon)
        chech_day(time_1, time_2, str1, str2, arr);
    else if (time_1.tm_mon < time_2.tm_mon)
    {    string_swap(&str1, &str2);
    // printf("\nafter swap    str1 = %s, str2 = %s\n", str1, str2); //debug
	// print_arr(arr, 16); //debug
    }
}

void    chech_day(struct tm time_1, struct tm time_2, char *str1, char *str2, char **arr)
{
    // printf("\nbefore swap   str1 = %s, str2 = %s\n", str1, str2); //debug
    if (time_1.tm_mday == time_2.tm_mday)
        chech_hour(time_1, time_2, str1, str2, arr);
    else if (time_1.tm_mday < time_2.tm_mday)
    {    string_swap(&str1, &str2);
    // printf("\nafter swap    str1 = %s, str2 = %s\n", str1, str2); //debug
	// print_arr(arr, 16); //debug
    }
}

void    chech_hour(struct tm time_1, struct tm time_2, char *str1, char *str2, char **arr)
{
    // printf("\nbefore swap   str1 = %s, str2 = %s\n", str1, str2); //debug
    if (time_1.tm_hour == time_2.tm_hour)
        chech_min(time_1, time_2, str1, str2, arr);
    else if (time_1.tm_hour < time_2.tm_hour)
    {    string_swap(&str1, &str2);
    // printf("\nafter swap    str1 = %s, str2 = %s\n", str1, str2); //debug
	// print_arr(arr, 16); //debug
    }
}

void    chech_min(struct tm time_1, struct tm time_2, char *str1, char *str2, char **arr)
{
    // printf("\nbefore swap   str1 = %s, str2 = %s\n", str1, str2); //debug
    if (time_1.tm_min == time_2.tm_min)
        chech_sec(time_1, time_2, str1, str2);
    else if (time_1.tm_min < time_2.tm_min)
    {    
		printf("min\n");
		
		printf("1 = %s\n2 = %s\n\n", str1, str2);		
		string_swap(&str1, &str2);
		
		printf("1 = %s\n2 = %s\n\n", str1, str2);		


    // printf("\nafter swap    str1 = %s, str2 = %s\n", str1, str2); //debug
	// print_arr(arr, 16); //debug
    }
}

void    chech_sec(struct tm time_1, struct tm time_2, char *str1, char *str2)
{
    // printf("\nbefore swap   str1 = %s, str2 = %s\n", str1, str2); //debug
    if (time_1.tm_sec == time_2.tm_sec)
        printf("Check for micro seconds\n");
    else if (time_1.tm_sec < time_2.tm_sec)
    {    string_swap(&str1, &str2);
    // printf("\nafter swap    str1 = %s, str2 = %s\n", str1, str2); //debug
    }
	
}
*/