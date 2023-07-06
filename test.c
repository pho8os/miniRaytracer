#include<mlx.h>
#include<math.h>
#include<stdio.h>

typedef struct {
    int red;
    int green;
} t_color;

t_color map(int x, int y, int windowWidth, int windowHeight, int startx, int starty) {
    t_color color;
    
    color.red = (((x - startx) * 255)) / ((windowWidth) - startx);
    color.green = ((y - starty) * 255) / ((windowHeight) - starty);
    
    return color;
}

int main()
{
	void *mlx;
	mlx = mlx_init();
	void *win = mlx_new_window(mlx, 900, 800, "test");
	int i, j = -1;
	while(++j <= 600)
	{
		i = 224;
		while(++i <= 675)
		{
			int color = 0;
			t_color c = map(i, j, 675, 600, 200, 200);
			color = c.red << 16 | c.green << 8 | 0;
			mlx_pixel_put(mlx, win, i, j, color);
		}
		

	}
	// double x = (2 * 0 / 900) - 1;
	// double y = (2 * 0 / 800) - 1;
	// printf("x = %f, y = %f\n", x, y);
	mlx_loop(mlx);
}