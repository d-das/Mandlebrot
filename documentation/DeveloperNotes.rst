Developer Notes for Mandelbrot
##############################

These are the notes taken while developing the Mandlebrot program for
my final exam in cosc1337 for Prof. Black

Notes Written By Dawson Weehunt


..  literalinclude::    ../src/main.cpp
    :caption:  main.cpp (line 1)
    :lines: 1

Magnitude
*********

The first part of this project was setting up the magnitude function.
The function produces a float, but does not take any parameters. It is called
upon a complex number object, and calculates the margnitude of the complex
number. The way it does this is by multiplying the given complex number by
its conjugate and then taking the square root of that result.

Understanding the code
**********************

The next part of this was to understand what exactly was going on in this thing.
This first part of this was to understand all the values declared in Mandlebrot
init. Then I had to understand that pixel value determines the magnitude of the
point and then determines if it will be colored or not. I Still am not sure what
the bitmap does. The generate function of Mandlebrot then goes through all x & y 
values within the range and plots them in relation to x & y offsets and the scale,
all in relation to the screen size.

I still don't understand everything that Graphics.cpp does, but understanding how
it handles keys and mouse inputs was simple enough. The code should be well 
commented on anything I have edited.

The settings for the mandlebrot image is determined in mandlebrot.init & in Graphics.cpp.
The screen controls for image size is declarred in Graphics.h.
The bitmap memory is set up in Mandlebrot.cpp under initBitmap().

Key Controls
************
After I got the program up and running, I added a few controls so that the user can
explore the awesomeness of Mandlebrot. Step one was having glut respond to arrow keys
and offsetting x & y by values of 1, in relation to direction and scale.

Then I set the '+' & '-' arrows to change that scale by order of 0.1 if the scale is
between 3.0 & 0.1, by order of .01 if the scale is between 0.09 & 0.01, and by order
of 0.001 if the scale is between 0.009 & 0.001. The scale is set to reset if the user
attemps to zoom out past 3.0 or zoom in past 0.001.

Mouse Controls
**************
The last part of the project was to have the image recenter on any point that a user
left clicks on. After I got this working I realized that it would be useful to have 
it set up so that everything recenters if the user right-clicks, so I added that as well.

First I had to impliment Glut's mouse funciton, and the wrapper for it as well. I did
some research on the parameters which this function takes, and then just implemented
it copying the synatx from the keyboard handler. 

Then I had to determine how to have the x and y inputs from the mouse shift the image to
center around those points. The first thing I did was include a c out function so that 
I knew what the coordinates are for any point I clicked on. From this I deduced that 
0,0 was the top left corner, and the bottom right corner was the values of the window 
height and width. Because Mandlebrot considers 0,0 to be the bottom left corner, I knew
that I had to flip the y value. Then to have the center of the window be 0,0, I devided
the window height and width in half, then subtracted that from whatver coordinate the
mouse recieved. I then wrote that value to a varible called mouse_xOff / mouse_yOff,
which was of the mandlebrot class. This way, in Mandlebrot.generate, after the function
determines the image coordinates, it is off set by the mouse values (multiplied by the
pixel height and width, so that it is in the correct scale of our image), before every-
thing is scaled to zoom.

Then, simpley enough, the mouse offsets and zoom off sets are set back to 0 if the user
right clicks.

..  literalinclude::    ../src/main.cpp
    :caption: main.cpp (line 2)
    :lines: 2


