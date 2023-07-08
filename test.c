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
	while(++j <= 800)
	{
		i = -1;
		while(++i <= 900)
		{
			int color = 0;
			t_color c = map(i, j, 900, 800, 0, 0);
			color = c.red << 16 | c.green << 8 | 0;
			mlx_pixel_put(mlx, win, i, j, color);
			// printf("color : %x\t", color);
		}
		// puts("");
	}
	// double x = (2 * 0 / 900) - 1;
	// double y = (2 * 0 / 800) - 1;
	// printf("x = %f, y = %f\n", x, y);
	mlx_loop(mlx);
}
#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y, z;
} Vector3;

typedef struct {
    Vector3 origin;
    Vector3 direction;
} Ray;

typedef struct {
    Vector3 center;
    double radius;
} Sphere;

int intersectRaySphere(Ray ray, Sphere sphere, double *t1, double *t2) {
    Vector3 oc = {ray.origin.x - sphere.center.x, ray.origin.y - sphere.center.y, ray.origin.z - sphere.center.z};
    double a = ray.direction.x * ray.direction.x + ray.direction.y * ray.direction.y + ray.direction.z * ray.direction.z;
    double b = 2 * (oc.x * ray.direction.x + oc.y * ray.direction.y + oc.z * ray.direction.z);
    double c = oc.x * oc.x + oc.y * oc.y + oc.z * oc.z - sphere.radius * sphere.radius;
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        // No intersection
        return 0;
    } else if (discriminant == 0) {
        // One intersection
        *t1 = -b / (2 * a);
        *t2 = *t1;
        return 1;
    } else {
        // Two intersections
        *t1 = (-b + sqrt(discriminant)) / (2 * a);
        *t2 = (-b - sqrt(discriminant)) / (2 * a);
        return 2;
    }
}

int main() {
    Ray ray = {{0, 0, 0}, {1, 0, 0}};
    Sphere sphere = {{2, 0, 0}, 1};
    double t1, t2;

    int numIntersections = intersectRaySphere(ray, sphere, &t1, &t2);
    if (numIntersections > 0) {
        printf("Number of intersections: %d\n", numIntersections);
        printf("Intersection t1: %f\n", t1);
        if (numIntersections == 2) {
            printf("Intersection t2: %f\n", t2);
        }
    } else {
        printf("No intersection\n");
    }

    return 0;
}
