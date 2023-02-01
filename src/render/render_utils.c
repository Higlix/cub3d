#include "cub.h"

void	render_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	render_line_put(t_game *cub, int bx, int by, int ex, int ey, int color)
{
	double deltaX;
	double deltaY;
	double pixelY;
	double pixelX;
	int pixels;
	
	deltaX = ex - bx;
	deltaY = ey - by;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	pixelX = bx;
	pixelY = by;
	while (pixels)
	{
    	render_pixel_put(&cub->data, pixelX, pixelY, color);
    	pixelX += deltaX;
    	pixelY += deltaY;
    	--pixels;
	}
}

void	render_cell_put(t_game *cub, int x, int y, int color)
{
	int i;
	int j;

	i = x * cub->cell_size;
	while (i < (x * cub->cell_size) + cub->cell_size - 1)
	{
		j = y * cub->cell_size;
		while (j < (y * cub->cell_size) + cub->cell_size - 1)
		{
			render_pixel_put(&cub->data, i, j, color);
			j++;
		}
		i++;
	}
}

static void	render_cell_clean(t_game *cub, int x, int y, int color)
{
	int i;
	int j;

	i = x * cub->cell_size;
	while (i < (x * cub->cell_size) + cub->cell_size)
	{
		j = y * cub->cell_size;
		while (j < (y * cub->cell_size) + cub->cell_size)
		{
			render_pixel_put(&cub->data, i, j, color);
			j++;
		}
		i++;
	}
}

void	render_reset_image(t_game *cub, int color)
{
	int i;
	int j;

	i = -1;
    while (cub->map.map[++i])
    {
        j = -1;
        while (cub->map.map[i][++j])
			render_cell_clean(cub, j + 1, i + 1, color);
    }
}