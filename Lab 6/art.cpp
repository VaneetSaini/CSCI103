#include "turtle.h"
#include "draw.h"
#include <ctime>
#include <iostream>
using namespace std;

int genRandom(){
  int n = 20 + rand() % 30;
  return n;
}
int main() {
  srand(time(0));
   draw::setpenwidth(3); // line thickness
   draw::setrange(-100, 100); //range

  Turtle turtle1(0, 0, 0); Turtle turtle2(-10, 0, 0);  //4 turtles
  Turtle turtle3(0, -100, 0); Turtle turtle4(-40, 50, 0);

   int x = 1+ rand() % 3;   //randomly assign one of 3 colors
   if (x == 1) turtle1.setColor(draw::RED);
   else if (x == 2) turtle1.setColor(draw::GREEN);
   else if (x == 3) turtle1.setColor(draw::BLUE);
  draw::show(100);
  for (int i = 0; i < 5; i++){   //turtle1 draw
    turtle1.move(100);
    turtle1.turn(144);
  }
  draw::show(100);
  turtle2.setColor(draw::PINK); //turtle2 draw
  int distance = 2 * genRandom();
  turtle2.turn(180);
  for (int i = 0; i < 4; i++){
    turtle2.move(distance);
    turtle2.turn(90);
  }
  draw::show(100);
  if (genRandom() % 2 == 0) turtle3.setColor(draw::YELLOW);
  else turtle3.setColor(draw::BLACK);
  turtle3.turn(60);turtle3.move(100);turtle3.turn(120);
  turtle3.move(100);turtle3.turn(120);turtle3.move(100);
  turtle3.turn(150);
  draw::show(100);
  turtle4.setColor(draw::OLIVE);
  int sides = 5 + rand() % 15;
  int distance1 = genRandom() / 2;
  for (int i = 0; i < sides; i++){
    turtle4.move(distance1);
    turtle4.turn(360 - (360 / sides));
  }
  turtle4.move(distance1);
  draw::show(100);

   return 0;
}
