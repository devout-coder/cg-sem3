#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void boundaryFill(int x,int y,int fillColor,int bColor){
    if((getpixel(x,y)!=fillColor)&&(getpixel(x,y)!=bColor)){
        putpixel(x,y,bColor);
        boundaryFill(x+1,y,fillColor,bColor);
        boundaryFill(x,y+1,fillColor,bColor);
        boundaryFill(x-1,y,fillColor,bColor);
        boundaryFill(x,y-1,fillColor,bColor);
    }
}

void floodFill(int x,int y,int oldColor, int newColor){
    if(getpixel(x,y)==oldColor){
        putpixel(x,y,newColor);
        floodFill(x+1,y,oldColor,newColor);
        floodFill(x,y+1,oldColor,newColor);
        floodFill(x-1,y,oldColor,newColor);
        floodFill(x,y-1,oldColor,newColor);
    }
}

void main() {
    int gdriver = DETECT, gmode;
    int x,y,p1,p2,p3,p4,fillColor,bColor,oldColor,newColor,choice;
    clrscr();
    initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
    printf("Enter the dimensions of rectangle : ");
    scanf("%d%d%d%d",&p1,&p2,&p3,&p4);

    printf("Enter x and y to be filled : ");
    scanf("%d%d",&x,&y);

    printf("Choose an option:\n1.Boundary fill\n2. Flood fill\n\nYour choice: ");
    scanf("%d",&choice);

    switch(choice) {
      case 1: {
        printf("Boundary fill \n");
        printf("\n Enter fillColor,bColor value to be filled");
        scanf("%d%d",&bColor,&fillColor);
        rectangle(p1,p2,p3,p4);
        boundaryFill(x,y,fillColor,bColor);
        break;
      }  

      case 2: {
        printf("flood fill \n");
        printf("\n Enter oldColor,newColor value to be filled");
        scanf("%d%d",&oldColor,&newColor);
        rectangle(p1,p2,p3,p4);
        floodFill(x,y,oldColor,newColor);
        break;
      }
    }
}