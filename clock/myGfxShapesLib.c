/*
 * myGfxShapesLib.c
 *
 *    A library of functions that draw various shapes using the gfx2 library.
 *
 *    Author: Isaiah Keating
 *    csc250DT2
 *    Last Modified: 04/22/2020   v0.9  version number indicates how many functions
 */
#include <stdio.h>
#include <math.h>
#include "gfx2.h"
#include "myGfxShapesLib.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
const double PI = 3.14159265358979323846264338327950288419716939937510;


/*
 * drawSquare
 *    draws a square centered at given x, y coords, with size
 *    given by the side parameter
 */
void drawSquare(double xCenter, double yCenter, double side)
{
   //calculate x,y coordinates of all corners... ulx means upper left x, etc
   double ulx = xCenter - side/2;
   double uly = yCenter - side/2;
   double llx = xCenter - side/2;
   double lly = yCenter + side/2;
   double urx = xCenter + side/2;
   double ury = yCenter - side/2;
   double lrx = xCenter + side/2;
   double lry = yCenter + side/2;

   gfx_line(ulx,uly,llx,lly);
   gfx_line(llx,lly,lrx,lry);
   gfx_line(lrx,lry,urx,ury);
   gfx_line(urx,ury,ulx,uly);
}


/*
drawCircle
   draws a circle
*/

void drawCircle(double xCenter, double yCenter, double radius)
{
   double x, y, theta, thetaNext, xNext, yNext;
   //double thetaIncrement = 0.1;//could end up drawing multipal lines in a pixel
   double thetaIncrement = 2.0 / ( 2 * PI * radius );//adjusts depending on
   //the radius
   
   for( theta = 0; theta < 2*PI; theta = thetaNext )
      {
         thetaNext = theta + thetaIncrement;
         x = xCenter + radius*cos(theta);
         y = yCenter + radius*sin(theta);
         xNext = xCenter + radius*cos(thetaNext);
         yNext = yCenter + radius*sin(thetaNext);
         gfx_line(x, y, xNext, yNext);
      }
}

/*
   draw polygon
*/

void drawPolygon(double centerX, double centerY, double radius, double nSides, double rotation)
{
   double x, y, theta, thetaNext, xNext, yNext;
   double thetaIncrement = 2*PI/nSides;

   for( theta = rotation; theta < 2*PI + rotation; theta = thetaNext )
      {
         thetaNext =  theta + thetaIncrement;
         x = centerX + radius*cos(theta);
         y = centerY + radius*sin(theta);
         xNext = centerX + radius*cos(thetaNext);
         yNext = centerY + radius*sin(thetaNext);
         gfx_line(x, y, xNext, yNext);
      }
}

/*
   drawRectangle
*/

void drawRectangle(double xCenter, double yCenter, double width,
                   double hight)
{
   //calculate x,y coordinates of all corners... ulx means upper left x, etc
   double ulx = xCenter - width/2;
   double uly = yCenter - hight/2;
   double llx = xCenter - width/2;
   double lly = yCenter + hight/2;
   double urx = xCenter + width/2;
   double ury = yCenter - hight/2;
   double lrx = xCenter + width/2;
   double lry = yCenter + hight/2;

   gfx_line(ulx,uly,llx,lly);
   gfx_line(llx,lly,lrx,lry);
   gfx_line(lrx,lry,urx,ury);
   gfx_line(urx,ury,ulx,uly);
}

/*
   drawBars
*/

void drawBars(double * data, int dataCount, double lowerLeftX,
              double lowerLeftY, double width, double spacing)
     {

        
        double llx = lowerLeftX;
        double lly = lowerLeftY;
        srand((unsigned)time(NULL));
        //loop for each bar we need to draw:
        for( int i = 0; i < dataCount; i++ )
           {
           
              int r;
              int rgb[3];
             // srand((unsigned)time(NULL));  
                for(int b=0;b<3;b++)
               {
                  r=0+(rand() %255);
                  //printf("%i\t",r);
                  rgb[b] = r;
               }
              gfx_color(rgb[0],rgb[1],rgb[2]);
           
           
              gfx_line(llx,lly,llx,lly-data[i]); //draw the left side of rectangle
              gfx_line(llx,lly,llx+width,lly); // draw bottom
              gfx_line(llx+width,lly,llx+width,lly-data[i]); // draw right side
              gfx_line(llx,lly-data[i],llx+width,lly-data[i]); // draw top side
              
              // update the x coord of the lower left corner for the next time through the loop
              llx = llx + width + spacing;
           }
           //draw the rectangle for the correct height and width in the correct position
        gfx_flush();
     }


