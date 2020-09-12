#include <iostream>
#include <stdio.h>
#include <graphics.h>

using namespace std;

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
	int x=h_center_of_building-17;
	int y=top_of_building-42;
	setcolor(BROWN);
	bar(x+12,    y+ 6,    x+21,    y+13); //head
	bar(x+10,    y+ 8,    x+23,    y+10); //ears
	setcolor(BLUE);  
	bar(x+13,    y+ 8,    x+20,    y+ 8); //eyes
	bar(x+14,    y+10,    x+16,    y+10); //nostril (left)
	bar(x+18,    y+10,    x+20,    y+10); //nostril (right)
	setcolor(BROWN);
	bar(x+13,    y+14,    x+20,    y+15); //neck

	bar(x+ 7,    y+16,    x+27,    y+23); //torso (high)
	bar(x+10,    y+24,    x+24,    y+31); //torso (low)

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
			draw_gorilla(current_x+(width_of_building/2),height_of_building);
		}
		current_x += width_of_building;
	}
	draw_gorilla(last_x+(last_width/2),last_height);
	return num_of_buildings;
}


int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	srand(time(0));
	setbkcolor(BLUE);
	draw_buildings();
	cleardevice();
	draw_buildings();
	getch(); 
	return 0;
}


