#include <stdio.h>
#include <graphics.h>
void floodFill4(int x, int y, int fill_color, int old_color)
{
	int current_color = getpixel(x,y);
	if (current_color == old_color)
	{
		putpixel(x, y, fill_color);
		floodFill4(x + 1, y, fill_color, old_color); //Right
		floodFill4(x - 1, y, fill_color, old_color); //Left
		floodFill4(x, y + 1, fill_color, old_color); //Down
		floodFill4(x, y - 1, fill_color, old_color); //Up
	}
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	int points[] = {200, 100,   //First vertex
	                250, 150,   //Second vertex
	                225, 200,   //Third vertex
	                175, 200,   //Fourth vertex
	                150, 150,   //Fifth vertex
	                200, 100};  //Repeat the first vertex to close the pentagon
	drawpoly(6, points);        //Drawing the pentagon
	floodFill4(200, 150, BLUE, BLACK); //Starting point inside the pentagon
	delay(10000);
	closegraph();
	return 0;
}
