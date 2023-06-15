#include "so_long.h"
# define BUFFER_SIZE 1
# define SIZE 0

static char	*ft_join(char *head, char *body)
{
	char	*temp;

	temp = ft_strjoin(head, body);
	free(head);
	return (temp);
}

static char	*ft_read(char *join, char *buffer, int i, int fd)
{
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (*buffer == '\n')
			break;
		else if (i == -1)
		{
			free(join);
			return (NULL);
		}
		join = ft_join(join, buffer);
		if (!join)
			return (NULL);
		buffer[SIZE] = '\0';
	}
	return (join);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*join;

	join = ft_calloc(1, 1);
	if (*buffer != '\0')
		buffer[SIZE] = '\0';
	join = ft_read(join, buffer, 1, fd);
	if (!join)
		return (NULL);
	if (*join == '\0' && *buffer == '\0')
	{
		free(join);
		return (NULL);
	}
	return (join);
}
