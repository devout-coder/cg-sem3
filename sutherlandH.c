#include <stdio.h>
#include <graphics.h>

int main()
{
    int gd = DETECT, gm, n, *x, i, k = 0;
    int w[] = {220, 140, 420, 140, 420, 340, 220, 340, 220, 140};
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    setcolor(RED);
    drawpoly(5, w);
    printf("Enter the no. of vertices of polygon: ");
    scanf("%d", &n);
    x = malloc(n * 2 + 1);
    printf("Enter the coordinates of points: ");
    k = 0;
    for (i = 0; i < n * 2; i += 2)
    {
        printf("(x%d y%d): ", k, k);
        scanf("%d %d", &x[i], &x[i + 1]);
        k++;
    }
    x[n * 2] = x[0];
    x[n * 2 + 1] = x[1];
    setcolor(WHITE);
    drawpoly(n + 1, x);
    printf("\nPress any key to clip the polygon...");
    getch();
    setcolor(RED);
    drawpoly(5, w);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(2, 2, RED);
    printf("\nThis is the clipped polygon");
    getch();
    return 0;
}