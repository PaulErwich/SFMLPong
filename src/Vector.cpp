//
// Created by MLG Erwich on 02/12/2021.
//

#include "Vector.h"

Vector::Vector(float _x, float _y)
{
  x = _x;
  y = _y;
  magnitude = sqrt((x*x) + (y*y));
}

Vector::~Vector()
{

}

void Vector::setVector(float _x, float _y)
{
  x = _x;
  y = _y;
  magnitude = sqrt((x*x) + (y*y));
}

Vector Vector::getVector()
{
  return Vector(x, y);
}

float Vector::getVectorx()
{
  return x;
}

float Vector::getVectory()
{
  return y;
}

void Vector::normalise()
{
  x = x/magnitude;
  y = y/magnitude;
}

void Vector::multiply(float scale)
{
  x = x * scale;
  y = y * scale;
  magnitude = sqrt((x*x) + (y*y));
}

