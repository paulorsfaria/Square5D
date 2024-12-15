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

#include "../../headers/cub3d.h"

int	draw(t_mlx *win)
{
	render_background(&win->img, 0xD3D3D3);
	ft_draw_map(win->map, &win->img, win);
	ft_update_player(win->player->x, win->player->y,
		&win->img, win);
	ft_vision_angle(win, win->player->x, win->player->y);
	render_background_top_bot(win, &win->img);
	raycaster(win);
	mlx_put_image_to_window(win->mlx_connect, win->mlx_win,
		win->img.mlx_img, 0, 0);
	return (0);
}

//TODO ver com o Paulo para dar merge antes de dar Norm
void	render(t_mlx *win) //render(char **map)
{
	win->mlx_connect = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx_connect, WIDTH, HEIGHT, "Cub3D");
	win->img.mlx_img = mlx_new_image(win->mlx_connect, WIDTH, HEIGHT);
	win->img.addr = mlx_get_data_addr(win->img.mlx_img, &win->img.bpp,
			&win->img.line_len, &win->img.endian);
	// North texture
	win->north_texture.mlx_img = mlx_xpm_file_to_image(win->mlx_connect,
			win->north_texture.path, &win->north_texture.width,
			&win->north_texture.height);
	if (win->north_texture.mlx_img == NULL)
		ft_cleanup_and_exit(win);
	win->north_texture.addr = mlx_get_data_addr(win->north_texture.mlx_img,
			&win->north_texture.bpp, &win->north_texture.line_len,
			&win->north_texture.endian);

	// South texture
	win->south_texture.mlx_img = mlx_xpm_file_to_image(win->mlx_connect,
			win->south_texture.path, &win->south_texture.width,
			&win->south_texture.height);
	if (win->south_texture.mlx_img== NULL)
		ft_cleanup_and_exit(win);
	win->south_texture.addr = mlx_get_data_addr(win->south_texture.mlx_img,
			&win->south_texture.bpp, &win->south_texture.line_len,
			&win->south_texture.endian);

	// East texture
	win->east_texture.mlx_img = mlx_xpm_file_to_image(win->mlx_connect,
			win->east_texture.path, &win->east_texture.width,
			&win->east_texture.height);
	if (win->east_texture.mlx_img == NULL)
		ft_cleanup_and_exit(win);
	win->east_texture.addr = mlx_get_data_addr(win->east_texture.mlx_img,
			&win->east_texture.bpp, &win->east_texture.line_len,
			&win->east_texture.endian);

	// West texture
	win->west_texture.mlx_img = mlx_xpm_file_to_image(win->mlx_connect,
			win->west_texture.path, &win->west_texture.width,
			&win->west_texture.height);
	if (win->west_texture.mlx_img == NULL)
		ft_cleanup_and_exit(win);
	win->west_texture.addr = mlx_get_data_addr(win->west_texture.mlx_img,
			&win->west_texture.bpp, &win->west_texture.line_len,
			&win->west_texture.endian);

	mlx_loop_hook(win->mlx_connect, &draw, win);
	mlx_key_hook(win->mlx_win, arrow_keys, win);
	mlx_hook(win->mlx_win, KeyPress, KeyPressMask, ft_event_checker, win);
	mlx_hook(win->mlx_win, 17, 0, ft_close, win);
	mlx_loop(win->mlx_connect);
}

void	check_bool_final(t_temp_map *map)
{
	first_check(map, 0, 0);
	if (map->valid->so == false || map->valid->no == false
		|| map->valid->we == false || map->valid->ea == false)
		print_error("textures", map);
	if (map->valid->c == false || map->valid->f == false)
		print_error("colors", map);
}

static int	is_whitespace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
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
	{
		ft_printf_err("Error in calloc\n");
		error_central(0, map);
	}
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
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
	return (line);
}

void	ft_validations(char *argv[])
{
	t_temp_map	*map;

	ft_check_file_name(argv[1]);
	map = ft_calloc(sizeof(t_temp_map), 1);
	map->player = ft_calloc(sizeof(t_player), 1);
	map->size = ft_get_file_size(argv[1]);
	ft_get_map(&map, argv[1]);
	check_bool_final(map);
	col_val(map, -1);
	check_textures(map, 0, 0, NULL);
	check_map(map, 0, 0, -1);
	free_map_parse(&map);
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
        map->size = ft_get_file_size(argv[1]);
        ft_get_map(&map, argv[1]);
     //   int i = -1;
//        while(map->lines[++i])
//            printf("%s\n", map->lines[i]);
		// function to get proper map values
		win = ft_calloc(sizeof(t_mlx), 1);
		set_up_win(win, map);
		free_map_parse(&map);
		render(win);
	}
	else if (argc > 1)
		ft_printf_err("Only one input is accepted");
	else
		ft_printf_err("Please use:\n./cub3d pwd/to/the/map\n");
	ft_printf("Thank you for using our print a square services\n");
	return (0);
}
