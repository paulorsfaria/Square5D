/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:51:00 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/02 15:53:11 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"
/**
 * raycaster - Casts rays to determine intersections with the map.
 *
 * Variables used:
 * - @r: Number of rays to cast.
 * - @mx: Map index on the x-axis (integer grid coordinate).
 * - @my: Map index on the y-axis (integer grid coordinate).
 * - @dof: Depth of field (maximum number of steps to check for collisions).
 * - @rx: X-coordinate of the ray endpoint on the rendered map.
 * - @ry: Y-coordinate of the ray endpoint on the rendered map.
 * - @ra: Ray angle (starts as the player's angle, varies per ray).
 * - @xo: X-offset for stepping to the next grid cell.
 * - @yo: Y-offset for stepping to the next grid cell.
 * - @atan: Inverse of tangent (used for ray_h direction).
 * - @ntan: Negative tangent (used for ray_v direction).
 *
**/

static void	ft_horizontal_init(t_mlx *win, t_h_inter *vars, float ra);
static void	horizontal_intersection(t_mlx *win, float ra, float *hx, float *hy);
static void	ft_vertical_init(t_mlx *win, t_v_inter *vars, float ra);
static void	vertical_intersection(t_mlx *win, float ra, float *vx, float *vy);

void	raycaster(t_mlx *win)
{
	t_ray_vars	vars;

	ft_init_vars(&vars, win);
	while (++vars.r < WIDTH && ft_circle_normalizer(&vars.ra) == SUCCESS)
	{
		horizontal_intersection(win, vars.ra, &vars.hx, &vars.hy);
		vertical_intersection(win, vars.ra, &vars.vx, &vars.vy);
		vars.ray_h = line_length(win->player->x, win->player->y,
				vars.hx, vars.hy);
		vars.ray_v = line_length(win->player->x, win->player->y,
				vars.vx, vars.vy);
		if (vars.ray_h < vars.ray_v)
		{
			ft_texture_picker(win, vars.hy, 'h');
			ft_value_setter(&vars.wall_x, &vars.hx, &vars.line, &vars.ray_h);
		}
		else
		{
			ft_texture_picker(win, vars.vx, 'v');
			ft_value_setter(&vars.wall_x, &vars.vy, &vars.line, &vars.ray_v);
		}
		vars.line = vars.line * cos(win->player->player_angle - vars.ra);
		draw_3d_walls(win, vars.line, vars.r, vars.wall_x);
		vars.ra += DR;
	}
}

static void	ft_horizontal_init(t_mlx *win, t_h_inter *vars, float ra)
{
	vars->atan = -1 / tan(ra);
	vars->dof = 0;
	if (ra > PI)
	{
		vars->ry = (((int)win->player->y / SQUARE) * SQUARE) - 0.0001;
		vars->rx = (win->player->y - vars->ry) * vars->atan + win->player->x;
		vars->yo = -SQUARE;
		vars->xo = -vars->yo * vars->atan;
	}
	else if (ra < PI)
	{
		vars->ry = (((int)win->player->y / SQUARE) * SQUARE) + SQUARE;
		vars->rx = (win->player->y - vars->ry) * vars->atan + win->player->x;
		vars->yo = SQUARE;
		vars->xo = -vars->yo * vars->atan;
	}
	else if (ra == 0 || ra == PI)
	{
		vars->rx = win->player->x;
		vars->ry = win->player->y;
		vars->dof = 20;
	}
}

static void	horizontal_intersection(t_mlx *win, float ra, float *hx, float *hy)
{
	t_h_inter	vars;

	ft_horizontal_init(win, &vars, ra);
	while (vars.dof < 20)
	{
		vars.mx = (int)(vars.rx / SQUARE);
		vars.my = (int)(vars.ry / SQUARE);
		if (vars.mx < 0 || vars.mx >= win->map->width
			|| vars.my < 0 || vars.my >= win->map->height)
			break ;
		if (win->map->coord[vars.my][vars.mx] == '1')
			break ;
		else
		{
			vars.rx += vars.xo;
			vars.ry += vars.yo;
			vars.dof++;
		}
	}
	*hx = vars.rx;
	*hy = vars.ry;
}

static void	ft_vertical_init(t_mlx *win, t_v_inter *vars, float ra)
{
	vars->ntan = -tan(ra);
	vars->dof = 0;
	if (ra > P2 && ra < P3)
	{
		vars->rx = (((int)win->player->x / SQUARE) * SQUARE) - 0.0001;
		vars->ry = (win->player->x - vars->rx) * vars->ntan + win->player->y;
		vars->xo = -SQUARE;
		vars->yo = -vars->xo * vars->ntan;
	}
	else if (ra < P2 || ra > P3)
	{
		vars->rx = (((int)win->player->x / SQUARE) * SQUARE) + SQUARE;
		vars->ry = (win->player->x - vars->rx) * vars->ntan + win->player->y;
		vars->xo = SQUARE;
		vars->yo = -vars->xo * vars->ntan;
	}
	else if (ra == 0 || ra == PI)
	{
		vars->rx = win->player->x;
		vars->ry = win->player->y;
		vars->dof = 20;
	}
}

static void	vertical_intersection(t_mlx *win, float ra, float *vx, float *vy)
{
	t_v_inter	vars;

	ft_vertical_init(win, &vars, ra);
	while (vars.dof < 20)
	{
		vars.mx = (int)(vars.rx / SQUARE);
		vars.my = (int)(vars.ry / SQUARE);
		if (vars.mx < 0 || vars.mx >= win->map->width
			|| vars.my < 0 || vars.my >= win->map->height)
			break ;
		if (win->map->coord[vars.my][vars.mx] == '1')
			break ;
		else
		{
			vars.rx += vars.xo;
			vars.ry += vars.yo;
			vars.dof++;
		}
	}
	*vx = vars.rx;
	*vy = vars.ry;
}
