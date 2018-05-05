#include <my_struct.h>

double GetCircleArea(struct Shape *shape) {
	return 3.14159 * shape->su.c.radius * shape->su.c.radius;
};

double GetRectangleArea(struct Shape *shape) {
	return 	(shape->su.r.maxX - shape->su.r.minX) * (shape->su.r.maxY - shape->su.r.minY);
};

double GetTriangleArea(struct Shape *shape) {
	return (shape->su.t.pt2X - shape->su.t.pt1X) * (shape->su.t.maxY - shape->su.t.minY)/2;
};

void GetCircleBoundingBox(struct Shape *shape, double *bbox) {
	bbox[0] = shape->su.c.originX - shape->su.c.radius;
	bbox[1] = shape->su.c.originX + shape->su.c.radius;
	bbox[2] = shape->su.c.originY - shape->su.c.radius;
	bbox[3] = shape->su.c.originY + shape->su.c.radius;
};

void GetRectangleBoundingBox(struct Shape *shape, double *bbox) {
	bbox[0] = shape->su.r.minX;
	bbox[1] = shape->su.r.maxX;
	bbox[2] = shape->su.r.minY;
	bbox[3] = shape->su.r.maxY;
};

void GetTriangleBoundingBox(struct Shape *shape, double *bbox) {
	bbox[0] = shape->su.t.pt1X;
	bbox[1] = shape->su.t.pt2X;
	bbox[2] = shape->su.t.minY;
	bbox[3] = shape->su.t.maxY;
};

void InitializeCircle(struct Shape *shape, double radius, double originX, double originY) {
	shape->st = CIRCLE;
	shape->su.c.radius = radius;
	shape->su.c.originX = originX;
	shape->su.c.originY = originY;
	shape->ft.GetArea = GetCircleArea;
	shape->ft.GetBoundingBox = GetCircleBoundingBox;
};

void InitializeRectangle(struct Shape *shape, double minX, double maxX, double minY, double maxY) {
	shape->st = RECTANGLE;
	shape->su.r.minX = minX;
	shape->su.r.maxX = maxX;
	shape->su.r.minY = minY;
	shape->su.r.maxY = maxY;
	shape->ft.GetArea = GetRectangleArea;
	shape->ft.GetBoundingBox = GetRectangleBoundingBox;
};

void InitializeTriangle(struct Shape *shape, double pt1X, double pt2X, double minY, double maxY) {
	shape->st = TRIANGLE;
	shape->su.t.pt1X = pt1X;
	shape->su.t.pt2X = pt2X;
	shape->su.t.minY = minY;
	shape->su.t.maxY = maxY;
	shape->ft.GetArea = GetTriangleArea;
	shape->ft.GetBoundingBox = GetTriangleBoundingBox;
};
