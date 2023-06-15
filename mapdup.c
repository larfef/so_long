#include "so_long.h"

static char	**map_to_buffer(int fd, size_t line)
{
	char	**tab;
	size_t	i;

	tab = ft_calloc(line + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < line)
	{
		tab[i] = get_next_line(fd);
		if (!tab[i])
		{
			free_table(tab);
			return (NULL);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

static size_t	nb_of_line(int fd)
{
	char	*str;
	size_t	line;

	str = get_next_line(fd);
	line = 0;
	while (str != NULL)
	{
		if (str)
			free(str);
		line++;
		str = get_next_line(fd);
	}
	if (close(fd) == -1)
		exit_err(errno);
	return (line);
}

static char	**minfo(char *arg, int fd)
{
	char	*path;
	char	**tab;
	size_t	tab_size;

	tab_size = nb_of_line(fd);
	if (!(path = ft_strjoin("./maps/", arg)))
		exit(EXIT_FAILURE);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd == -1)
		exit_err(errno);
	tab = map_to_buffer(fd, tab_size);
	if (close(fd) == -1)
		exit_err(errno);
	if (!tab)
		exit(EXIT_FAILURE);
	return(tab);
}

void	mdup(char *arg, t_map *data)
{
	char	*path;
	int		fd;

	if (!(path = ft_strjoin("./maps/", arg)))
		exit(EXIT_FAILURE);	
	fd = open(path, O_RDONLY);
	free(path);
	if (fd == -1)
		exit_err(errno);
	data->map = minfo(arg, fd);
	printf_tab(data->map);
}