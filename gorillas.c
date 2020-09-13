#define _USE_MATH_DEFINES

#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include <math.h>

using namespace std;

int l_gor_x = 0;
int l_gor_y = 0;
bool stop=false;

float myrand(int min=0, int max=1)
{
	return min + (((rand()+0.0)/(RAND_MAX+0.0))*(max-min));
}

int get_building_color()
{
	int seed = myrand(1,4);
	switch(seed)
	{
		case 1:
			return CYAN;
		case 2:
			return LIGHTRED;
		case 3:
			return LIGHTGRAY;
	}
	// Available colors:
	// BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY,
	// LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
	return RED;
}

int draw_windows_for_building(int left, int width_of_building, int top)
{
	int width_of_window = 6;
	int h_space_between_windows = 6;
	int height_of_window = 10;
	int v_space_between_windows = 8;
	int floor = 10;
	int h_step = width_of_window + h_space_between_windows;
	int v_step = height_of_window + v_space_between_windows;
	int color_of_window = YELLOW;
	int min_padding = 4;
	int padding = ((((width_of_building-min_padding*2)-width_of_window)%h_step)/2)+min_padding;
	//bar(left+padding, top+padding, ((left-1)+width_of_building)-padding, getmaxy()-padding);
	int minx = left+padding;
	int maxx = ((left)+width_of_building)-(padding);
	int x = minx;
	int i = 0;
	while(x < maxx)
	{
		for(int y=top+padding; y<(getmaxy()-floor); y+=v_step)
		{
			if(myrand()>0.3)
				color_of_window = YELLOW;
			else
				color_of_window = DARKGRAY;
			setcolor(color_of_window);
			bar(x,y,x+width_of_window,y+height_of_window);
			i++;
		}
		x+=h_step;
	}
	
	return i;
}

int draw_building(int x, int width_of_building, int height_of_building)
{
	int bottom=getmaxy();
	int left=x+1;
	int right=x+width_of_building;
	int top=height_of_building;
	setcolor(get_building_color());
	bar(left, top, right, bottom);
	draw_windows_for_building(left, width_of_building, top);
	return 0;
}


int draw_gorilla(int h_center_of_building, int top_of_building, bool r_arm_up=false, bool l_arm_up=false)
{
	int x = h_center_of_building - 17;
	int y = top_of_building - 42;
	setcolor(BROWN);
	bar(x+12,    y+ 6,    x+21,    y+13); //head
	bar(x+10,    y+ 8,    x+23,    y+10); //ears
	bar(x+13,    y+14,    x+20,    y+15); //neck

	bar(x+ 7,    y+16,    x+27,    y+23); //torso (high)
	bar(x+10,    y+24,    x+24,    y+31); //torso (low)

	setcolor(BLUE);  
	bar(x+13,    y+ 8,    x+20,    y+ 8); //eyes
	bar(x+14,    y+10,    x+16,    y+10); //nostril (left)
	bar(x+18,    y+10,    x+20,    y+10); //nostril (right)
	bar(x+17,    y+18,    x+17,    y+20); //pectorals 1
	bar(x+11,    y+23,    x+13,    y+23); //pectorals 1
	bar(x+17,    y+18,    x+17,    y+20); //pectorals 1
	bar(x+14,    y+22,    x+15,    y+22); //pectorals 1
	bar(x+16,    y+21,    x+16,    y+21); //pectorals 1
	bar(x+18,    y+21,    x+18,    y+21); //pectorals 1
	bar(x+19,    y+22,    x+20,    y+22); //pectorals 1
	bar(x+21,    y+23,    x+23,    y+23); //pectorals 1

	setcolor(BROWN);
	bar(x+20,    y+32,    x+26,    y+32); //r leg 1
	bar(x+21,    y+33,    x+26,    y+33); //r leg 2
	bar(x+22,    y+34,    x+27,    y+40); //r leg 3
	bar(x+21,    y+41,    x+26,    y+41); //r leg 4

	bar(x+ 8,    y+32,    x+14,    y+32); //l leg 1
	bar(x+ 8,    y+33,    x+13,    y+33); //l leg 2
	bar(x+ 7,    y+34,    x+12,    y+40); //l leg 3
	bar(x+ 8,    y+41,    x+13,    y+41); //l leg 4

	bar(x+ 3,    y+17,    x+ 6,    y+21); //l arm 1
	bar(x+ 2,    y+18,    x+ 5,    y+28); //l arm 2
	bar(x+ 1,    y+19,    x+ 6,    y+21); //l arm 3
	bar(x+ 0,    y+22,    x+ 5,    y+26); //l arm 4
	bar(x+ 3,    y+29,    x+ 7,    y+29); //l arm 5
	bar(x+ 4,    y+30,    x+ 8,    y+30); //l arm 6

	bar(x+26,    y+ 4,    x+30,    y+ 4); //r arm 1
	bar(x+27,    y+ 5,    x+31,    y+ 5); //r arm 2
	bar(x+28,    y+ 6,    x+33,    y+ 8); //r arm 3
	bar(x+29,    y+ 9,    x+34,    y+12); //r arm 4
	bar(x+28,    y+13,    x+33,    y+15); //r arm 5
	bar(x+28,    y+16,    x+32,    y+16); //r arm 6
	bar(x+28,    y+17,    x+31,    y+17); //r arm 7

	return 0;
}

