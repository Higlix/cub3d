#include "cub.h"

void    render_dda_calc_ray_data(t_game *cub, double cam_x)
{
	cub->dda.pos_map.x = (int )cub->player.pos.x;
	cub->dda.pos_map.y = (int )cub->player.pos.y;
	cub->dda.ray_dir.x = cub->player.dir.x + cub->plane.x * cam_x;
	cub->dda.ray_dir.y = cub->player.dir.y + cub->plane.y * cam_x;
	cub->dda.dis_delta.x = fabs(1 / cub->dda.ray_dir.x);
	cub->dda.dis_delta.y = fabs(1 / cub->dda.ray_dir.y);
}

void    render_dda_calc_first_step(t_game *cub)
{
	if (cub->dda.ray_dir.x < 0)
	{
		cub->dda.step_dir.x = -1;
		cub->dda.ray_len.x = (cub->player.pos.x - cub->dda.pos_map.x) * cub->dda.dis_delta.x;
	}
	else
	{
		cub->dda.step_dir.x = 1;
		cub->dda.ray_len.x = ((cub->dda.pos_map.x + 1) - cub->player.pos.x) * cub->dda.dis_delta.x;
	}
	if (cub->dda.ray_dir.y < 0)
	{
		cub->dda.step_dir.y = -1;
		cub->dda.ray_len.y = (cub->player.pos.y - cub->dda.pos_map.y) * cub->dda.dis_delta.y;
	}
	else
	{
		cub->dda.step_dir.y = 1;
		cub->dda.ray_len.y = ((cub->dda.pos_map.y + 1) - cub->player.pos.y) * cub->dda.dis_delta.y;
	}
}

void    render_dda_calc_ray_len(t_game *cub, int ray_count)
{
	bool    wall;

	wall = false;
	while (wall == false)
	{
		if (cub->dda.ray_len.x < cub->dda.ray_len.y)
		{
			cub->dda.pos_map.x += cub->dda.step_dir.x;
			cub->dda.current_ray_len = cub->dda.ray_len.x;
			cub->dda.ray_len.x += cub->dda.dis_delta.x;
			cub->dda.side = false;
		}
		else
		{
			cub->dda.pos_map.y += cub->dda.step_dir.y;
			cub->dda.current_ray_len = cub->dda.ray_len.y;
			cub->dda.ray_len.y += cub->dda.dis_delta.y;
			cub->dda.side = true;
		}
		if ((int )cub->dda.pos_map.x < cub->map.width && (int )cub->dda.pos_map.y < cub->map.height)
			if (cub->map.map[cub->dda.pos_map.y][cub->dda.pos_map.x] == '1')
				wall = true;
	}
	cub->debug.ray_coll[ray_count].x = cub->player.pos.x + cub->dda.ray_dir.x * cub->dda.current_ray_len;
	cub->debug.ray_coll[ray_count].y = cub->player.pos.y + cub->dda.ray_dir.y * cub->dda.current_ray_len;
}

void    render_dda_calc_wall_height(t_game *cub, int ray_count)
{
	int     wall_start;
	int     wall_end;
	int     wall_height;
	double  perp_wall_height;

	if (cub->dda.side)
		perp_wall_height = cub->dda.ray_len.y - cub->dda.dis_delta.y;
	else
		perp_wall_height = cub->dda.ray_len.x - cub->dda.dis_delta.x;
	wall_height = cub->height / perp_wall_height;
	wall_start = -wall_height / 2 + cub->height / 2;
	wall_end = wall_height / 2 + cub->height / 2;
	if (wall_start < 0)
		wall_start = 0;
	if (wall_end >= cub->height)
		wall_end = cub->height - 1;
	//render_wall(cub, wall_start, wall_end, ray_count);
	//return ;
	int mw = cub->tex_x;
	int mh = cub->tex_y;
	double wallX;
	if (cub->dda.side)
		wallX = cub->player.pos.x + perp_wall_height * cub->dda.ray_dir.x;
	else
		wallX = cub->player.pos.y + perp_wall_height * cub->dda.ray_dir.y;
	wallX -= floor((wallX));
	int texX = (int ) (wallX * (double) mw);
	if (cub->dda.side == false && cub->dda.ray_dir.x > 0) 
		texX = mw - texX -1;
	if (cub->dda.side == true && cub->dda.ray_dir.y < 0)
		texX = mw - texX - 1;
	double step = 1.0 * mh / wall_height;
	double texPos = (wall_start - cub->height / 2 + wall_height / 2) * step;
	for (int y = wall_start; y < wall_end; y++)
	{
		int texY = (int ) texPos;
		char *dst = cub->tex.addr + (texY * cub->tex.line_length + texX * (cub->tex.bits_per_pixel / 8));
		int color = *(unsigned int *)dst;
		if(cub->dda.side == true) 
			color = (color >> 1) & 8355711;
		render_pixel_put(&cub->data, cub->width - ray_count, y, color);
		//render_pixel_put(&cub->data, cub->width - ray_count, y, rgb(0, 0, 255, 0));
		texPos += step;
	}
}