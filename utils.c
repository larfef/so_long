#include "so_long.h"

void	exit_err(int errnum)
{	
	perror(strerror(errnum));
	exit(EXIT_FAILURE);
}

void	free_table(char **buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i])
		i++;
	while (--i > -1)
		free(buffer[i]);
	free(buffer);
}

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	if (*a == 'C')
		*a = '0';
}

void	printf_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s\n",tab[i]);
		i++;
	}
}