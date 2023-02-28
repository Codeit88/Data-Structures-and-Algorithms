#include<graphics.h>
const int row=600;
const int col=600;
void movepac();
void gamestart();
void borders();
main(){
	initwindow(row,col,"PACMAN");
	gamestart();
	cleardevice();
	   borders();
	   movepac();
	getch();
}
void movepac(){
	while(1){
	int x=300;
	int y=300;
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL,YELLOW);
	circle(x,y,20);
	floodfill(300,300,YELLOW);
	//setcolor(BLACK);
	//setfillstyle(SOLID_FILL,BLACK);
	//line(300,300,320,290);
	//line(300,300,320,310);
	//arc(320,320,0,90,20);
	//floodfill(305,100,BLACK);
		if(GetAsyncKeyState(VK_RIGHT) )
	{
		x +=10;
	}
	if(GetAsyncKeyState(VK_LEFT) )
	{
		x -=10;
	}
	delay(30);
	cleardevice();
}
}
void gamestart()
{
	setcolor(WHITE);
	settextstyle(EUROPEAN_FONT, HORIZ_DIR, 6);
	outtextxy(70, 200, "Starting Game...");
	//delay(4000);
	
}
void borders(){
	setcolor(WHITE);
	line(10,10,590,10);
	line(10,10,10,590);
	line(590,590,590,10);
	line(590,590,10,590);
}
