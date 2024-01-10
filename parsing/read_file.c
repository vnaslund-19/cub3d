/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaslund <vnaslund@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:58:23 by vnaslund          #+#    #+#             */
/*   Updated: 2024/01/10 17:57:47 by vnaslund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_read_file(t_game *game, char **argv)
{
	int		fd;
	int		i;
	int		line_count;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_handler("Map error: open error", game);
	line_count = ft_allocate_lines(game, argv);
	game->data->allocated_file = true;
	i = 0;
	while (line_count--)
	{
		game->data->file[i] = get_next_line(fd);
		if (game->data->file[i] == NULL)
			exit_handler("Map error: gnl error", game);
		i++;
	}
	game->data->file[i] = NULL;
	get_next_line(-1);
	game->data->map = NULL;
	ft_file_check(game, game->data->file, 0);
	if (!game->data->map)
		exit_handler("map not found", game);
	ft_playable_check(game, game->data->map);
}

int	ft_allocate_lines(t_game *game, char **argv)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_handler("Map error: open error", game);
	line_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		free(line);
		line_count++;
	}
	close(fd);
	game->data->lines = line_count;
	game->data->file = (char **)malloc((line_count + 1) * sizeof(char *));
	if (!game->data->file)
		exit_handler("Malloc error", game);
	return (line_count);
}
