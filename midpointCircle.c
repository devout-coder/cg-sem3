// Midpoint Circle 
// Center of circle = 300, 400
// Radius = 100

#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void display(int xc,int yc,int x, int y) {
    putpixel(xc+x,yc+y,3);
    putpixel(xc+y,yc+x,3);
    putpixel(xc-y,yc+x,3);
    putpixel(xc-x,yc+y,3);
    putpixel(xc-x,yc-y,3);
    putpixel(xc-y,yc-x,3);
    putpixel(xc+y,yc-x,3);
    putpixel(xc+x,yc-y,3);
}

void main() {
    int gdriver = DETECT, gmode;
    int xc,yc,x,y,r,d;
    clrscr();
    initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
    printf("Enter center of circle : ");
    scanf("%d%d",&xc,&yc);
    printf("Enter radius of circle :");
    scanf("%d",&r);
    x = 0;
    y = r;
    d = 1 - r;
    do {
       display(xc,yc,x,y);
       if(d < 0) {
        d = d + 2*x + 1;
       }
       else {
        y = y - 1;
        d = d + 2*x - 2*y +1;
       }
       x = x + 1;

    }while(x < y);

    getch();
    closegraph();

}

