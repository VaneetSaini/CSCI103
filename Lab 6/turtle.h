//This file starts out empty!
//Define the Turtle class here.
#include "draw.h"

class Turtle{
  double x;
  double y;
  double dir;
  bool isOn;
  Color c;
  public:
    Turtle(double x0, double y0, double dir0);
    void move(double dist);
    void turn(double deg);
    void setColor(Color c);
    void off();
    void on();
};
