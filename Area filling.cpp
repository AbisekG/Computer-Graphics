#include <stdio.h>
#include <graphics.h>

// 8-connected Boundary Fill Algorithm
void boundaryFill8(int x, int y, int fill_color, int boundary_color) {
    int current_color = getpixel(x, y);
    if (current_color != boundary_color && current_color != fill_color) {
        putpixel(x, y, fill_color);
        boundaryFill8(x + 1, y, fill_color, boundary_color);
        boundaryFill8(x - 1, y, fill_color, boundary_color);
        boundaryFill8(x, y + 1, fill_color, boundary_color);
        boundaryFill8(x, y - 1, fill_color, boundary_color);
        boundaryFill8(x + 1, y + 1, fill_color, boundary_color);
        boundaryFill8(x - 1, y + 1, fill_color, boundary_color);
        boundaryFill8(x + 1, y - 1, fill_color, boundary_color);
        boundaryFill8(x - 1, y - 1, fill_color, boundary_color);
    }
}

// 4-connected Boundary Fill Algorithm
void boundaryFill4(int x, int y, int fill_color, int boundary_color) {
    int current_color = getpixel(x, y);
    if (current_color != boundary_color && current_color != fill_color) {
        putpixel(x, y, fill_color);
        boundaryFill4(x + 1, y, fill_color, boundary_color);
        boundaryFill4(x - 1, y, fill_color, boundary_color);
        boundaryFill4(x, y + 1, fill_color, boundary_color);
        boundaryFill4(x, y - 1, fill_color, boundary_color);
    }
}

// 4-connected Flood Fill Algorithm
void floodFill4(int x, int y, int fill_color, int old_color) {
    int current_color = getpixel(x, y);
    if (current_color == old_color && current_color != fill_color) {
        putpixel(x, y, fill_color);
        floodFill4(x + 1, y, fill_color, old_color);
        floodFill4(x - 1, y, fill_color, old_color);
        floodFill4(x, y + 1, fill_color, old_color);
        floodFill4(x, y - 1, fill_color, old_color);
    }
}

// 8-connected Flood Fill Algorithm
void floodFill8(int x, int y, int fill_color, int old_color) {
    int current_color = getpixel(x, y);
    if (current_color == old_color && current_color != fill_color) {
        putpixel(x, y, fill_color);
        floodFill8(x + 1, y, fill_color, old_color);
        floodFill8(x - 1, y, fill_color, old_color);
        floodFill8(x, y + 1, fill_color, old_color);
        floodFill8(x, y - 1, fill_color, old_color);
        floodFill8(x + 1, y + 1, fill_color, old_color);
        floodFill8(x - 1, y + 1, fill_color, old_color);
        floodFill8(x + 1, y - 1, fill_color, old_color);
        floodFill8(x - 1, y - 1, fill_color, old_color);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    setbkcolor(WHITE);
    cleardevice();

    // Draw rectangle
    setcolor(BLACK);  // Ensure rectangle is visible on a white background
    rectangle(100, 100, 200, 200);
    
    int choice;
    printf("Choose filling algorithm:\n");
    printf("1. 4-Connected Boundary Fill\n");
    printf("2. 8-Connected Boundary Fill\n");
    printf("3. 4-Connected Flood Fill\n");
    printf("4. 8-Connected Flood Fill\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            boundaryFill4(150, 150, RED, BLACK);
            break;
        case 2:
            boundaryFill8(150, 150, BLUE, BLACK);
            break;
        case 3:
            floodFill4(150, 150, GREEN, WHITE);  // Correct old_color
            break;
        case 4:
            floodFill8(150, 150, YELLOW, WHITE);  // Correct old_color
            break;
        default:
            printf("Invalid choice\n");
    }

    getch();
    closegraph();
    return 0;
}

