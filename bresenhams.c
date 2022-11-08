#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

void drawline(int x1,int y1,int x2,int y2) {
    int dx,dy,p,x,y;
    dx = x2 - x1;
    dy = y2 - y1;
    p = 2*dy - dx;
    x = x1;
    y = y1;

    while(x < x2) {
        if(p >= 0) {
            putpixel(x,y,7);
            y = y + 1;
            p = p + 2*dy - 2*dx;
        }
        else {
            putpixel(x,y,7);
            p = p + 2*dy;
        }
        x = x + 1;
    }
}


void main() {
    int gdriver = DETECT, gmode;
    int x1,y1,x2,y2;
    clrscr();
    initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
    printf("Enter strarting point : ");
    scanf("%d%d",&x1,&y1);
    printf("Enter ending point : ");
    scanf("%d%d",&x2,&y2);
    drawline(x1,y1,x2,y2);
    getch();
    closegraph();

}