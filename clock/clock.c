/*
Isaiah Keating
clock V1
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gfx2.h"
#include "myGfxShapesLib.h"
#include <math.h>
#include "myFunctionsLib.h"
#include <unistd.h>

/*
gfx_color(255,0,0);// RGB red
gfx_color(0,255,0);// RGB green
gfx_color(255,255,255);// RGB white
gfx_color(0,0,255);//RGB blue
gfx_color(255,255,0);//yellow
gfx_color(248,24,148);//hot pink
gfx_color(255,165,0);//Orange
gfx_color(128,128,128);//Gray
*/

int main(int argc, char *argv[])
{
  int ySize = 200;
  int xSize = 200;

  gfx_open(xSize, ySize, "clock");

  while(1)
   {
      time_t sec;
      sec = time (NULL);
      int numTimes = (sec*6);
      int numTimes2 = ((sec*6)/60);
      int numTimes3 = ((sec*6)/60)/12;

      gfx_clear();

      //********************************************************************
      /*
      for ( int i = 1 ; i <= 200 ; i++ ){
        gfx_color(128,128,128);//Gray
        drawSquare(100,100,i);
      }
      for ( int i = 1 ; i <= 75 ; i++ ){
        gfx_color(0,0,0);//Black
        drawCircle(100,100,i);
      }

      for ( int i = 76 ; i <= 80 ; i++ ){
        gfx_color(0,0,255);//RGB blue
        drawCircle(100,100,i);
      }
*/
      gfx_color(0,0,255);//RGB blue
      drawCircle(100,100,76);

      //*********************************************************************

      gfx_color(255,255,255);// RGB white

      for( int i = 0; i < 60; i++)
        {
          double radius = 75;//tic is 5 because the circle is 50
          double radian = (i * 0.0174532925)* 6;//one tic every 10 rad
          double dataX = radius * cos(radian);
          double dataY = radius * sin(radian);
      
          double radius2 = 70;//tic is 5 because the circle is 50
          double radian2 = (i * 0.0174532925)* 6;//one tic every 10 rad
          double dataX2 = radius2 * cos(radian2);
          double dataY2 = radius2 * sin(radian2);
          gfx_line( dataX2+100, dataY2+100, dataX+100, dataY+100);
         }

      //*********************************************************************

      gfx_color(248,24,148);// RGB hot pink

      for( int i = 0; i < 12; i++)
        {
          double radius = 75;//tic is 5 because the circle is 50
          double radian = (i * 0.0174532925)* 30;//one tic every 10 rad
          double dataX = radius * cos(radian);
          double dataY = radius * sin(radian);
      
          double radius2 = 65;//tic is 5 because the circle is 50
          double radian2 = (i * 0.0174532925)* 30;//one tic every 10 rad
          double dataX2 = radius2 * cos(radian2);
          double dataY2 = radius2 * sin(radian2);
          gfx_line( dataX2+100, dataY2+100, dataX+100, dataY+100);
         }

      //***************************************************************************

      double radius = 70;
      double radian = (numTimes3 * 0.0174532925)-4.1887895;//adjust for day light savings,
                                                   //0.5235987 rad per hour
      double dataX = (radius-20) * cos(radian);
      double dataY = (radius-20) * sin(radian);

      double triX2 = (radius-15) * cos(radian+.2);
      double triY2 = (radius-15) * sin(radian+.2);

      double triX3 = (radius-15) * cos(radian-.2);
      double triY3 = (radius-15) * sin(radian-.2);

      gfx_color(255,165,0);//Orange
      gfx_line( 100, 100, dataX+100, dataY+100);
      drawPolygon(dataX+100, dataY+100, 10, 3, radian);

      //**********************************************************************

      radian = (numTimes2 * 0.0174532925)-1.570796;

      dataX = (radius-10) * cos(radian);
      dataY = (radius-10) * sin(radian);

      triX2 = (radius-15) * cos(radian+.2);
      triY2 = (radius-15) * sin(radian+.2);

      triX3 = (radius-15) * cos(radian-.2);
      triY3 = (radius-15) * sin(radian-.2);

      gfx_color(0,255,0);//RGB blue
      gfx_line( 100, 100, dataX+100, dataY+100);
      drawPolygon(dataX+100, dataY+100, 7.5, 3, radian);

      //************************************************************************

      radian = (numTimes * 0.0174532925)-1.570796;

      dataX = (radius-10) * cos(radian);
      dataY = (radius-10) * sin(radian);

      triX2 = (radius-15) * cos(radian+.2);
      triY2 = (radius-15) * sin(radian+.2);

      triX3 = (radius-15) * cos(radian-.2);
      triY3 = (radius-15) * sin(radian-.2);

      gfx_color(255,255,255);
      gfx_line( 100, 100, dataX+100, dataY+100);
      gfx_color(255,0,0);
      drawPolygon(dataX+100, dataY+100, 5, 3, radian);

      //*************************************************************************

      gfx_flush();
      usleep(100);
   }

   return(0);
}


