#include <stdio.h>
#include <graphics.h>
void boundaryFill8(int x, int y, int fill_color, int boundary_color)
{
	int current_color = getpixel(x,y);
	if (current_color != boundary_color && current_color != fill_color)
	{
		putpixel(x, y, fill_color);
		boundaryFill8(x + 1, y, fill_color, boundary_color);      //Right
		boundaryFill8(x - 1, y, fill_color, boundary_color);      //Left
		boundaryFill8(x, y + 1, fill_color, boundary_color);      //Down
		boundaryFill8(x, y - 1, fill_color, boundary_color);      //Up
		boundaryFill8(x + 1, y + 1, fill_color, boundary_color);  //Top-Right
		boundaryFill8(x - 1, y + 1, fill_color, boundary_color);  //Down-Left
		boundaryFill8(x + 1, y - 1, fill_color, boundary_color);  //Down-Right
		boundaryFill8(x - 1, y - 1, fill_color, boundary_color);  //Up-Left
	}
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	rectangle(100, 100, 300, 300);
	boundaryFill8(150, 150, WHITE, WHITE);
	delay(10000);
	closegraph();
	return 0;
}
