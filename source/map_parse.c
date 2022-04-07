#include "so_long.h"

void	get_height(char *argv, t_game *game)
{
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error_exit("Can't open file\n", game);
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

void	check_folder(char *argv)
{
	char	*folder;
	char	*path;
	int		fd;

	folder = "/";
	path = ft_strjoin(argv, folder);
	fd = open(path, O_RDONLY);
	if (fd != -1)
	{
		ft_putendl_fd("Map error: it's not a file");
		exit(1);
	}
	free(path);
	close(fd);
}

void	read_file(char *argv, t_game *game)
{
	int		fd;
	int		height;

	check_folder(argv);
	get_height(argv, game);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error_exit("Can't open file\n", game);
	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (game->map == NULL)
		ft_error_exit("Malloc error", game);
	height = 0;
	while (height < game -> height)
	{
		get_next_line_fd(fd, &game->map[height]);
		height++;
	}
	if (game->map == NULL)
		ft_error_exit("Map error: can't read file", game);
	close(fd);
}

void	check_name(char *name)
{
	size_t 		len;
	char	*endofname;

	len = ft_strlen(name);
	endofname = ft_substr(name, len - 4, 4);
	if (ft_strncmp(endofname, ".ber", 4) != 0)
	{
		free(endofname);
		ft_putendl_fd("Filetype error");
		exit(1);
	}
	free(endofname);
}

void	parse_map(char *argv, t_game *game)
{
	int	height;

	check_name(argv);
	read_file(argv, game);
	height = 0;
	game->width = ft_strlen(game->map[height]);
	while (height < game->height)
	{
		if (game->width != ft_strlen(game->map[height]))
			ft_error_exit("Map is not rectangular", game);
		height++;
	}
	check_chars(game);
	check_walls(game);
}
