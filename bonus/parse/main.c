/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:45:00 by paulo-do          #+#    #+#             */
/*   Updated: 2024/12/08 15:27:00 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d_bonus.h"

int	draw(t_mlx *win)
{
	render_background(&win->img, 0xD3D3D3);
	render_background_top_bot(win, &win->img);
	raycaster(win);
	raycaster(win);
	ft_draw_mini_map(win->map, &win->img, -1, -1);
	ft_update_player((win->player->x / SQUARE) * SQUARE_MINI,
		(win->player->y / SQUARE) * SQUARE_MINI, &win->img, win);
	mlx_put_image_to_window(win->mlx_connect, win->mlx_win,
		win->img.mlx_img, 0, 0);
	return (0);
}

void	start_textures(t_mlx *win, t_tex *texture)
{
	texture->mlx_img = mlx_xpm_file_to_image(win->mlx_connect,
			texture->path, &texture->width, &texture->height);
	if (texture->mlx_img == NULL)
	{
		ft_printf_err("Error in texture path\n");
		ft_cleanup_and_exit(win);
	}
	texture->addr = mlx_get_data_addr(texture->mlx_img,
			&texture->bpp, &texture->line_len,
			&texture->endian);
}

void	render(t_mlx *win)
{
	win->mlx_connect = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx_connect, WIDTH, HEIGHT, "Cub3D");
	win->img.mlx_img = mlx_new_image(win->mlx_connect, WIDTH, HEIGHT);
	win->img.addr = mlx_get_data_addr(win->img.mlx_img, &win->img.bpp,
			&win->img.line_len, &win->img.endian);
	start_textures(win, &win->north_texture);
	start_textures(win, &win->south_texture);
	start_textures(win, &win->east_texture);
	start_textures(win, &win->west_texture);
	mlx_loop_hook(win->mlx_connect, &draw, win);
	mlx_key_hook(win->mlx_win, arrow_keys, win);
	mlx_hook(win->mlx_win, KeyPress, KeyPressMask, ft_event_checker, win);
	mlx_hook(win->mlx_win, 17, 0, ft_close, win);
	mlx_loop(win->mlx_connect);
}

char	*ft_remove_extra_spaces(char *str, t_temp_map *map)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!line)
		error_central(-15, map);
	while (is_whitespace(str[i]))
		i++;
	while (str[i])
	{
		while (str[i] && !is_whitespace(str[i]))
			line[j++] = str[i++];
		while (is_whitespace(str[i]))
			i++;
		if (i > 0 && str[i] != '\0')
			line[j++] = ' ';
	}
	line[j] = '\0';
	if (line[0] == 'C' || line[0] == 'F')
		line = ft_color_special(line, 0, 0, map);
	return (line);
}

int	main(int argc, char *argv[])
{
	t_mlx		*win;
	t_temp_map	*map;

	argc--;
	if (argc == 1)
	{
		ft_validations(argv);
		map = ft_calloc(sizeof(t_temp_map), 1);
		map->player = ft_calloc(sizeof(t_player), 1);
		map->size = ft_get_file_size(argv[1], map);
		ft_get_map(&map, argv[1], 0, 0);
		win = ft_calloc(sizeof(t_mlx), 1);
		set_up_win(win, map);
		free_map_parse(&map);
		render(win);
	}
	else if (argc > 1)
		ft_printf_err("Only one input is accepted");
	else
		ft_printf_err("Please use:\n./cub3d_bonus pwd/to/the/map\n");
	return (0);
}
