#ifndef __cgorillas_buildings__
#define __cgorillas_buildings__ 1

#include <graphics.h>
#include "buildings.h"
#include "aux.h"


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
	int h_step = WIDTH_OF_WINDOW + H_SPACE_BETWEEN_WINDOWS;
	int v_step = HEIGHT_OF_WINDOW + V_SPACE_BETWEEN_WINDOWS;
	int color_of_window = YELLOW;
	int padding = ((((width_of_building - MIN_WINDOW_PADDING*2) - WIDTH_OF_WINDOW)%h_step)/2) + MIN_WINDOW_PADDING;
	int minx = left + padding;
	int maxx = ((left)+width_of_building)-(padding);
	int x = minx;
	int i = 0;
	while(x < maxx)
	{
		for(int y = top+padding; y < (getmaxy()-FLOOR_HEIGHT); y += v_step)
		{
			if(myrand(0,1)>0.3)
				color_of_window = YELLOW;
			else
				color_of_window = DARKGRAY;
			setcolor(color_of_window);
			bar(x, y, x+WIDTH_OF_WINDOW, y+HEIGHT_OF_WINDOW);
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

#endif
