/* This file should contain your struct definitions for Circle, Triangle, and 
   Rectangle */

typedef struct
{
	double radius;
	double originX;
	double originY;

} Circle; //struct definition for Circle


typedef struct 
{
	double pt1X;
	double pt2X;
	double minY;
	double maxY;

} Triangle; //struct definition for Triangle


typedef struct 
{
	double minX;
	double maxX;
	double minY;
	double maxY;

} Rectangle; //struct definition for Rectangle