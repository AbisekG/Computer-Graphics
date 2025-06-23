#include <graphics.h>
#include <stdio.h>
#include <math.h>

// Function to draw a line using the DDA algorithm
void drawLineDDA(int x1, int y1, int x2, int y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    int steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy); // Determine the number of steps

    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    float x = x1, y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), BLACK); // Plot the rounded pixel
        delay(5);                            // Add delay to visualize drawing
        x += xIncrement;                     // Increment x
        y += yIncrement;                     // Increment y
    }
}

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    // Initialize graphics mode
    initgraph(&gd, &gm, NULL);

    // Set the background to white and drawing color to black
    setbkcolor(WHITE);
    cleardevice();
    setcolor(BLACK);

    // Input coordinates for the line
    printf("Enter the value of x1 and y1 : ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the value of x2 and y2:");
    scanf("%d %d", &x2, &y2);

    // Draw the line using DDA algorithm
    drawLineDDA(x1, y1, x2, y2);

    // Wait for a key press and close graphics
    getch();
    closegraph();

    return 0;
}

