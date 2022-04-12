#include "so_long.h"

void	get_height(char *argv, t_game *game)
{
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_game_error("Open file error", game);
	game->height = 0;
	line = NULL;
	while (get_next_line_fd(fd, &line))
	{
		game->height++;
		free(line);
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
	game->height++;
	close(fd);
}

void	read_file(char *argv, t_game *game)
{
	int		fd;
	int		i;

	get_height(argv, game);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_game_error("Can't open file\n", game);
	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		ft_game_error("Malloc error", game);
	i = 0;
	while (i < game -> height)
	{
		get_next_line_fd(fd, &game->map[i]);
		i++;
	}
	close(fd);
}

void	check_file_type(char *name)
{
	int		file_name_len;
	char	*file_name_tail;

	file_name_len = ft_strlen(name);
	file_name_tail = ft_substr(name, file_name_len - 4, 4);
	if (ft_strncmp(file_name_tail, MAP_FILE_TYPE, 4) != 0)
	{
		free(file_name_tail);
		ft_putendl_fd("Error", 1);
		ft_putendl_fd("Map error: filename error\n", 1);
		exit(EXIT_FAILURE);
	}
	free(file_name_tail);
}

void	parse_map(char *argv, t_game *game)
{
	int	height;

	check_file_type(argv);
	read_file(argv, game);
	height = 0;
	game->width = ft_strlen(game->map[height]);
	while (height < game->height)
	{
		if (game->width != (int)ft_strlen(game->map[height]))
			ft_game_error("Map is not rectangular", game);
		height++;
	}
	validate_chars(game);
	validate_walls(game);
}
