/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:49:25 by ibotnaru          #+#    #+#             */
/*   Updated: 2020/02/08 22:38:27 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


/*  We enter in this function only if ac > 1
    Here "param" is av[1]. 
    We are looking if av[1] is a valid flag and return this flag as one letter. */
char    get_flag(int ac, char *param)
{
    char    flag;
    if (ac == 1)
        flag = '0'; // means there is no flags
    else if (ac > 1)
    {
        /* If av[1] isn't valid flag we display an error and quit the program. */
        if ((param[0] != '-') && (param[2] != '\0') && (param[1] != 'l' ||
            param[1] != 't' || param[1] != 'r' || param[1] != 'r' ||
            param[1] != 'R' || param[1] != 'a'))
        {
            printf("Error, invalid flag! Use ./ft_ls -[ltrRa]\n");
            exit(1);
        }
        /* Otherwise we ckeck wich flag is it and return it to main() */
        if (param[1] == 'l')
            flag = 'l';
        else if (param[1] == 't')
            flag = 't';
        else if (param[1] == 'r')
            flag = 'r';
        else if (param[1] == 'R')
            flag = 'R';
        else if (param[1] == 'a')
            flag = 'a';
    }
    // printf ("flag = %c", flag);
    return(flag);
}