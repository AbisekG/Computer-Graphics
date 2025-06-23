#include <graphics.h>
#include <conio.h>
#include <stdio.h>

// Function to plot symmetric points of the ellipse
void plotPoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, BLACK);  // Quadrant 1
    putpixel(xc - x, yc + y, BLACK);  // Quadrant 2
    putpixel(xc + x, yc - y, BLACK);  // Quadrant 4
    putpixel(xc - x, yc - y, BLACK);  // Quadrant 3
}

// Function to draw an ellipse using Midpoint Algorithm
void drawEllipse(int xc, int yc, int rx, int ry) {
    float dx, dy, d1, d2;
    int x = 0, y = ry;

    // Region 1
    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    while (dx < dy) {
        plotPoints(xc, yc, x, y);
        if (d1 < 0) {
            x++;
            dx += 2 * ry * ry;
            d1 += dx + (ry * ry);
        } else {
            x++;
            y--;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            d1 += dx - dy + (ry * ry);
        }
    }

    // Region 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);
    while (y >= 0) {
        plotPoints(xc, yc, x, y);
        if (d2 > 0) {
            y--;
            dy -= 2 * rx * rx;
            d2 += (rx * rx) - dy;
        } else {
            y--;
            x++;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            d2 += dx - dy + (rx * rx);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    int xc, yc, rx, ry;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Set background color to grey
    setbkcolor(LIGHTGRAY);
    cleardevice(); // Apply background color

    // Set drawing color to black
    setcolor(BLACK);

    // User input
    printf("Enter center coordinates (x, y): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter x-radius: ");
    scanf("%d", &rx);
    printf("Enter y-radius: ");
    scanf("%d", &ry);

    // Draw ellipse using midpoint algorithm
    drawEllipse(xc, yc, rx, ry);

    getch();  // Wait for key press
    closegraph(); // Close graphics mode
    return 0;
}

