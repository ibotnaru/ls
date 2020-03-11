#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char	*choose_time(t_path *path, char *flags)
{
	char	*t;

	if (ft_strrchr(flags, 'u') && ft_strrchr(flags, 't'))
		t = ctime(&path->stat->st_atime);
	else if (ft_strrchr(flags, 'c') && ft_strrchr(flags, 't'))
		t = ctime(&path->stat->st_ctime);
	else
		t = ctime(&path->stat->st_mtime);
	return (t);
}