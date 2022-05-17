#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

// Fill in this function:
void draw_rectangle(int top, int left, int height, int width) {
   for (int i = left; i <= (width+left); i++){
    if (i >= 0 && i < SIZE){
      if (top >= 0 && top < SIZE){
        image[top][i] = 0;
      }
    }
    if (i >= 0 && i < SIZE){
      if (top+height >= 0 && top+height < SIZE){
        image[height+top][i] = 0;
      }
    }
   }
   for (int j = top; j <= (height + top); j++){
     if (j >= 0 && j < SIZE){
       if (left >= 0 && left < SIZE){
         image[j][left] = 0;
       }
     }
     if (j >= 0 && j < SIZE){
       if (width+left >= 0 && width+left < SIZE){
         image[j][width+left] = 0;
       }
     }
   }
}

// Fill in this function:
void draw_ellipse(int cy, int cx, int height, int width) {
  double rx = width/2;
  double ry = height/2;
  for (double theta = 0.0; theta < 2*M_PI; theta += 0.0001){
    double x = rx*cos(theta);
    double y = ry*sin(theta);
    x += cx;
    y += cy;
    if (x >= 0 && x <= SIZE){
      if (y >= 0 && y <= SIZE){
        image[(int)y][(int)x] = 0;
      }
    }
  }
}


int main() {
   // initialize the image to all white pixels
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }
   
   // Main program loop here
   int command;
   cout << "To draw a rectangle, enter: 0 top left height width" << endl;
   cout << "To draw an ellipse, enter: 1 cy cx height width" << endl;
   cout << "To save your drawing as \"output.bmp\" and quit, enter: 2" << endl;
   cin >> command;
   while (command != 2){
      if (command == 0){
        int top, left, height, width;
         cin >> top >> left >> height >> width;
         draw_rectangle(top, left, height, width);
      }
      if (command == 1){
        int cy, cx, height, width;
        cin >> cy >> cx >> height >> width;
        draw_ellipse(cy, cx, height, width);
      }
      if (command == 2){
        break;
      }
      cout << "To draw a rectangle, enter: 0 top left height width" << endl;
      cout << "To draw an ellipse, enter: 1 cy cx height width" << endl;
      cout << "To save your drawing as \"output.bmp\" and quit, enter: 2" << endl;
      cin >> command;
   }

   
   
   // Write the resulting image to the .bmp file
   writeGSBMP("output.bmp", image);
   
   return 0;
}
