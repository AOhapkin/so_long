#include "so_long.h"

void	map_rows(t_game *game)
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

void	map_snapshot(t_game *game)
{
	int	size;

	size = game->map.rows;
	game->map.snapshot = malloc(sizeof(char *) * (size + 1));
	if (!game->map.snapshot)
		game_error(ERR_MALLOC_FAIL, game);
	game->map.snapshot[size] = 0;
	while (size--)
		game->map.snapshot[size] = ft_strdup(game->map.tiles[size]);
}

void	map_free(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.tiles)
	{
		while (i < game->map.rows)
			free(game->map.tiles[i++]);
		free(game->map.tiles);
	}
	game->map.tiles = 0;
	i = 0;
	if (game->map.snapshot)
	{
		while (i < game->map.rows)
			free(game->map.snapshot[i++]);
		free(game->map.snapshot);
	}
	game->map.snapshot = 0;
}

void	map_init(char *path, t_game *game)
{
	game->map.tiles = 0;
	game->map.snapshot = 0;
	game->map.path = path;
	game->map.rows = 0;
	game->map.cols = 0;
	game->map.players = 0;
	game->map.collectibles = 0;
	game->map.exits = 0;
	map_rows(game);
	map_build(game);
	map_verify_wall(game);
	map_verify_charset(game);
	map_verify_components(game);
}
