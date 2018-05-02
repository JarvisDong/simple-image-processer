#include <my_struct.h>

void InitializeCircle(struct Shape *shape, double radius, double originX, double originY) {
	// circle->radius = radius;
	// circle->originX = originX;
	// circle->originY = originY;
};

void InitializeRectangle(struct Shape *shape, double minX, double maxX, double minY, double maxY) {
	// rectangle->minX = minX;
	// rectangle->maxX = maxX;
	// rectangle->minY = minY;
	// rectangle->maxY = maxY;
};

void InitializeTriangle(struct Shape *shape, double pt1X, double pt2X, double minY, double maxY) {
	// triangle->pt1X = pt1X;
	// triangle->pt2X = pt2X;
	// triangle->minY = minY;
	// triangle->maxY = maxY;
};

double GetCircleArea(struct Shape *shape) {
	// return 3.14159 * circle->radius * circle->radius;
};

double GetRectangleArea(struct Shape *shape) {
	// return (rectangle->maxX - rectangle->minX) * (rectangle->maxY - rectangle->minY);
};

double GetTriangleArea(struct Shape *shape) {
	// return (triangle->pt2X - triangle->pt1X) * (triangle->maxY - triangle->minY)/2;
};

void GetCircleBoundingBox(struct Shape *shape, double *bbox) {
	// bbox[0] = circle->originX - circle->radius;
	// bbox[1] = circle->originX + circle->radius;
	// bbox[2] = circle->originY - circle->radius;
	// bbox[3] = circle->originY + circle->radius;
};

void GetRectangleBoundingBox(struct Shape *shape, double *bbox) {
	// bbox[0] = rectangle->minX;
	// bbox[1] = rectangle->maxX;
	// bbox[2] = rectangle->minY;
	// bbox[3] = rectangle->maxY;
};

void GetTriangleBoundingBox(struct Shape *shape, double *bbox) {
	// bbox[0] = triangle->pt1X;
	// bbox[1] = triangle->pt2X;
	// bbox[2] = triangle->minY;
	// bbox[3] = triangle->maxY;
};