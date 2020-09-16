#ifndef __cgorillas_gorillas__
#define __cgorillas_gorillas__ 1

#include <graphics.h>
#include <stdio.h>
#include "gorillas.h"

int draw_gorilla(int h_center_of_building, int top_of_building)
{
	int x = h_center_of_building - (WIDTH_OF_GORILLA/2);
	int y = top_of_building - HEIGHT_OF_GORILLA;

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
	bar(x+11,    y+23,    x+13,    y+23); //pectorals 2
	bar(x+17,    y+18,    x+17,    y+20); //pectorals 3
	bar(x+14,    y+22,    x+15,    y+22); //pectorals 4
	bar(x+16,    y+21,    x+16,    y+21); //pectorals 5
	bar(x+18,    y+21,    x+18,    y+21); //pectorals 6
	bar(x+19,    y+22,    x+20,    y+22); //pectorals 7
	bar(x+21,    y+23,    x+23,    y+23); //pectorals 8

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

#endif
