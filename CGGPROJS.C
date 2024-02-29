#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include <graphics.h>

void dda(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps, k;
    float xIncrement, yIncrement, x = x1, y = y1;

    if (abs(dx) > abs(dy)) {
	steps = abs(dx);
    } else {
	steps = abs(dy);
    }

    xIncrement = (float)dx / (float)steps;
    yIncrement = (float)dy / (float)steps;

    putpixel((int) floor(x), (int) floor(y), WHITE);

    for (k = 0; k < steps; k++) {
	x += xIncrement;
	y += yIncrement;
	putpixel((int) floor(x), (int) floor(y), WHITE);
    }
}




void bresnln(int x1, int y1, int x2, int y2) {
int dx = abs(x2 - x1);
int dy = abs(y2 - y1);
int sx = (x1 < x2) ? 1 : -1;
int sy = (y1 < y2) ? 1 : -1;
int err = dx - dy;
int e2;
while (x1 != x2 || y1 != y2) {
putpixel(x1, y1, WHITE);
e2 = 2 * err;
if (e2 > -dy) {
err -= dy;
x1 += sx;
}
if (e2 < dx) {
err += dx;
y1 += sy;
}

}
}



void midptcircle(int x, int y, int radius) {
int x1, y1;
int p;
x1 = 0;
y1 = radius;
p = 1 - radius;
while (x1 <= y1) {
putpixel(x + x1, y + y1, WHITE);
putpixel(x - x1, y + y1, WHITE);
putpixel(x + x1, y - y1, WHITE);
putpixel(x - x1, y - y1, WHITE);
putpixel(x + y1, y + x1, WHITE);
putpixel(x - y1, y + x1, WHITE);
putpixel(x + y1, y - x1, WHITE);
putpixel(x - y1, y - x1, WHITE);

if (p < 0) {
p = p + 2 * x1 + 1;
} else {
p = p + 2 * (x1 - y1) + 1;
y1--;
}
x1++;
}
}


void bresncircle(int x,int y,int r)
{
int i=0,j=r,p=3-2*r;
while(i<=j)
{
putpixel(x+i,y+j,WHITE);
putpixel(x-i,y-j,WHITE);
putpixel(x+j,y+i,WHITE);
putpixel(x-j,y-i,WHITE);
putpixel(x-i,y+j,WHITE);
putpixel(x+i,y-j,WHITE);
putpixel(x-j,y+i,WHITE);
putpixel(x+j,y-i,WHITE);
if(p<0)
{
i++;
p=p+4*i+6;
}
else
{
i++;
j--;
p=p+4*(i-j)+10;
}
}
}


int main(){
 int gd = DETECT, gm;
 initgraph(&gd, &gd, "c:\\turboc3\\bgi");

 //mountain
 bresnln(0, 220, 190, 30);
 bresnln(190, 30, 400,220);
 bresnln(0, 220, 400, 220);
 bresnln(335,160,425,75);
 bresnln(425, 75, 548, 160);
 bresnln(378, 200, 650, 200);
 bresnln(475, 198, 650, 107);

setfillstyle(9, 6);
floodfill(100, 150, WHITE);
setfillstyle(9, 6);
floodfill(400, 100, WHITE);


// river
bresnln(450, 200, 530, 235);
dda(530, 235, 530, 250);
bresnln(530, 235, 420, 283);
bresnln(530, 250, 460, 265);
bresnln(420, 283, 530, 283);
dda(530, 283, 530, 310);
bresnln(530, 283, 310, 495);
bresnln(530, 310, 468, 344);
arc(550,450,30,160,15);
arc(450,450,30,160,20);
arc(585,375,30,160,10);
arc(500,350,30,160,10);
arc(600,250,30,160,10);
arc(555,345,30,160,15);
setfillstyle(9, BLUE);
floodfill(550, 250, WHITE);

//Hut
dda(400, 253, 400, 275);
dda(400, 275, 330, 295);
dda(330, 295, 330, 248);
dda(330, 295, 290, 295);
dda(290, 295, 290, 252);
dda(300, 295, 300, 270);
dda(320, 295, 320, 270);
dda(320, 270, 300, 270);
dda(420, 250, 390, 230);
dda(390, 230, 310, 235);
dda(310, 235, 350, 260);
dda(420, 250, 350, 260);
dda(310, 235, 280, 260);

setfillstyle(3, 6);
floodfill(395, 235, WHITE);
setfillstyle(10, 6);
floodfill(310, 280, WHITE);
setfillstyle(9, 8);
floodfill(310, 260, WHITE);
setfillstyle(9, 8);
floodfill(390, 265, WHITE);


setfillstyle(6, GREEN);
floodfill(290, 400, WHITE);


//cycle
dda(240, 400, 273, 400);
dda(265, 380, 300, 380);
dda(240, 400, 265, 380);
dda(300, 380, 275, 400);
dda(315, 399, 290, 365);
dda(290, 365, 280, 364);
dda(260, 375, 270, 375);
midptcircle(315, 400, 18);
bresncircle(240, 400, 18);


bresnln(140, 340, 173, 340);
bresnln(165, 320, 200, 320);
bresnln(140, 340, 165, 320);
bresnln(200, 320, 175, 340);
dda(215, 339, 190, 305);
bresnln(190, 305, 180, 304);
bresnln(160, 315, 170, 315);
midptcircle(215, 340, 18);
bresncircle(140, 340, 18);



setfillstyle(6, GREEN);
floodfill(315, 400, WHITE);
setfillstyle(6, GREEN);
floodfill(300, 300, WHITE);


//sun
arc(335, 140, 19, 162, 36);
dda(300, 65, 315, 95);
dda(331, 50, 331, 95);
dda(365, 65, 350, 95);
dda(389, 83, 367, 105);
dda(280, 85, 300, 105);
arc(530,50,30,160,10);
arc(548,50,30,160,10);
arc(500,70,30,160,10);
arc(518,70,30,160,10);
arc(530,100,30,160,10);
arc(548,100,30,160,10);
arc(570,80,30,160,10);
arc(588,80,30,160,10);

setfillstyle(1, 14);
floodfill(340, 130, WHITE);
setfillstyle(1, 9);
floodfill(0,0, WHITE);

getch();
 closegraph();
 return 0;
}