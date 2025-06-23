#include <stdio.h>
#include <graphics.h>
void floodFill8(int x, int y, int fill_color, int old_color)
{
	int current_color = getpixel(x,y);
	if (current_color == old_color)
	{
		putpixel(x, y, fill_color);
		floodFill8(x + 1, y, fill_color, old_color); //Right
		floodFill8(x - 1, y, fill_color, old_color); //Left
		floodFill8(x, y + 1, fill_color, old_color); //Down
		floodFill8(x, y - 1, fill_color, old_color); //Up
		floodFill8(x + 1, y + 1, fill_color, old_color); //Down-Right
		floodFill8(x - 1, y + 1, fill_color, old_color); //Down-Left
		floodFill8(x + 1, y - 1, fill_color, old_color); //Up-Right
		floodFill8(x - 1, y - 1, fill_color, old_color); //Up-Left
	}
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	/*rectangle(100, 100, 200, 200);
	floodFill8(150, 150, YELLOW, BLACK);*/
	drawpoly(6, points);        //Drawing the pentagon
	floodFill8(200, 150, BLUE, BLACK);
	delay(10000);
	closegraph();
	return 0;
}
