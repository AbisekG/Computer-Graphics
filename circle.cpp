#include <stdio.h>
#include <graphics.h>

void plotpoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, BLACK);
    putpixel(xc - x, yc + y, BLACK);
    putpixel(xc + x, yc - y, BLACK);
    putpixel(xc - x, yc - y, BLACK);
    putpixel(xc + y, yc + x, BLACK);
    putpixel(xc - y, yc + x, BLACK);
    putpixel(xc + y, yc - x, BLACK);
    putpixel(xc - y, yc - x, BLACK);
}

void drawcircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 1 - r;

    plotpoints(xc, yc, x, y);

    while (x <= y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
        plotpoints(xc, yc, x, y);
    }
}

int main() {
    int xc, yc, r;
    
    printf("Enter the center of the circle: ");
    scanf("%d %d", &xc, &yc);
    
    printf("Enter the radius of the circle: ");
    scanf("%d", &r);
    
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    setbkcolor(WHITE);  // Set background color to white
    cleardevice();       // Clear screen to apply white background

    drawcircle(xc, yc, r);

    delay(10000);
    closegraph();
    
    return 0;
}

