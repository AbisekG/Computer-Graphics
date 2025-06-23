#include <stdio.h>
#include <graphics.h>
void boundaryFill4(int x, int y, int fill_color, int boundary_color)
{
	int current_color = getpixel(x,y);
	if (current_color != boundary_color && current_color != fill_color)
	{
		putpixel(x, y, fill_color);
		boundaryFill4(x + 1, y, fill_color, boundary_color); //Right
		boundaryFill4(x - 1, y, fill_color, boundary_color); //Left
		boundaryFill4(x, y + 1, fill_color, boundary_color); //Down
		boundaryFill4(x, y - 1, fill_color, boundary_color); //Up
	}
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");
	rectangle(100,100,300,300);
	boundaryFill4(150, 150, WHITE, WHITE);
	delay(10000);
	closegraph();
	return 0;
}
