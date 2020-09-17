#ifndef __cgorillas_banana__
#define __cgorillas_banana__ 1

#include <math.h>
#include <stdio.h>
#include <graphics.h>
#include "banana.h"
#include "landscape.h"

extern float wind;

int explosion_kills_gorilla(int x, int y)
{
	//this calculates a square area of impact at the moment.
	//it should be a circle with the radius of explosion
	//to find whether a point in this loop is in the circle or not,
	//calculate the distance from point to center of circle. if distance
	//is lesser than radius, then point is within circle.
	//lots of pithagoras involved in the process mentioned above
	int maxx=x+40, maxy=y+40;
	for(; x<maxx; x++)
	{
		for(; y<maxy; y++)
		{
			if(getpixel(x,y)==BROWN)
				return 1;
			//here we should do a second check:
			//if pixel is brown,
			//  then check if it's within circle.
			//    if it's brown && within circle, ret 1.
			// checking if it's brown is lighter than
			// checking if it's within circle. Order matters.
		}
	}
	return 0;
}

int has_impact(int left, int top, int spin)
{
	int minx=0, miny=0, maxx=0, maxy=0;
	if(top<0)
	{
		return 0;
	}
	switch(spin){
		case 0:
			minx= 4, miny=15,maxx=17, maxy=21;
			break;
		case 1:
			minx= 0, miny= 4,maxx= 6, maxy=17;
			break;
		case 2:
			minx= 4, miny= 0,maxx=17, maxy= 6;
			break;
		case 3:
			minx=15, miny= 4,maxx=21, maxy=17;
			break;
	}
	for(int x=left+minx;x<(left+maxx);x++)
	{
		for(int y=top+miny;y<(top+maxy);y++)
		{
			if(getpixel(x,y)!=BLUE && (x>100 || y>40))
				return 1;
		}
	}
	return 0;
}

int draw_banana(int x, int y, int spin)
{
	if(y<0)
	{
        // if banana is above the visible screen
        // draw arow instead
		if(x>0 && x+20<getmaxx())
		{
			setcolor(YELLOW);
			pieslice(x+20,1,70,110,5);
			delay(200);
			setcolor(BLUE);
			pieslice(x+20,1,70,110,5);
		}
		return 0;
	}
	switch(spin)
	{
		case 0: // u
			setcolor(YELLOW);
			bar(x+ 4, y+15, x+ 5, y+17);
			bar(x+ 5, y+16, x+ 7, y+18);
			bar(x+ 6, y+17, x+15, y+20);
			bar(x+ 9, y+21, x+12, y+21);
			bar(x+14, y+16, x+16, y+18);
			bar(x+16, y+15, x+17, y+17);
			delay(200);
			setcolor(BLUE);
			bar(x+ 4, y+15, x+17, y+21);
			break;
		case 1: // c
			setcolor(YELLOW);
			bar(x+ 4, y+ 4, x+ 6, y+ 5);
			bar(x+ 3, y+ 5, x+ 5, y+ 7);
			bar(x+ 1, y+ 6, x+ 4, y+15);
			bar(x+ 0, y+ 9, x+ 0, y+12);
			bar(x+ 3, y+14, x+ 5, y+16);
			bar(x+ 4, y+16, x+ 6, y+17);
			delay(200);
			setcolor(BLUE);
			bar(x+ 0, y+ 4, x+ 6, y+17);
			break;
		case 2: // n
			setcolor(YELLOW);
			bar(x+ 9, y+ 0, x+12, y+ 0);
			bar(x+ 6, y+ 1, x+15, y+ 4);
			bar(x+ 5, y+ 3, x+ 7, y+ 5);
			bar(x+ 4, y+ 4, x+ 5, y+ 6);
			bar(x+14, y+ 3, x+16, y+ 5);
			bar(x+16, y+ 4, x+17, y+ 6);
			delay(200);
			setcolor(BLUE);
			bar(x+ 4, y+ 0, x+17, y+ 6);
			break;
		case 3: // >
			setcolor(YELLOW);
			bar(x+15, y+ 4, x+17, y+ 5);
			bar(x+16, y+ 5, x+18, y+ 7);
			bar(x+17, y+ 6, x+20, y+15);
			bar(x+16, y+14, x+18, y+16);
			bar(x+15, y+16, x+18, y+17);
			bar(x+21, y+ 9, x+21, y+12);
			delay(200);
			setcolor(BLUE);
			bar(x+15, y+ 4, x+21, y+17);
			break;
	}
	return 0;
}

int draw_explosion(int x, int y)
{
	x+=10;
	y+=10;
	setcolor(WHITE);
	pieslice(x,y,0,360,2);
	delay(100);
	setcolor(LIGHTRED);
	pieslice(x,y,0,360,6);
	setcolor(WHITE);
	pieslice(x,y,0,360,2);
	delay(500);
	setcolor(RED);
	pieslice(x,y,0,360,10);
	setcolor(LIGHTRED);
	pieslice(x,y,0,360,6);
	setcolor(WHITE);
	pieslice(x,y,0,360,2);
	delay(500);
	setcolor(YELLOW);
	pieslice(x,y,0,360,18);
	setcolor(RED);
	pieslice(x,y,0,360,10);
	setcolor(LIGHTRED);
	pieslice(x,y,0,360,6);
	setcolor(WHITE);
	pieslice(x,y,0,360,2);
	delay(1000);
	setcolor(BLUE);
	pieslice(x,y,0,360,18);
	return 0;
}

int throw_banana(int x, int y, float speed, float angle)
{
	float radians = angle*M_PI/180.0;
	int s=0;
	float speed_x = (speed*cos(radians));
	float speed_y = (speed*sin(radians));
	int impact=0;
	int out_of_screen=0;
	while(!(out_of_screen=(x>=getmaxx()||x<0) || (y>=getmaxy())) && !(impact=has_impact(x,y,s)))
	{
		draw_banana(x,y,s);
		x+=speed_x;
		y-=speed_y;
		s++;
		if(s==4)
			s=0;
		speed_y-=GRAVITY;
		if(wind > 0 && speed_x < MAX_WIND_DRAG)
		{
			speed_x += (MAX_WIND_DRAG-speed_x)*wind;
		}
		if(wind < 0 && speed_x > -MAX_WIND_DRAG)
		{
			speed_x += (MAX_WIND_DRAG+speed_x)*wind;
		}
	}
	if(impact)
	{
		draw_explosion(x, y);
		if(explosion_kills_gorilla(x,y))
		{
			printf("KILLED\n");
		}
	}
	else
	{
		printf("OUT\n");
	}
	sleep(2);
	return 0;
}

#endif