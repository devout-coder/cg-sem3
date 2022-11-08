#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
void koch(int x1, int y1, int x2, int y2, int it)
{
float angle = 90 * M_PI / 180;
int x3 = (2 * x1 + x2) / 3;
int y3 = (2 * y1 + y2) / 3;
int x4 = (x1 + 2 * x2) / 3;
int y4 = (y1 + 2 * y2) / 3;
int x = x3 + (x4 - x3) * cos(angle) + (y4 - y3) * sin(angle);
int y = y3 - (x4 - x3) * sin(angle) + (y4 - y3) * cos(angle);
if (it > 0)
{
koch(x1, y1, x3, y3, it - 1);
koch(x3, y3, x, y, it - 1);
koch(x, y, x4, y4, it - 1);
koch(x4, y4, x2, y2, it - 1);
}
else
{
line(x1, y1, x3, y3);
line(x3, y3, x, y);
line(x, y, x4, y4);
line(x4, y4, x2, y2);
}
}

int main(void)
{
int gd = DETECT, gm, i, n, x1 = 100, y1 = 100, x2 = 400, y2 = 400;
initgraph(&gd, &gm,"C:\\TURBOC3\\BGI");
printf("Enter number of interations: ");
scanf("%d", &n);
for (i = 0; i < n; i++)
{
cleardevice();
koch(x1, y1, x2, y2, i);
getch();
}
return 0;
}
