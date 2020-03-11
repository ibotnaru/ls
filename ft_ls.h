/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 21:36:41 by ibotnaru          #+#    #+#             */
/*   Updated: 2020/02/16 19:46:42 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "libft/libft.h"
#include <sys/types.h>  //lib for opendir() readdir()   closedir()
#include <dirent.h>     //lib for opendir() readdir()   closedir()
#include <stdlib.h>     //exit()
#include <stdio.h>      //printf()
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>   //stat()
#include <sys/types.h>  //stat()
#include <sys/types.h>  //getgrgid()
#include <grp.h>        //getgrgid()
#include <pwd.h>        //getpwuid() 
#define MAX_LEN 100
#define true 1
#define false 0

char    get_flag(int ac, char *param);

void    arrstring_sort(char strings_arr[][MAX_LEN], int n);

void    sort_and_display(char flag, char strings_arr[][MAX_LEN], int size_arr);

void    no_flags(char strings_arr[][MAX_LEN], int size_arr);
void    l_flag(char strings_arr[][MAX_LEN], int size_arr);

void    r_flag(char strings_arr[][MAX_LEN], int size_arr);
void    R_flag(char strings_arr[][MAX_LEN], int size_arr);
void    a_flag(char strings_arr[][MAX_LEN], int size_arr);

char    *convert_month(int month);
int     convert_day(int day, int time);

void    t_flag(char **strings_arr, int size_arr);
char    **mtime_sort(char strings_arr[][MAX_LEN], int size_arr);



void    string_swap(char **str1, char **str2);
// void    sort_by_day(struct tm time1, struct tm time2, char **str1, char **str2);
int    sort_by_day(struct tm time1, struct tm time2, char **str1, char **str2);
// void    chech_year(struct tm time_1, struct tm time_2, char str1[][MAX_LEN], char str2[][MAX_LEN]);
// void    chech_month(struct tm time_1, struct tm time_2, char str1[][MAX_LEN], char str2[][MAX_LEN]);
// void    chech_day(struct tm time_1, struct tm time_2, char str1[][MAX_LEN], char str2[][MAX_LEN]);
// void    chech_hour(struct tm time_1, struct tm time_2, char str1[][MAX_LEN], char str2[][MAX_LEN]);
// void    chech_min(struct tm time_1, struct tm time_2, char str1[][MAX_LEN], char str2[][MAX_LEN]);
// void    chech_sec(struct tm time_1, struct tm time_2, char str1[][MAX_LEN], char str2[][MAX_LEN]);



// int    chech_year(struct tm time_1, struct tm time_2, char *str1, char *str2, char **arr);
// int    chech_month(struct tm time_1, struct tm time_2, char *str1, char *str2, char **arr);
// int    chech_day(struct tm time_1, struct tm time_2, char *str1, char *str2, char **arr);
// int    chech_hour(struct tm time_1, struct tm time_2, char *str1, char *str2, char **arr);
// int    chech_min(struct tm time_1, struct tm time_2, char *str1, char *str2, char **arr);
// int    chech_sec(struct tm time_1, struct tm time_2, char *str1, char *str2);
// int    chech_microsec(struct tm time_1, struct tm time_2, char *str1, char *str2);

// char    *create_newarr(char strings_arr[][MAX_LEN], int size_arr);


#endif