/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 21:36:44 by ibotnaru          #+#    #+#             */
/*   Updated: 2020/02/15 12:09:23 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/* Get the parameters */
int     main(int ac, char **av)
{
    /* Step 1:
        Open a directory with opendir() (man opendir to see how it works).
        opendir() returns *DIR
        opendir(".") means that we are opening current dyrectory */

    DIR             *current_directory;
    struct dirent   *sd;
    char            flag;
    char            strings_arr[MAX_LEN][MAX_LEN];
    int             size_arr;
    // -l flag stat()

    size_arr = 0;
    current_directory = opendir(".");
    if (current_directory == NULL)
    {
        printf("Error! Unable to open directory\n");
        exit (1);
    }

     /* Step 3:
        All the content is printed including regular files, 
        directories and hidden files. We need to sort this data depending on the flag.
        So for thaat we need to pars the flags first.
        Function get_flag int parsing.c file is doing that */
        
    flag = get_flag(ac, av[1]);

    /* Step 2:
        So if we could open the dyrectory we need to read all the files and
        subdirectories inside of it and dysplay them. Use readdir() for that,
        which returns (struct dirent *) and we have the variable sd for that.
        while sd is not Null we print the content of current directory.
        If sd is Null it means there is nothing else to read in current dir */
    while ((sd = readdir(current_directory)) != NULL )
    {
        /*  step 4:
        I've created an array of strings and keep all the content of the current
        directory in that array. Later I can substract data from it do display it.
        In the while loop we put the content in that array string by string(whilch
        are files, directories, hidden files and so on..). */
        ft_strcpy(strings_arr[size_arr], sd->d_name);
        size_arr++;
    }
    // int j = 0;
    // while (j < size_arr)
    // {
    //     printf("%s\n", strings_arr[j]);
    //     j++;
    // }
    // printf("\n\n");
    /* This functios sorst the array of strings by ASCII */
    arrstring_sort(strings_arr, size_arr);
    /*  We have the flags parsed and the array sorted at this point.
        Next function will display the content of curren directory depending on the flag. */
    sort_and_display(flag, strings_arr, size_arr);
    
    
    /*  Step ???:
        Display data sorted depending on the flag */
    closedir(current_directory);
    return (0);
}