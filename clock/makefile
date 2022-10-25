clock: clock.o myFunctionsLib.o myGfxShapesLib.o gfx2.o
	gcc -o clock clock.o myFunctionsLib.o gfx2.o myGfxShapesLib.o -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lm

clock.o: clock.c myFunctionsLib.h myGfxShapesLib.h gfx2.h
	gcc -c -g clock.c -I/usr/X11R6/include

myGfxShapesLib.o: myGfxShapesLib.c myGfxShapesLib.h
	gcc -c -g myGfxShapesLib.c -I/usr/X11R6/include

gfx2.o: gfx2.c gfx2.h
	gcc -c gfx2.c -I/usr/X11R6/include

myFunctionsLib.o: myFunctionsLib.c myFunctionsLib.h
	gcc -c -g myFunctionsLib.c -I/usr/X11R6/include

clean:
	rm clock clock.o myFunctionsLib.o myGfxShapesLib.o gfx2.o

