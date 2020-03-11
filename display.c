/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:12:04 by ibotnaru          #+#    #+#             */
/*   Updated: 2020/02/16 00:08:03 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#define _POSIX_SOURCE
#include <sys/types.h>
#include <pwd.h>
    struct passwd *p;
    uid_t  uid=0;

    p = getpwuid(uid);
    printf("  pw_name  : %s\n",       p->pw_name);
        printf("  pw_uid   : %d\n", (int) p->pw_uid);
    printf("  pw_gid   : %d\n", (int) p->pw_gid);
    printf("  pw_dir   : %s\n",       p->pw_dir);
    printf("  pw_shell : %s\n\n",       p->pw_shell);

    https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.bpxbd00/rtgtpu.htm
*/

#include "ft_ls.h"

/*  Display data depending on the flag */

void    no_flags(char strings_arr[][MAX_LEN], int size_arr)
{
    int i;

    i = 0;
    while (i < size_arr)
    {
        if (strings_arr[i][0] != '.')
            printf("%s\n", strings_arr[i]);
        i++;
    }
}
//-------------------------------------------------------------------
//http://codewiki.wikidot.com/c:system-calls:stat
//http://www.qnx.com/developers/docs/6.5.0/index.jsp?topic=%2Fcom.qnx.doc.neutrino_lib_ref%2Fg%2Fgetgrgid.html
//https://codeforwin.org/2018/03/c-program-find-file-properties-using-stat-function.html

void    l_flag(char strings_arr[][MAX_LEN], int size_arr)
{
    struct stat fileStat; //stat()
    struct group* g;    //getgrgid()
    struct passwd* pw;  //getpwuid()
    struct tm time;     //time
    char        *month;
    int         day;

    
    g = getgrgid(getgid()); //getgrgid()
    pw = getpwuid(getuid()); //getpwuid()
    // time = *(gmtime(&fileStat.st_ctime));
    int i = 0;
    while (i < size_arr)
    {
        if (strings_arr[i][0] != '.')
        {

            stat(strings_arr[i],&fileStat);
            time = *(gmtime(&fileStat.st_ctime)); //time
            printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-"); //stat()
            printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");//stat()
            printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");//stat()
            printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");//stat()
            printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");//stat()
            printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");//stat()
            printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");//stat()
            printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");//stat()
            printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");//stat()
            printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");//stat()
            printf("  %d",fileStat.st_nlink);//stat()
            printf( " %s", pw->pw_name );//getpwuid()
            printf("  %s", g->gr_name );//getgrgid()
            printf(" %7lld",fileStat.st_size);//stat()
            month = convert_month(time.tm_mon);
            day = convert_day(time.tm_mday, time.tm_hour + 16);
            printf(" %s %2d %.2d:%.2d", month, day, (time.tm_hour + 16) % 24, time.tm_min); //time
            printf(" %s\n", strings_arr[i]);//stat()
        }
        i++;
    }
}
//----------------------------------------------------------------------------------------------
void    t_flag(char **strings_arr, int size_arr)
{
   int     i;

    i = 0;
    while (i < size_arr)
    {
        if (strings_arr[i][0] != '.')
            printf("%s\n", strings_arr[i]);
        i++;
    }
}

void    r_flag(char strings_arr[][MAX_LEN], int size_arr)
{
    size_arr--;

    while (size_arr >= 0)
    {
        if (strings_arr[size_arr][0] != '.')
            printf("%s\n", strings_arr[size_arr]);
        size_arr--;
    }
}

void    R_flag(char strings_arr[][MAX_LEN], int size_arr)
{
    printf("Flag -R is displayd\n");
}

void    a_flag(char strings_arr[][MAX_LEN], int size_arr)
{
    int     i;

    i = 0;
    while (i < size_arr)
    {
        printf("%s\n", strings_arr[i]);
        i++;
    }
}

char    *convert_month(int time)
{
    if (time == 0)
        return("Jan");
    else if (time == 1)
        return("Feb");
    else if (time == 2)
        return("Mar");
    else if (time == 3)
        return("Apr");
    else if (time == 4)
        return("May");
    else if (time == 5)
        return("Jun");
    else if (time == 6)
        return("Jul");
    else if (time == 7)
        return("Aug");
    else if (time == 8)
        return("Sep");
    else if (time == 9)
        return("Oct");
    else if (time == 10)
        return("Nov");
    else
        return("Dec");
}

int     convert_day(int day, int time)
{
    if (time >= 24)
        return(day);
    else
        return(day - 1);
}