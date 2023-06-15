#include "so_long.h"

static int	cmap_border(t_map *data)
{
	size_t col;
	size_t line;

	col = 1;
	while (data->map[col] 
		&& (ft_strlen(data->map[col]) == ft_strlen(data->map[0])))
		col++;
	if (data->map[col])
		return (0);
	while (data->map[0][data->mpos[X]] == '1' 
		&& data->map[col - 1][data->mpos[X]] == '1')
		data->mpos[X]++;
	line = ft_strlen(data->map[0]);
	while (data->map[data->mpos[Y]] && data->map[data->mpos[Y]][0] == '1' 
		&& data->map[data->mpos[Y]][line - 1] == '1')
		data->mpos[Y]++;
	if (data->mpos[X] != line || data->mpos[X] > LMAX
		|| data->mpos[Y] != col || data->mpos[Y]> HMAX)
		return (0);
	data->mpos[X] = 0;
	data->mpos[Y] = 0;
	return (1);	
}

static	int	cmap_inside(t_map *data, char c)
{
	int	exit;

	exit = 0;
	while (data->map[data->mpos[Y]] 
		&& ft_strchr("CEP01", c))
	{
		c = data->map[data->mpos[Y]][data->mpos[X]];
		if (c == 'C')
			data->item++;
		else if (c == 'E')
			exit += 1;
		else if (!data->ppos[X] && c == 'P')
			data->ppos[X] += data->mpos[X];
		if (!data->ppos[Y] && c == 'P')
			data->ppos[Y] += data->mpos[Y];
		data->mpos[X]++;
		if (c == '\0')
			data->mpos[X] = 0;
		if (c == '\0')
			data->mpos[Y]++;
		if (!data->map[data->mpos[Y]] && data->ppos[X] 
			&& data->ppos[Y] && exit == 1 && data->item)
			return (1);
	}
	return (0);
}

static void	cmap_path(t_map *data, size_t col, size_t line, size_t *item)
{
	if (data->map[line][col] == 'E')
		data->path[0] = 'S';
	if (data->path[0] == 'S' && !(*item))
		data->path[0] = 'V';
	if (data->map[line][col] == 'C')
		*item -= 1;
	if (data->map[line][col] == '0' || data->map[line][col] == 'C'
		|| data->map[line][col] == 'E' || data->map[line][col] == 'P')
	{
		data->map[line][col] = '2';
		cmap_path(data, col + 1, line, item);
		cmap_path(data, col - 1, line, item);
		cmap_path(data, col, line + 1, item);
		cmap_path(data, col, line - 1, item);
	}
}

int	map_parsing(t_map *data)
{
	size_t	item;

	data->ppos[X] = 0;
	data->ppos[Y] = 0;
	data->mpos[X] = 0;
	data->mpos[Y] = 0;
	data->path[0] = '\0';
	data->item = 0;
	if (!cmap_border(data) 
		|| !cmap_inside(data, data->map[data->mpos[Y]][data->mpos[X]]))
		return (ft_printf("Error\n[Carte non valide]\n"));
	item = data->item;
	cmap_path(data, data->ppos[X], data->ppos[Y], &item);
	if (data->path[0] != 'V')
		return (ft_printf("Error\n[Carte non valide]\n"));
	return (ft_printf("Carte valide\n"));
}
