#include <stdio.h>
#include <graphics.h>
#include <math.h>

// Function to convert degrees to radians
float degrees_to_radians(float degrees) {
    return degrees * (M_PI / 180.0);
}

// Main function
int main() {
    // Initialize graphics variables
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
//initwindow(500,500,"3D transformation");

    // Initial coordinates for the 3D bar
    int x1 = 50, y1 = 50, x2 = 80, y2 = 80;

    // Variables for transformations
    int tx, ty;
    float sx, sy, angle, shx, shy;

    // Draw the initial 3D bar
    outtextxy(x2+35, y2, "Before transformation");
    bar3d(x1, y1, x2, y2, 25, 1);
    delay(2000);

    // Display menu for the user
    int choice;
    printf("Choose the transformation:\n");
    printf("1. Translation\n");
    printf("2. Scaling\n");
    printf("3. Rotation\n");
    printf("4. Reflection\n");
    printf("5. Shearing\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            // Get the translation factors from the user
            printf("Enter the translation factors (tx ty): ");
            scanf("%d %d", &tx, &ty);

            // Translate the bar
            x1 += tx;
            y1 += ty;
            x2 += tx;
            y2 += ty;

            // Draw the translated 3D bar
            outtextxy(x2, y2 + 35, "After translation");
            bar3d(x1, y1, x2, y2, 25, 1);
            break;
        }
        case 2: {
            // Get the scaling factors from the user
            printf("Enter the scaling factors (sx sy): ");
            scanf("%f %f", &sx, &sy);

            // Scale the bar (assuming the origin is the pivot point)
            x1 = (int)(x1 * sx); y1 = (int)(y1 * sy);
            x2 = (int)(x2 * sx); y2 = (int)(y2 * sy);

            // Draw the scaled 3D bar
            setcolor(GREEN);
            outtextxy(x2, y2 + 35, "After scaling");
            bar3d(x1, y1, x2, y2, 25, 1);
            break;
        }
        case 3: {
            // Get the rotation angle from the user
            printf("Enter the rotation angle (in degrees): ");
            scanf("%f", &angle);

            // Convert the angle to radians
            float radian = degrees_to_radians(angle);

            // Rotate the bar around the origin
            int new_x1 = (int)(x1 * cos(radian) - y1 * sin(radian));
            int new_y1 = (int)(x1 * sin(radian) + y1 * cos(radian));
            int new_x2 = (int)(x2 * cos(radian) - y2 * sin(radian));
            int new_y2 = (int)(x2 * sin(radian) + y2 * cos(radian));

            // Draw the rotated 3D bar
            setcolor(BLUE);
            outtextxy(new_x2, new_y2 + 35, "After rotation");
            bar3d(new_x1, new_y1, new_x2, new_y2, 25, 1);
            break;
        }
        case 4: {
            // Reflect the bar about the x-axis
            x1 = -x1; x2 = -x2;

            // Draw the reflected 3D bar
            setcolor(RED);
            outtextxy(x2, y2 + 35, "After reflection");
            bar3d(x1, y1, x2, y2, 25, 1);
            break;
        }
        case 5: {
            // Get the shearing factors from the user
            printf("Enter the shearing factors (shx shy): ");
            scanf("%f %f", &shx, &shy);

            // Shear the bar
            x1 = x1 + shx * y1;
            x2 = x2 + shx * y2;
            y1 = y1 + shy * x1;
            y2 = y2 + shy * x2;

            // Draw the sheared 3D bar
            setcolor(YELLOW);
            outtextxy(x2, y2 + 35, "After shearing");
            bar3d(x1, y1, x2, y2, 25, 1);
            break;
        }
        default:
            printf("Invalid choice\n");
    }

    // Conclude the program
    delay(100000);
    closegraph();
    return 0;
}
