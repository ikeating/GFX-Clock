/*
 * myGfxShapesLib.h
 *
 *    A library of functions that draw various shapes using the gfx2 library.
 *
 *    Author: Isaiah Keating
 *    csc250DT2
 *    Last Modified: 04/22/2020   v1.0
 */

// header files normally contain constants, global variables, #define, as well
// as function headers

//const double PI = 3.14159265358979323846264338327950288419716939937510;

typedef struct GfxPoint
{
   // declare the component variables of the struct here...
   double x;
   double y;
}

GfxPoint;

//mostly function headers (prototypes, signatures) are listed in the header
//file
void drawSquare(double xCenter, double yCenter, double side);

void drawCircle(double centerX, double centerY, double radius);

void drawPolygon(double centerX, double centerY, double radius, double nSides, double rotation);

void drawRectangle(double xCenter, double yCenter, double width, double hight);

void drawBars(double * data, int dataCount, double lowerLeftX,
              double lowerLeftY, double width, double spacing);

void drawLines(double *xList, double *yList, int numPoints);

void xyGridLine (double xLength, double yLength, double xZero, double yZero, double numTicks);

void drawCircleThing(double xCenter, double yCenter, double radius, double rLimit);

void fractalDragon(GfxPoint a, GfxPoint b, double sizeLimit, int timeDelay);


