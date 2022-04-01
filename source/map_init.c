#include "so_long.h"

void	get_map_height(t_game *game)
{
	int		fd;
	int		bytes_read;
	char	buffer_read;

	if (!isfiletype(game->map.path, MAP_FILETYPE))
		game_error(ERR_MAP_INVALID_FILETYPE, game);
	fd = open(game->map.path, O_RDONLY);
	if (fd < 0)
		game_error(ERR_MAP_OPEN_FAIL, game);
	while (1)
	{
		bytes_read = read(fd, &buffer_read, 1);
		if (bytes_read == 0)
			break ;
		if (buffer_read == '\n')
			game->map.rows++;
	}
	if (game->map.rows < 3)
		game_error(ERR_MAP_INVALID, game);
	close(fd);
}

void	map_build(t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(game->map.path, O_RDONLY);
	if (fd < 0)
		game_error(ERR_MAP_OPEN_FAIL, game);
	game->map.tiles = ft_calloc(sizeof(char *), (game->map.rows + 1));
	if (!game->map.tiles)
		game_error(ERR_MALLOC_FAIL, game);
	while (i < game->map.rows)
	{
		line = get_next_line(fd);
		game->map.tiles[i++] = ft_strtrim(line, "\n");
		free(line);
	}
	map_snapshot(game);
	close(fd);
}

void	map_reset(t_map *map)
{
	map->grid_initial = 0;
	map->grid_current = 0;
	map->map_file = NULL;
	map->height = 0;
	map->width = 0;
	map->players = 0;
	map->collectibles = 0;
	map->exits = 0;
}

void	init_map(char *file_path, t_game *game)
{
	map_reset(&game->map);
	get_map_height(game);
	map_build(game);
	validate_map(game);
}