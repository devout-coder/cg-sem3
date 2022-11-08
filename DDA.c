// DDA

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

void main() 
{
    int gdriver = DETECT,gmode;
    int x1,y1,x2,y2,i,steps,dx,dy;
    float xn, yn;
    clrscr();
    initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
    printf("Enter starting point : ");
    scanf("%d%d",&x1,&y1);
    printf("Enter ending point : ");
    scanf("%d%d",&x2,&y2);
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(dx) > abs(dy)) {
        steps = dx;
    }
    else {
        steps = dy;
    }
    xn = (float)dx/(float)steps;
    yn = (float)dy/(float)steps;

    for(i = 1; i <= steps; i++){
        putpixel(x1,y1,RED);
        x1 = x1 + xn;
        y1 = y1 + yn;
    }
    clrscr();
    closegraph();
}
