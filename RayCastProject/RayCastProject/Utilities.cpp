#include "Utilities.h"
#include <cmath>

//-------------------------------------------------------------------
// Point ------------------------------------------------------------
//-------------------------------------------------------------------
Point::Point(double x, double y, double z)
  : x(x),
  y(y),
  z(z)
{
}

Point::Point(Vector Vec)
  : x(Vec.x),
  y(Vec.y),
  z(Vec.z)
{
}

Point::~Point()
{
}

bool Point::operator==(Point Other)
{
  return x == Other.x && y == Other.y && z == Other.z;
}

Point Point::operator+(Point Other)
{
  return Point(x + Other.x, y + Other.y, z + Other.z);
}

void Point::operator+=(Point Other)
{
  x += Other.x;
  y += Other.y;
  z += Other.z;
}

Point Point::operator-(Point Other)
{
  return Point(x - Other.x, y - Other.y, z - Other.z);
}

void Point::operator-=(Point Other)
{
  x -= Other.x;
  y -= Other.y;
  z -= Other.z;
}

void Point::Copy(Point Other)
{
  x = Other.x;
  y = Other.y;
  z = Other.z;
}

Point Point::Translate(Vector Shift)
{
  return Point(x + Shift.x, y + Shift.y, z + Shift.z);
}

Vector Point::Difference(Point Other)
{
  return Vector(*this - Other);
}

Vector Point::FromThisToThat(Point That)
{
  return Vector(That - *this);
}

//-------------------------------------------------------------------
// Vector -----------------------------------------------------------
//-------------------------------------------------------------------
Vector::Vector(double x, double y, double z)
  : x(x),
  y(y),
  z(z)
{
}

Vector::Vector(Point Pt)
  : x(Pt.x),
  y(Pt.y),
  z(Pt.z)
{
}

Vector::~Vector()
{
}

bool Vector::operator==(Vector Other)
{
  return x == Other.x && y == Other.y && z == Other.z;
}

Vector Vector::operator+(Vector Other)
{
  return Vector(x + Other.x, y + Other.y, z + Other.z);
}

void Vector::operator+=(Vector Other)
{
  x += Other.x;
  y += Other.y;
  z += Other.z;
}

Vector Vector::operator-(Vector Other)
{
  return Vector(x - Other.x, y - Other.y, z - Other.z);
}

void Vector::operator-=(Vector Other)
{
  x -= Other.x;
  y -= Other.y;
  z -= Other.z;
} 

Vector Vector::operator*(double Scalar)
{
  return Vector(x * Scalar, y * Scalar, z * Scalar);
}

void Vector::operator*=(double Scalar)
{
  x *= Scalar;
  y *= Scalar;
  z *= Scalar;
}

double Vector::Dot(Vector Other)
{
  return x * Other.x + y * Other.y + z * Other.z;
}

double Vector::Dot()
{
  return x * x + y * y + z * z;
}

double Vector::Length()
{
  return std::sqrt(x * x + y * y + z * z);
}

Vector Vector::Normalize()
{
  double len = this->Length();
  return Vector(x / len, y / len, z / len);
}

//-------------------------------------------------------------------
// Ray --------------------------------------------------------------
//-------------------------------------------------------------------
Ray::Ray(Point loc, Vector dir)
  : Location(loc),
  Direction(dir)
{
}

Ray::~Ray()
{
}

void Ray::Move(Point shift)
{
  Location += shift;
}

void Ray::Move(double x, double y, double z)
{
  Location += Point(x, y, z);
}

bool Ray::operator==(Ray Other)
{
  return Location == Other.Location && Direction == Other.Direction;
}

//-------------------------------------------------------------------
// Sphere -----------------------------------------------------------
//-------------------------------------------------------------------
Sphere::Sphere(Point cen, double radius)
  : Center(cen),
  Radius(radius)
{
}

Sphere::~Sphere()
{
}

void Sphere::Move(Point shift)
{
  Center += shift;
}

void Sphere::Move(double x, double y, double z)
{
  Center += Point(x, y, z);
}

bool Sphere::operator==(Sphere Other)
{
  return Center == Other.Center && Radius == Other.Radius;
}