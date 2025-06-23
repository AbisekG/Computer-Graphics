#include <graphics.h>
#include <stdio.h>
#include <math.h>

// Function to draw a line based on BLA
void drawLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    if (dx == 0) { // Vertical line
        int y = y1;
        while (y <= y2) {
            putpixel(x1, y, BLACK);
            y++;
        }
        return;
    }

    float m = (float)dy / dx;

    if (m > 0 && fabs(m) <= 1) { // Case 1: m = +ve and |m| <= 1
        printf("Case 1: m = +ve and |m| <= 1\n");
        int y = y1;
        int p = 2 * dy - dx;
        for (int x = x1; x <= x2; x++) {
            putpixel(x, y, BLACK);
            delay(5); // Add delay to visualize drawing
            if (p >= 0) {
                y++;
                p += 2 * (dy - dx);
            } else {
                p += 2 * dy;
            }
        }
    } else if (m > 0 && fabs(m) > 1) { // Case 2: m = +ve and |m| > 1
        printf("Case 2: m = +ve and |m| > 1\n");
        int x = x1;
        int p = 2 * dx - dy;
        for (int y = y1; y <= y2; y++) {
            putpixel(x, y, BLACK);
            delay(5);
            if (p >= 0) {
                x++;
                p += 2 * (dx - dy);
            } else {
                p += 2 * dx;
            }
        }
    } else if (m < 0 && fabs(m) <= 1) { // Case 3: m = -ve and |m| <= 1
        printf("Case 3: m = -ve and |m| <= 1\n");
        int y = y1;
        int p = 2 * dy + dx;
        for (int x = x1; x <= x2; x++) {
            putpixel(x, y, BLACK);
            delay(5);
            if (p <= 0) {
                y--;
                p += 2 * (dy + dx);
            } else {
                p += 2 * dy;
            }
        }
    } else if (m < 0 && fabs(m) > 1) { // Case 4: m = -ve and |m| > 1
        printf("Case 4: m = -ve and |m| > 1\n");
        int x = x1;
        int p = 2 * dx + dy;
        for (int y = y1; y >= y2; y--) {
            putpixel(x, y, BLACK);
            delay(5);
            if (p <= 0) {
                x++;
                p += 2 * (dx + dy);
            } else {
                p += 2 * dx;
            }
        }
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

    printf("Enter the initial point (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the final point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    drawLine(x1, y1, x2, y2);

    // Wait for a key press and close graphics
    getch();
    closegraph();

    return 0;
}