/*
drawLines
*/

void drawLines(double *xList, double *yList, int numPoints)
{
   int x1, x2, y1, y2;
   int r = 255;
   int g = 0;
   int b = 0;

   for (int i = 0; i < numPoints; i++)
   {
/*
      gfx_color(r,g,b);
      r = r-255/numPoints;
      g = g+255/numPoints;
      b = b+255/numPoints;
*/
      x1 = xList[i];
      x2 = xList[i+1];
      y1 = yList[i];
      y2 = yList[i+1];
      gfx_line( x1, y1, x2, y2);
   }

}


/*
xyGridLine
*/

void xyGridLine (double xLength, double yLength, double xZero, double yZero, double numTicks)
{
   gfx_color(255,255,255);
   double llx = xZero;
   double lrx = xZero + (xLength/numTicks);


   double lly = yZero;
   double uly = yZero - (yLength/numTicks);

   for (int i = 0;i < numTicks;i++)
   {
   gfx_line(llx,lly,lrx,lly);
   gfx_line(lrx,lly,lrx,lly+5);
   gfx_line(lrx,lly,lrx,lly-5);

   lrx=lrx+(xLength/numTicks);
   }

   for (int i = 0;i < numTicks;i++)
   {
   gfx_line(llx,lly,llx,uly);
   gfx_line(llx,uly,llx+5,uly);
   gfx_line(llx,uly,llx-5,uly);

   uly=uly-(yLength/numTicks);
   }
 
}

/*
Recursion
DrawCircleThing
*/

void drawCircleThing(double xCenter, double yCenter, double radius, double rLimit)
{
   if (radius > rLimit )
   {


      // drawCircleThing on the left, half as big
      drawCircleThing(xCenter-radius, yCenter, radius/2, rLimit);
      // drawCircleThing on the right, half as big
      drawCircleThing(xCenter+radius, yCenter, radius/2, rLimit);
      // drawCircleThing on the top, half as big
      drawCircleThing(xCenter, yCenter-radius, radius/2, rLimit);
      // drawCircleThing on the bottom, half as big
      drawCircleThing(xCenter, yCenter+radius, radius/2, rLimit);

      // draw the big circle
      drawCircle(xCenter, yCenter, radius);

      gfx_flush();
      usleep(25000);

   }
   // base case : do nothing
}

/*
fractalDragon
*/

void fractalDragon(GfxPoint a, GfxPoint b, double sizeLimit, int timeDelay)
{
   GfxPoint newPoint;
   // calculate xdif, ydif...
   double xdif = b.x - a.x;
   double ydif = b.y - a.y;

   // base case: draw the line
   double dist = sqrt( xdif*xdif + ydif*ydif );
   if ( dist <= sizeLimit /*distance small enough */ )
   {
      //rand color
      int r;
      int rgb[3];
      srand((unsigned)time(NULL));  
            for(int b=0;b<3;b++)
               {
                  r=0+(rand() %255);
                  rgb[b] = r;
               }

   gfx_color(rgb[0],rgb[1],rgb[2]);

      gfx_line(a.x,a.y,b.x,b.y);
      gfx_flush();   // so every line drawn we see imeadiatly
      usleep(timeDelay);   // delay
   }
   else
   {
      // calculate x & y of the new point
      newPoint.x = a.x + (b.x-a.x)/2 + (b.y-a.y)/2;
      newPoint.y = a.y + (b.y-a.y)/2 - (b.x-a.x)/2;
      // recursively draw the sub-dragons...
      fractalDragon(a, newPoint, sizeLimit, timeDelay);
      fractalDragon(b, newPoint, sizeLimit, timeDelay);
   }
}




/*  {
      printf("***drawLines; function not yet implemented\n");
   }
*/
















