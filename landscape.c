#ifndef __cgorillas_landscape__
#define __cgorillas_landscape__ 1

#include <graphics.h>
#include <math.h>
#include "landscape.h"
#include "gorillas.h"
#include "buildings.h"
#include "aux.h"

extern int l_gor_x;
extern int l_gor_y;
extern float wind;

int draw_landscape()
{
	int current_x = -1;
	int width_of_building = 0;
	int height_of_building = 0;
	int max_height_of_building=(getmaxy()*MAX_HEIGHT_OF_BUILDING_PCT)/100;
	int num_of_buildings=0;
	int last_x=0,last_width=0,last_height=0;
	while(current_x < getmaxx())
	{
		last_x=current_x-width_of_building;
		last_width=width_of_building;
		last_height=height_of_building;
		num_of_buildings++;
		width_of_building = myrand(MIN_WIDTH_OF_BUILDING, MAX_WIDTH_OF_BUILDING);
		height_of_building = getmaxy()-(max_height_of_building*myrand(MIN_HEIGHT_OF_BUILDING_PCT,100))/100;
		if(current_x+width_of_building+MIN_WIDTH_OF_BUILDING > getmaxx())
		{
			width_of_building += MIN_WIDTH_OF_BUILDING;
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
	wind = myrand(MIN_WIND, MAX_WIND);
	return num_of_buildings;
}

#endif