#include "Point.h"

void PointInit(Point* point, int x, int y) {
	point->xpos = x;
	point->ypos = y;
}

int PointComp(Point point1, Point point2) {
	if (point1.xpos < point2.xpos) {
		return TRUE;
	}
	else if (point1.xpos == point2.xpos) {
		if (point1.ypos < point2.ypos)
			return TRUE;
		else
			return FALSE;
	}
	else
		return FALSE;

}

void PointPrint(Point* point) {
	printf("( x : %d, y : %d )\n", point->xpos, point->ypos);
}