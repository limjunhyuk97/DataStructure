#ifndef __POINT_H__
#define __POINT_H__

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct Point {
	int xpos;
	int ypos;
}Point;

void PointInit(Point* point, int x, int y);

int PointComp(Point point1, Point point2);

void PointPrint(Point* point);
#endif