int draw_buildings()
{
	int current_x = -1;
	int width_of_building = 0;
	int height_of_building = 0;
	int max_height_of_building=(getmaxy()*8)/10;
	int num_of_buildings=0;
	int min_width_of_building=36;
	int max_width_of_building=90;
	int last_x=0,last_width=0,last_height=0;
	while(current_x < getmaxx())
	{
		last_x=current_x-width_of_building;
		last_width=width_of_building;
		last_height=height_of_building;
		num_of_buildings++;
		width_of_building = myrand(min_width_of_building, max_width_of_building);
		height_of_building = getmaxy()-(max_height_of_building*myrand(2,10))/10;
		if(current_x+width_of_building+min_width_of_building > getmaxx())
		{
			width_of_building += min_width_of_building;
		}
		if(current_x+width_of_building > getmaxx())
		{
			width_of_building = getmaxx() - current_x;
		}
		draw_building(current_x, width_of_building, height_of_building);
		if(num_of_buildings==2)
		{
			l_gor_x=current_x+(width_of_building/2);
			l_gor_y=height_of_building;
			draw_gorilla(current_x+(width_of_building/2),height_of_building);
		}
		current_x += width_of_building;
	}
	draw_gorilla(last_x+(last_width/2),last_height);
	return num_of_buildings;
}

bool explosion_kills_gorilla(int x, int y)
{
	//this calculates a square area of impact at the moment.
	//it should be a circle with the radius of explosion
	//to find whether a point in this loop is in the circle or not,
	//calculate the distance from point to center of circle. if distance
	//is lesser than radius, then point is within circle.
	//lots of pithagoras involved in the process mentioned above
	int maxx=x+40, maxy=y+40;
	for(x; x<maxx;x++)
	{
		for(y;y<maxy;y++)
		{
			if(getpixel(x,y)==BROWN)
				return true;
			//here do another check. if pixel is brown,
			//then check if it's within circle.
			//if it's brown && within circle, ret true.
			//order matters.
		}
	}
	return false;
}

bool has_impact(int left, int top, int spin=0)
{
	int minx=0, miny=0, maxx=0, maxy=0;
	if(top<0)
	{
		return false;
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
			if(getpixel(x,y)!=BLUE)
				return true;
		}
	}
	return false;
}

int draw_banana(int x=200, int y=80, int spin=0)
{
	if(y<0)
	{
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
	bool impact=false;
	bool out_of_screen=false;
	while(!(out_of_screen=(x>=getmaxx()||x<0) || (y>=getmaxy())) && !(impact=has_impact(x,y,s)))
	{
		draw_banana(x,y,s);
		x+=speed_x;
		y-=speed_y;
		s++;
		if(s==4)
			s=0;
		speed_y-=0.4;
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
}

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	srand(time(0));
	cleardevice();
	setbkcolor(BLUE);
	draw_buildings();
	sleep(3);
	char angle_str[3];
	char speed_str[3];
	printf("\nAngle:");
	angle_str[0]=getch();
	printf("%c", angle_str[0]);
	angle_str[1]=getch();
	printf("%c.\n", angle_str[1]);
	printf("Speed:");
	speed_str[0]=getch();
	printf("%c", speed_str[0]);
	speed_str[1]=getch();
	printf("%c.\n", speed_str[1]);
	angle_str[2]=0;
	speed_str[2]=0;
	float angle = atoi(angle_str);
	float speed = atoi(speed_str);
	throw_banana(l_gor_x, l_gor_y-(42+21), speed, angle);
	return 0;
}


