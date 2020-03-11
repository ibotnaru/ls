/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:49:34 by ibotnaru          #+#    #+#             */
/*   Updated: 2020/02/15 21:26:47 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// char    *create_newarr(char strings_arr[][MAX_LEN], int size_arr)
// {
    // int i  = 0;
    // int j = 0;
    // char    *new_stringarr[MAX_LEN];
// 
    // while (i < size_arr)
    // {
        // if (strings_arr[i][0] != '.')
            // ft_strcpy(new_stringarr[j], strings_arr[i]);
        // i++;
        // j++;
    // }
    // return (new_stringarr);
// }

/*  Call different function depending on the flag.
    These functions do the soting and dispay the contetn. */
void    sort_and_display(char flag, char strings_arr[][MAX_LEN], int size_arr)
{
    char    **new_arr;

    if (flag == '0')
        no_flags(strings_arr, size_arr);
    else if (flag == 'l')
        l_flag(strings_arr, size_arr);
    else if (flag == 't')
    {
        // sort the string by modification date
        // new_stringarr = create_newarr(strings_arr, size_arr);
        new_arr = mtime_sort(strings_arr, size_arr);
        t_flag(new_arr, size_arr);
    }
    else if (flag == 'r')
        r_flag(strings_arr, size_arr);
    else if (flag == 'R')
        R_flag(strings_arr, size_arr);
    else if (flag == 'a')
        a_flag(strings_arr, size_arr);    
}

/*  Function that sorts an array of strings where length of every 
    string should be smaller than MAX_LEN 
    
    !! This function works fine (I checked) */

void    arrstring_sort(char strings_arr[][MAX_LEN], int size) 
{ 
    int i;
    int j;
    int min_idx;
    char min_str[MAX_LEN];
    char temp[MAX_LEN];

    i = 0;
    j = 0;
    min_idx = 0; 
    while (i < (size - 1)) 
    { 
        min_idx = i;
        j = i + 1;
        ft_strcpy(min_str, strings_arr[i]); 
        while (j < size) 
        { 
            if (ft_strcmp(min_str, strings_arr[j]) > 0) 
            { 
                ft_strcpy(min_str, strings_arr[j]); 
                min_idx = j; 
            }
            j++;
        } 
        if (min_idx != i) 
        { 
            ft_strcpy(temp, strings_arr[i]);
            ft_strcpy(strings_arr[i], strings_arr[min_idx]);
            ft_strcpy(strings_arr[min_idx], temp);
        }
        i++; 
    }
}
