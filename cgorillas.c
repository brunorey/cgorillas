#define _USE_MATH_DEFINES

#include "gorillas.h"
#include "landscape.h"
#include "buildings.h"
#include "banana.h"
#include "aux.h"
#include <stdio.h>
#include <graphics.h>
#include <math.h>

//these global variables should not be global
//  and should be put into a nice struct
//  landscape {
//    wind
//    left_gorilla {
//      x_coord
//      y_coord
//    }
//    right_gorilla {
//      x_coord
//      y_coord
//    }
//    buildings {
//      [...]
//    }
//  }

int l_gor_x = 0;
int l_gor_y = 0;
float wind = 0;

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	srand(time(0));
	cleardevice();
	setbkcolor(BLUE);
	draw_landscape();
	sleep(2);
	char angle_str[3];
	char speed_str[3];
	printf("Wind: %f", wind);
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
	throw_banana(l_gor_x-(WIDTH_OF_GORILLA/2), l_gor_y-(HEIGHT_OF_GORILLA+20), speed, angle);
	return 0;
}


