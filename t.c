/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 23:01:33 by ibotnaru          #+#    #+#             */
/*   Updated: 2020/02/16 20:05:09 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    string_swap(char **str1, char **str2)
{
    char *tmp;

    tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;
}

// void    sort_by_day(struct tm time1, struct tm time2, char **str1, char **str2)
// {
//     if (time1.tm_wday < time2.tm_wday)
//         string_swap(&str1, &str2);
// }

// int    sort_by_day(struct tm time1, struct tm time2, char **str1, char **str2)
// {
//     if (time1.tm_wday < time2.tm_wday)
//         return (1);
//     return (0);
// }

char   **mtime_sort(char strings_arr[][MAX_LEN], int size_arr)
{
    struct tm time1;
    struct tm time2;
    struct stat fileStat;
    struct stat fileStat2;
	char	**new_arr;
    int i = 0;
    int j = 0;

	new_arr = (char **)malloc(sizeof(char *) * size_arr);
	while (i < size_arr)
	{
		new_arr[i] = strings_arr[i];
		i++;
	}

    char *t;

    t = ctime(size_arr[i]);
    

    

    // while ( i < size_arr - 1)
    // {
    //     j = i + 1;
    //     stat(new_arr[i],&fileStat);
    //     time1 = *(gmtime(&fileStat.st_mtime));
    //     while (j < size_arr)
    //     {
    //         stat(new_arr[j],&fileStat2);
    //         time2 = *(gmtime(&fileStat2.st_mtime));
    //         sort_by_day(time1, time2, &new_arr[i], &new_arr[j]);
    //         j++;
    //     }
    //     i++;
    // }
    int k = 0;
    while ( k < size_arr)
    {
        printf("%s\n", new_arr[k]);
        k++;
    }
    printf("\n");
	return (new_arr);
}

/*
char   **mtime_sort(char strings_arr[][MAX_LEN], int size_arr)
{
    struct tm time1;
    struct tm time2;
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
    stat(new_arr[i],&fileStat);
    time1 = *(gmtime(&fileStat.st_ctime));
    while (i < size_arr - 1)
    {
        j = i + 1;
        stat(new_arr[j],&fileStat);
        time2 = *(gmtime(&fileStat.st_ctime));
        while (j < size_arr)
        {
            if (time1.tm_year < time2.tm_year)
                string_swap(&new_arr[i], &new_arr[j]);
            else if (time1.tm_year == time2.tm_year)
            {
                if (time1.tm_mon < time2.tm_mon)
                    string_swap(&new_arr[i], &new_arr[j]);
                else if (time1.tm_mon == time2.tm_mon)
                {
                    if (time1.tm_mday < time2.tm_mday)
                        string_swap(&new_arr[i], &new_arr[j]);
                    else if (time1.tm_mday == time2.tm_mday)
                    {
                        if (time1.tm_hour < time2.tm_hour)
                            string_swap(&new_arr[i], &new_arr[j]);
                        else if(time1.tm_hour == time2.tm_hour)
                        {
                            if (time1.tm_min < time2.tm_min)
                                string_swap(&new_arr[i], &new_arr[j]);
                            else if (time1.tm_min == time2.tm_min)
                            {
                                if (time1.tm_sec < time2.tm_sec)
                                    string_swap(&new_arr[i], &new_arr[j]);
                            }
                        }
                    }
                }
            }
            printf("i = %s  j = %s", new_arr[i], new_arr[j]);
            j++;
        }
        printf("\n");
        i++;
    }
    int k = 0;
    while ( k < size_arr)
    {
        printf("%s\n", new_arr[k]);
        k++;
    }
    printf("\n");
	return (new_arr);
}
*/
/*
int    chech_year(struct tm time_1, struct tm time_2, char *str1, char *str2, char **arr)
{
    if (time_1.tm_year == time_2.tm_year)
    {
        chech_month(time_1, time_2, str1, str2, arr);
        return (true);
    }
    else if (time_1.tm_year < time_2.tm_year)
        return (true);
    return (false);
}

int    chech_month(struct tm time_1, struct tm time_2, char *str1, char *str2, char **arr)
{
    if (time_1.tm_mon == time_2.tm_mon)
    {
        chech_day(time_1, time_2, str1, str2, arr);
        return (true);
    }
    else if (time_1.tm_mon < time_2.tm_mon)
        return (true);
    return (false);
}

int    chech_day(struct tm time_1, struct tm time_2, char *str1, char *str2, char **arr)
{
    if (time_1.tm_mday == time_2.tm_mday)
    {
        chech_hour(time_1, time_2, str1, str2, arr);
        return (true);
    }
    else if (time_1.tm_mday < time_2.tm_mday)
        return (true);
    return (false);
}

int    chech_hour(struct tm time_1, struct tm time_2, char *str1, char *str2, char **arr)
{
    if (time_1.tm_hour == time_2.tm_hour)
    {
        chech_min(time_1, time_2, str1, str2, arr);
        return (true);
    }
    else if (time_1.tm_hour < time_2.tm_hour)
        return (true);
    return (false);
}

int    chech_min(struct tm time_1, struct tm time_2, char *str1, char *str2, char **arr)
{
    if (time_1.tm_min == time_2.tm_min)
    {
        chech_sec(time_1, time_2, str1, str2);
        return (true);
    }
    else if (time_1.tm_min < time_2.tm_min)
        return (true);
    return (false);
}

int    chech_sec(struct tm time_1, struct tm time_2, char *str1, char *str2)
{
    if (time_1.tm_sec == time_2.tm_sec)
    {    
        chech_microsec(time_1, time_2, str1, str2);
        return (true);
    }
    else if (time_1.tm_sec < time_2.tm_sec)
        return (true);
    return (false);
}

int    chech_microsec(struct tm time_1, struct tm time_2, char *str1, char *str2)
{
    long double microsec1;
    long double microsec2;

    microsec1 = time_1.tm_sec / 10000000;
    microsec2 = time_2.tm_sec / 10000000;
    printf("microsec1 = %Lf", microsec1);
    printf("microsec2 = %Lf", microsec2);
    if (microsec1 < microsec2)
        return (true);
    return (false);
}
*/