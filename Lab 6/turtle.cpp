//This file also starts out empty.
//Implement the Turtle class here.
#include "turtle.h"
#include "draw.h"
#include <cmath>

void Turtle::setColor(Color newColor){
  c = newColor;
}
void Turtle::on(){
  isOn = true;
}
void Turtle::off(){
  isOn = false;
}
void Turtle::turn(double deg){
  dir += deg;
}
void Turtle::move(double dist){
  double x1 = x + dist * cos(M_PI * dir / 180);
  double y1 = y + dist * sin(M_PI * dir / 180);
  if (isOn == true){
    draw::setcolor(c);
    draw::line(x, y, x1, y1);
  }
  x = x1;
  y = y1;
}
Turtle::Turtle(double x0, double y0, double dir0){
  x = x0;
  y = y0;
  dir = dir0;
  isOn = true;
  c = draw::BLACK;
}
