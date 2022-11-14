//
// Created by MLG Erwich on 02/12/2021.
//
#include <math.h>

#ifndef PONGSFML_VECTOR_H
#define PONGSFML_VECTOR_H

class Vector
{
 public:
  Vector(float _x, float _y);
  ~Vector();
  void setVector(float _x, float _y);
  Vector getVector();
  float getVectorx();
  float getVectory();
  void normalise();
  void multiply(float scale);

 private:
  float x;
  float y;
  float magnitude;
};

#endif // PONGSFML_VECTOR_H
